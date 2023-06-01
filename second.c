/*WAP to input an array of 10 integers/characters
(a)Search for an item using linear search and print the message found or not found.
--if found print the index.
--Print the total number of comparision done.
(b)Binary Search */

#include<stdio.h>
int count = 0; //for binary seach comparision

void input(int *arr, int n){
    printf("Enter %d numbers in sorted order: ",n);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
}

void display(int *arr, int n){
    printf("Given array: ");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void findelementbylinear(int *arr, int n, int find){
    for(int i=0;i<n;i++){
        if(arr[i]==find){
            int index = i;
            printf("Total number of comparision in linear search is %d \n", i+1);
            printf("%d is found at index %d by linear search.\n",find,index);
            break;
        }
        else if(i==n-1){
            printf("%d is not found\n",find);
        }
    }
}


int findelementbybinary(int *arr, int l,int m, int find){
    if(m>=l){
        count++;
        int mid = l+(m-l)/2;
        if(find==arr[mid]){
            printf("Total number of comparision in binary search is %d\n",count);
            return mid;
        }
        else if(find<arr[mid]){
            m = mid-1;
            return findelementbybinary(arr,l,m,find);
        }
        else if(find>arr[mid]){
            l = mid+1;
            return findelementbybinary(arr,l,m,find);
        }
    }
    else{
        printf("Total number of comparision in binary search is %d\n",count);
        return -1;
    }
}

int main(){
    int n;
    printf("Enter length of array: ");
    scanf("%d", &n);
    int arr[n];
    input(arr, n);
    display(arr, n);
    printf("Enter the number which we have to find: ");
    int find;
    scanf("%d", &find);
    findelementbylinear(arr, n, find);
    int index = findelementbybinary(arr,0,n-1,find);
    printf("%d is found at index %d by binary search", find, index);
    return 0;
}