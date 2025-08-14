#include <stdio.h>

void insert(int arr[], int dat, int pos){
    arr[pos]=dat;
}

void main(){
    
    printf("Array Program\n");
    int n,i,dat,pos;
    printf("Enter the number of elements: \n");
    scanf("%d",&n);
    int arr[n];
    printf("Enter %d elements: ", n);
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("The elements in the array are ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\nNow Let's insert an element\n");
    printf("Enter the element to insert: ");
    scanf("%d",&dat);
    printf("Enter the position to insert: ");
    scanf("%d",&pos);
    insert(arr,dat,pos);
    printf("The new elements in the array are ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
}