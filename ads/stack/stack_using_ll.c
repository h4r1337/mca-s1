#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
} *head;

void menu() {
  printf("\n1. Insert\n");
  printf("2. Delete\n");
  printf("3. Print\n");
  printf("4. Exit\n");
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

void push(struct Node *head) {
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

void pop(struct Node *head) {
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

int main() {
  head = (struct Node *)malloc(sizeof *head);
  head->next = NULL;

  printf("===== Stack =====\n");
  menu();
  while (1) {
    int opt;
    scanf("%d", &opt);

    switch (opt) {
    case 1:
      push(head);
      menu();
      break;
    case 2:
      pop(head);
      menu();
      break;
    case 3:
      print(head);
      menu();
      break;
    case 4:
      return 0;
    default:
      printf("Unknown choice");
      menu();
      break;
    }
  }

  return 0;
}
