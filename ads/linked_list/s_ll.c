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
  printf("3. Insert at middle\n");
  printf("4. Delete from start\n");
  printf("5. Delete from end\n");
  printf("6. Delete from middle\n");
  printf("7. Print the linked list\n");
  printf("8. Exit\n");
  printf("Choose an option: ");
}

void print(struct Node *head) {
  struct Node *temp = head->next;
  printf("\n");
  printf("List: ");
  while (temp) {
    printf("%d -> ", temp->data);
    temp = temp->next;
  }
  printf("NULL");
  printf("\n");
}

void insert_start(struct Node *head) {
  int data;
  printf("Enter value to insert: ");
  scanf("%d", &data);

  struct Node *new_node;
  new_node = (struct Node *)malloc(sizeof *new_node);
  new_node->data = data;
  new_node->next = head->next;
  head->next = new_node;
}

void insert_end(struct Node *head) {
  int data;
  printf("Enter value to insert: ");
  scanf("%d", &data);

  struct Node *new_node;
  new_node = (struct Node *)malloc(sizeof *new_node);
  new_node->data = data;
  new_node->next = NULL;

  struct Node *temp = head;
  while (temp->next) {
    temp = temp->next;
  }

  temp->next = new_node;
}

void insert_middle(struct Node *head) {
  int data, search, found = 0;
  printf("Enter insert position (after): ");
  scanf("%d", &search);

  struct Node *new_node, *temp = head;
  while (temp) {
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
  scanf("%d", &data);

  new_node = (struct Node *)malloc(sizeof *new_node);
  new_node->data = data;
  new_node->next = temp->next;
  temp->next = new_node;
}

void delete_start(struct Node *head) {
  struct Node *temp = head->next;
  if (temp) {
    head->next = temp->next;
    free(temp);
    return;
  }

  printf("\nUnderflow!\n");
}

void delete_end(struct Node *head) {
  struct Node *temp = head;

  if (temp->next) {
    while (temp->next->next) {
      temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;
    return;
  }

  printf("\nUnderflow!\n");
  return;
}

void delete_middle(struct Node *head) {
  int search, found = 0;
  printf("Enter item to delete: ");
  scanf("%d", &search);

  struct Node *to_delete, *temp = head;

  while (temp->next) {
    if (temp->next->data == search) {
      found = 1;
      break;
    }
    temp = temp->next;
  }

  if (!found) {
    printf("\nPosition not found!\n");
    return;
  }

  to_delete = temp->next;
  printf("%d", to_delete->data);
  temp->next = to_delete->next;
  free(to_delete);
}

int main() {
  head = (struct Node *)malloc(sizeof *head);
  head->next = NULL;

  printf("===== Linked List =====\n");
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
      print(head);
      menu();
      break;
    case 8:
      return 0;
    default:
      printf("Unknown choice");
      menu();
      break;
    }
  }
  return 0;
}
