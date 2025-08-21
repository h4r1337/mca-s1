#include <stdio.h>

#define MAX_LEN 50
int front = -1;
int rear = -1;
int queue[MAX_LEN];

void menu() {
  printf("\n1. Insert item to queue\n");
  printf("2. Remove an item from the queue\n");
  printf("3. Print the queue\n");
  printf("4. Reset queue\n");
  printf("5. Exit\n");
  printf("Choose an option: ");
}

void enqueue() {
  if (rear + 1 >= MAX_LEN) {
    printf("Overflow!\n");
    return;
  }

  // If first element
  if (front == -1) {
    front++;
  }

  int data;
  printf("\nEnter the value to insert: ");
  scanf("%d", &data);

  rear++;
  queue[rear] = data;
}

int dequeue() {
  if (front < 0 || front >= MAX_LEN || front > rear) {
    printf("Underflow!\n");
    return NULL;
  }
  int item = queue[front];
  front++;
  return item;
}

void reset() {
  printf("\nQueue reset!\n");
  front = -1;
  rear = -1;
}

void print() {
  printf("\n");
  printf("Queue: ");
  for (int i = front; i <= rear; i++) {
    printf("%d ", queue[i]);
  }
  printf("\n");
  printf("\n");
}

int main() {
  printf("===== Queue Operations =====\n");
  menu();
  while (1) {
    int opt;
    scanf("%d", &opt);
    switch (opt) {
    case 1:
      enqueue();
      menu();
      break;
    case 2:
      dequeue();
      menu();
      break;
    case 3:
      print();
      menu();
      break;
    case 4:
      reset();
      menu();
      break;
    case 5:
      return 0;
    default:
      printf("Unknown choice");
      menu();
      break;
    }
  }
}
