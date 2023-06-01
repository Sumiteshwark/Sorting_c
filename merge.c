//Sorting by merge sort.

#include<stdio.h>
int lengthofarr; //for taking temp array size in merge function.

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

void merge(int *arr, int l, int mid, int m){
    int i=l, j=mid+1, k=l;
    int temp[lengthofarr];
    while (i<=mid && j<=m){
        if(arr[i]<=arr[j]){
            temp[k]=arr[i];
            k++;
            i++;
        }
        else{
            temp[k]=arr[j];
            j++;
            k++;
        }
    }
    while (i<=mid){
        temp[k]=arr[i];
        i++;
        k++;
    }
    while(j<=m){
        temp[k]=arr[j];
        j++;
        k++;
    }
    for(int z=l;z<=m;z++){
        arr[z]=temp[z];
    }
}

void mergesort(int *arr,int l, int m){
    if(l<m){
        int mid = (l+m)/2;
        mergesort(arr, l, mid);
        mergesort(arr, mid+1, m);
        merge(arr, l, mid, m);
    }
}

int main(){
    int n;
    printf("Enter total number of numbers: ");
    scanf("%d", &n);
    lengthofarr = n;
    int arr[n];
    input(arr, n);
    printf("Given array: ");
    display(arr, n);
    mergesort(arr, 0, n-1);
    printf("Sorted array: ");
    display(arr, n);
    return 0;
}