/* Q-WAP to input an array of 10 integers/character from user..
 (a)Display all the elements in reverse order of input.
 (b)Remove last element and display all the elements.*/


#include<stdio.h>
#include<stdlib.h>

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

void reverse(int *arr, int n){
    for(int i=0; i<n/2; i++){
        int temp=arr[i];
        arr[i]=arr[n-1-i];
        arr[n-1-i]=temp;
    }
}

void displayrem(int *arr, int n){
    printf("Remaning array elements: ");
    for(int i=0;i<n-1;i++){
        printf("%d ",arr[i]);
    }
}

int main(){
    int n;
    printf("Enter length of array: ");
    scanf("%d", &n);
    int *arr;
    arr = (int*) malloc(n * sizeof(int));
    input(arr, n);
    printf("Given array: ");
    display(arr, n);
    printf("Reversed array: ");
    reverse(arr, n);
    display(arr, n);
    displayrem(arr, n);
    return 0;
}