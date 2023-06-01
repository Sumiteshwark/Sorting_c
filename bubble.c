//sorting by bubble sort.

#include<stdio.h>

void input(int *arr, int n){
    printf("Enter %d numbers: ",n);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
}

void display(int *arr, int n){
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void bubblesort(int *arr, int n){
    int t=n;
    while ((t!=1)){
        for (int i=0;i<t-1;i++){
            if (arr[i]>arr[i+1]){
                int temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1]=temp;
            }
        }
        t--;
    }
}

int main(){
    int n;
    printf("Enter total number of numbers: ");
    scanf("%d", &n);
    int arr[n];
    input(arr, n);
    printf("Given array: ");
    display(arr, n);
    bubblesort(arr, n);
    printf("Sorted array: ");
    display(arr, n);
    return 0;
}