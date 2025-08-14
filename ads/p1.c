#include <stdio.h>

void main(){
    
    printf("Array Program\n");
    int n,i;
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
}