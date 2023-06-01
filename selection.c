//sorting by selection sort.

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

void selectionsort(int *arr, int n){
    int compcount=0;
    int swapcount=0;
    for (int i=0;i<n-1;i++){
        for (int j=i+1;j<n;j++){
            compcount++;
            if(arr[i]>arr[j]){
                swapcount++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    printf("Total number of comparison is %d.\n",compcount);
    printf("Total number of swapping is %d.\n",swapcount);
}

int main(){
    int n;
    printf("Enter total number of numbers: ");
    scanf("%d", &n);
    int arr[n];
    input(arr, n);
    printf("Given array: ");
    display(arr, n);
    selectionsort(arr, n);
    printf("Sorted array: ");
    display(arr, n);
    return 0;
}