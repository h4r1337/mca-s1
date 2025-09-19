#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
};

struct Node *head;

void menu() {
  printf("\n1. Insert at start\n");
  printf("2. Insert at end\n");
  printf("3. Insert after a node (middle)\n");
  printf("4. Delete from start\n");
  printf("5. Delete from end\n");
  printf("6. Delete a node (middle)\n");
  printf("7. Print the linked list\n");
  printf("8. Exit\n");
  printf("Choose an option: ");
}

void print(struct Node *head) {
  struct Node *temp = head->next;
  printf("\n");
  printf("List: ");
  if (temp == head) {
    printf("NULL\n");
    return;
  }
  while (temp != head) {
    printf("%d -> ", temp->data);
    temp = temp->next;
  }
  printf("(back to head)\n");
}

void insert_start(struct Node *head) {
  int data;
  printf("Enter value to insert: ");
  if (scanf("%d", &data) != 1)
    return;

  struct Node *new_node = (struct Node *)malloc(sizeof *new_node);
  if (!new_node) {
    perror("malloc");
    return;
  }
  new_node->data = data;

  new_node->next = head->next;
  head->next = new_node;
}

void insert_end(struct Node *head) {
  int data;
  printf("Enter value to insert: ");
  if (scanf("%d", &data) != 1)
    return;

  struct Node *new_node = (struct Node *)malloc(sizeof *new_node);
  if (!new_node) {
    perror("malloc");
    return;
  }
  new_node->data = data;
  new_node->next = head;

  struct Node *temp = head;
  while (temp->next != head) {
    temp = temp->next;
  }
  temp->next = new_node;
}

void insert_middle(struct Node *head) {
  int data, search;
  int found = 0;
  printf("Enter insert position (after value): ");
  if (scanf("%d", &search) != 1)
    return;

  struct Node *temp = head->next;
  while (temp != head) {
    if (temp->data == search) {
      found = 1;
      break;
    }
    temp = temp->next;
  }

  if (!found) {
    printf("\nPosition not found!\n");
    return;
  }

  printf("Enter value to insert: ");
  if (scanf("%d", &data) != 1)
    return;

  struct Node *new_node = (struct Node *)malloc(sizeof *new_node);
  if (!new_node) {
    perror("malloc");
    return;
  }
  new_node->data = data;

  new_node->next = temp->next;
  temp->next = new_node;
}

void delete_start(struct Node *head) {
  if (head->next == head) {
    printf("\nUnderflow!\n");
    return;
  }
  struct Node *to_delete = head->next;
  head->next = to_delete->next;
  free(to_delete);
}

void delete_end(struct Node *head) {
  if (head->next == head) {
    printf("\nUnderflow!\n");
    return;
  }

  if (head->next->next == head) {
    free(head->next);
    head->next = head;
    return;
  }

  struct Node *temp = head->next;
  while (temp->next->next != head) {
    temp = temp->next;
  }
  free(temp->next);
  temp->next = head;
}

void delete_middle(struct Node *head) {
  int search;
  int found = 0;
  printf("Enter item to delete: ");
  if (scanf("%d", &search) != 1)
    return;

  struct Node *prev = head;
  while (prev->next != head) {
    if (prev->next->data == search) {
      found = 1;
      break;
    }
    prev = prev->next;
  }

  if (!found) {
    printf("\nPosition not found!\n");
    return;
  }

  struct Node *to_delete = prev->next;
  printf("Deleting: %d\n", to_delete->data);
  prev->next = to_delete->next;
  free(to_delete);
}

int main() {
  head = (struct Node *)malloc(sizeof *head);
  if (!head) {
    perror("malloc");
    return 1;
  }
  head->next = head;
  head->data = 0;

  printf("===== Circular Linked List =====\n");
  menu();
  while (1) {
    int opt;
    if (scanf("%d", &opt) != 1)
      break;

    switch (opt) {
    case 1:
      insert_start(head);
      menu();
      break;
    case 2:
      insert_end(head);
      menu();
      break;
    case 3:
      insert_middle(head);
      menu();
      break;
    case 4:
      delete_start(head);
      menu();
      break;
    case 5:
      delete_end(head);
      menu();
      break;
    case 6:
      delete_middle(head);
      menu();
      break;
    case 7:
      print(head);
      menu();
      break;
    case 8:
      while (head->next != head) {
        struct Node *tmp = head->next;
        head->next = tmp->next;
        free(tmp);
      }
      free(head);
      return 0;
    default:
      printf("Unknown choice\n");
      menu();
      break;
    }
  }

  return 0;
}
