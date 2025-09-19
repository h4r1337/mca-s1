#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *prev;
  struct Node *next;
};

struct Node *head;

void menu() {
  printf("\n1. Insert at start\n");
  printf("2. Insert at end\n");
  printf("3. Insert after a value\n");
  printf("4. Delete from start\n");
  printf("5. Delete from end\n");
  printf("6. Delete a value\n");
  printf("7. Print the linked list (forward)\n");
  printf("8. Print the linked list (backward)\n");
  printf("9. Exit\n");
  printf("Choose an option: ");
}

void print_forward(struct Node *head) {
  struct Node *temp = head->next;
  printf("\nList (forward): ");
  while (temp) {
    printf("%d <-> ", temp->data);
    temp = temp->next;
  }
  printf("NULL\n");
}

void print_backward(struct Node *head) {
  struct Node *temp = head;
  while (temp->next) {
    temp = temp->next; // go to last node
  }

  printf("\nList (backward): ");
  while (temp != head) {
    printf("%d <-> ", temp->data);
    temp = temp->prev;
  }
  printf("NULL\n");
}

void insert_start(struct Node *head) {
  int data;
  printf("Enter value to insert: ");
  scanf("%d", &data);

  struct Node *new_node = (struct Node *)malloc(sizeof *new_node);
  new_node->data = data;
  new_node->prev = head;
  new_node->next = head->next;

  if (head->next) {
    head->next->prev = new_node;
  }
  head->next = new_node;
}

void insert_end(struct Node *head) {
  int data;
  printf("Enter value to insert: ");
  scanf("%d", &data);

  struct Node *new_node = (struct Node *)malloc(sizeof *new_node);
  new_node->data = data;
  new_node->next = NULL;

  struct Node *temp = head;
  while (temp->next) {
    temp = temp->next;
  }

  temp->next = new_node;
  new_node->prev = temp;
}

void insert_middle(struct Node *head) {
  int data, search, found = 0;
  printf("Enter value after which to insert: ");
  scanf("%d", &search);

  struct Node *temp = head->next;
  while (temp) {
    if (temp->data == search) {
      found = 1;
      break;
    }
    temp = temp->next;
  }

  if (!found) {
    printf("\nValue not found!\n");
    return;
  }

  printf("Enter value to insert: ");
  scanf("%d", &data);

  struct Node *new_node = (struct Node *)malloc(sizeof *new_node);
  new_node->data = data;
  new_node->next = temp->next;
  new_node->prev = temp;

  if (temp->next) {
    temp->next->prev = new_node;
  }
  temp->next = new_node;
}

void delete_start(struct Node *head) {
  struct Node *temp = head->next;
  if (temp) {
    head->next = temp->next;
    if (temp->next) {
      temp->next->prev = head;
    }
    free(temp);
    return;
  }
  printf("\nUnderflow!\n");
}

void delete_end(struct Node *head) {
  struct Node *temp = head;
  if (temp->next == NULL) {
    printf("\nUnderflow!\n");
    return;
  }

  while (temp->next) {
    temp = temp->next;
  }

  temp->prev->next = NULL;
  free(temp);
}

void delete_middle(struct Node *head) {
  int search, found = 0;
  printf("Enter value to delete: ");
  scanf("%d", &search);

  struct Node *temp = head->next;
  while (temp) {
    if (temp->data == search) {
      found = 1;
      break;
    }
    temp = temp->next;
  }

  if (!found) {
    printf("\nValue not found!\n");
    return;
  }

  temp->prev->next = temp->next;
  if (temp->next) {
    temp->next->prev = temp->prev;
  }

  free(temp);
}

int main() {
  head = (struct Node *)malloc(sizeof *head);
  head->next = NULL;
  head->prev = NULL;

  printf("===== Doubly Linked List =====\n");
  menu();

  while (1) {
    int opt;
    scanf("%d", &opt);

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
      print_forward(head);
      menu();
      break;
    case 8:
      print_backward(head);
      menu();
      break;
    case 9:
      return 0;
    default:
      printf("Unknown choice!\n");
      menu();
      break;
    }
  }
  return 0;
}
