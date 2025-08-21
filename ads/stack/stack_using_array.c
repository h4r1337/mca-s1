#include <stdio.h>

#define MAX_LEN 50
int top = -1;
int stack[MAX_LEN];

void menu() {
  printf("\n1. Push item to stack\n");
  printf("2. Pop an item from the stack\n");
  printf("3. Print the stack\n");
  printf("4. Exit\n");
  printf("Choose an option: ");
}

void print() {
  printf("\n");
  printf("Stack: ");
  for (int i = 0; i <= top; i++) {
    printf("%d ", stack[i]);
  }
  printf("\n");
  printf("\n");
}

void push() {
  if (top + 1 >= MAX_LEN) {
    printf("Stack Overflow!\n");
    return;
  }
  int data;
  printf("\nEnter the value to push: ");
  scanf("%d", &data);

  top++;
  stack[top] = data;
}

int pop() {
  if (top < 0) {
    printf("Stack Underflow!\n");
    return NULL;
  }
  int item = stack[top];
  top--;
  return item;
}

int main(int argc, char *argv[]) {
  printf("===== Stack Operations =====\n");
  menu();
  while (1) {
    int opt;
    scanf("%d", &opt);
    switch (opt) {
    case 1:
      push();
      menu();
      break;
    case 2:
      pop();
      menu();
      break;
    case 3:
      print();
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
