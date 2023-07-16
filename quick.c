//Sorting by quick sort

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

int partition(int *arr, int l, int m){
    int pivot = arr[m];
    int i = 0;
    for(int j=i; j<=m-1; j++){
        if(arr[j]<pivot){
            int ch=arr[i];
            arr[i]=arr[j];
            arr[j]=ch;
            i++;
        }
    }
    int pv=arr[i];
    arr[i]=arr[m];
    arr[m]=pv;
    return i;
}

void quicksort(int *arr, int l, int m){
    if(l<m){
        int p = partition(arr, l, m);
        quicksort(arr, l, p-1);
        quicksort(arr, p+1, m);
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
    quicksort(arr, 0, n-1);
    printf("Sorted array: ");
    display(arr, n);
    return 0;
}