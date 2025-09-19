#include <stdio.h>

#define MAX_LEN 50
int front = -1;
int rear = -1;
int count = 0;
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
  if (count == MAX_LEN) {
    printf("Overflow! Queue is full.\n");
    return;
  }

  int data;
  printf("\nEnter the value to insert: ");
  if (scanf("%d", &data) != 1) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
    }
    printf("Invalid input.\n");
    return;
  }

  if (count == 0) {
    front = 0;
    rear = 0;
    queue[rear] = data;
  } else {
    rear = (rear + 1) % MAX_LEN;
    queue[rear] = data;
  }
  count++;
  printf("Inserted %d into the queue.\n", data);
}

int dequeue() {
  if (count == 0) {
    printf("Underflow! Queue is empty.\n");
    return -1;
  }

  int item = queue[front];
  if (count == 1) {
    front = -1;
    rear = -1;
    count = 0;
  } else {
    front = (front + 1) % MAX_LEN;
    count--;
  }
  return item;
}

void reset() {
  printf("\nQueue reset!\n");
  front = -1;
  rear = -1;
  count = 0;
}

void print() {
  printf("\n");
  if (count == 0) {
    printf("Queue is empty.\n\n");
    return;
  }

  printf("Queue: ");
  for (int i = 0; i < count; i++) {
    int idx = (front + i) % MAX_LEN;
    printf("%d ", queue[idx]);
  }
  printf("\n\n");
}

int main() {
  printf("===== Circular Queue Operations =====\n");
  menu();
  while (1) {
    int opt;
    if (scanf("%d", &opt) != 1) {
      int c;
      while ((c = getchar()) != '\n' && c != EOF) {
      }
      printf("Please enter a number choice.\n");
      menu();
      continue;
    }

    switch (opt) {
    case 1:
      enqueue();
      menu();
      break;
    case 2: {
      int removed = dequeue();
      if (removed != -1) {
        printf("Removed: %d\n", removed);
      }
      menu();
      break;
    }
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
      printf("Unknown choice\n");
      menu();
      break;
    }
  }
}
