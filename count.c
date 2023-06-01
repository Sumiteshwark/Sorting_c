//Sorting by count sort

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

void countsort(int *arr, int n){
    int max = arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]>max){
            max=arr[i];
        }
    }
    int newarr[max+1];
    for(int i=0;i<max+1;i++){
        newarr[i]=0;
    }
    for(int i=0;i<n;i++){
        ++newarr[arr[i]];
    }
    for(int i=1;i<max+1;i++){
        newarr[i]+=newarr[i-1];
    }
    int sortarr[n];
    // for(int i=0;i<n;i++){
    //     sortarr[newarr[arr[i]]-1]=arr[i];
    //     newarr[arr[i]]--;
    // }
    for(int i=n-1;i>=0;i--){
        sortarr[newarr[arr[i]]-1]=arr[i];
        newarr[arr[i]]--;
    }
    for(int i=0; i<n;i++){
        arr[i]=sortarr[i];
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
    countsort(arr, n);
    printf("Sorted array: ");
    display(arr, n);
    return 0;
}