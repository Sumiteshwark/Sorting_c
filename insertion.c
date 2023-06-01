//sorting by insertion sort.

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

void insertionsort(int *arr, int n){
    for(int i=1;i<n;i++){
        int p=i-1;
        int key=arr[i];
        while(p>=0 && arr[p]>key){
            arr[p+1]=arr[p];
            p--;
        }
        arr[p+1]=key;
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
    insertionsort(arr, n);
    printf("Sorted array: ");
    display(arr, n);
    return 0;
}