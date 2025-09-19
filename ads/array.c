#include <stdio.h>

#define MAX_LEN 50

int arr[MAX_LEN];
int len = 0;

void menu() {
  printf("\n1. Insert item into array (at index)\n");
  printf("2. Remove an item from array (by index)\n");
  printf("3. Print the array\n");
  printf("4. Reset array\n");
  printf("5. Search for a value\n");
  printf("6. Exit\n");
  printf("Choose an option: ");
}

void insert_at() {
  if (len >= MAX_LEN) {
    printf("Overflow! array is full.\n");
    return;
  }

  int index, value;
  printf("\nEnter the index to insert at (0 to %d): ", len);
  if (scanf("%d", &index) != 1) {
    printf("Invalid input.\n");
    return;
  }
  if (index < 0 || index > len) {
    printf("Invalid index. Must be between 0 and %d.\n", len);
    return;
  }

  printf("Enter the value to insert: ");
  if (scanf("%d", &value) != 1) {
    printf("Invalid input.\n");
    return;
  }

  for (int i = len - 1; i >= index; --i) {
    arr[i + 1] = arr[i];
  }
  arr[index] = value;
  len++;
  printf("Inserted %d at index %d.\n", value, index);
}

void remove_at() {
  if (len == 0) {
    printf("Underflow! array is empty.\n");
    return;
  }

  int index;
  printf("\nEnter the index to remove (0 to %d): ", len - 1);
  if (scanf("%d", &index) != 1) {
    printf("Invalid input.\n");
    return;
  }
  if (index < 0 || index >= len) {
    printf("Invalid index. Must be between 0 and %d.\n", len - 1);
    return;
  }

  int removed = arr[index];
  for (int i = index; i < len - 1; ++i) {
    arr[i] = arr[i + 1];
  }
  len--;
  printf("Removed %d from index %d.\n", removed, index);
}

void reset() {
  len = 0;
  printf("\nArray reset!\n");
}

void print_array() {
  printf("\n");
  if (len == 0) {
    printf("Array is empty.\n\n");
    return;
  }
  printf("Array (size %d): ", len);
  for (int i = 0; i < len; ++i) {
    printf("%d ", arr[i]);
  }
  printf("\n\n");
}

void search_value() {
  if (len == 0) {
    printf("Array is empty. Nothing to search.\n");
    return;
  }

  int value;
  printf("\nEnter value to search: ");
  if (scanf("%d", &value) != 1) {
    printf("Invalid input.\n");
    return;
  }

  int found = 0;
  printf("Value %d found at indices: ", value);
  for (int i = 0; i < len; i++) {
    if (arr[i] == value) {
      printf("%d ", i);
      found = 1;
    }
  }
  if (!found) {
    printf("not found.");
  }
  printf("\n");
}

int main() {
  printf("===== Array Operations =====\n");
  menu();
  while (1) {
    int opt;
    if (scanf("%d", &opt) != 1) {
      int c;
      while ((c = getchar()) != '\n' && c != EOF) {
      }
      printf("Invalid choice. Try again.\n");
      menu();
      continue;
    }
    switch (opt) {
    case 1:
      insert_at();
      menu();
      break;
    case 2:
      remove_at();
      menu();
      break;
    case 3:
      print_array();
      menu();
      break;
    case 4:
      reset();
      menu();
      break;
    case 5:
      search_value();
      menu();
      break;
    case 6:
      return 0;
    default:
      printf("Unknown choice\n");
      menu();
      break;
    }
  }
}

