#include <stdio.h>

#define MAX_LEN 500
char stack[MAX_LEN];
int top = -1;

void push(char data) {
  if (top >= MAX_LEN) {
    printf("Overflow!\n");
    return;
  }
  top++;
  stack[top] = data;
}

char pop() {
  if (top == -1) {
    return '\n';
  }
  char ret = stack[top];
  top--;
  return ret;
}

void print() {
  int temp = top;
  while (temp > 0) {
    printf("%c", stack[temp]);
    temp--;
  }
}

int main() {
  char c;
  printf("Enter a string to reverse: ");

  while ((c = getchar()) != '\n') {
    push(c);
  }

  printf("Reverse: ");
  while (top >= 0) {
    printf("%c", pop());
  }
  printf("\n");

  return 0;
}
