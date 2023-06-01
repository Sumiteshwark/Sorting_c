#include<stdio.h>
int totallength;  //for merge sort.

void input(int *arr, int n){
    printf("Enter %d numbers: ",n);
    for(int i=0;i<n;i++){
        scanf("%d", &arr[i]);
    }
}



void display(int *arr, int n){
    for(int i=0;i<n;i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}



void selectionsort(int *arr, int n){
    int swap=0;
    int comp=0;
    for(int i=0;i<n-1;i++){
        int min=arr[i];
        for(int j=i+1;j<n;j++){
            comp++;
            if(arr[j]<=arr[i]){
                swap++;
                int temp = arr[j];
                arr[j]=arr[i];
                arr[i]=temp;
            }
        }
    }
    printf("Number of comparision in selection sort is %d\n",comp);
    printf("Number of swapping in selection sort is %d\n",swap);
}



void insertionsort(int *arr, int n){
    int swap=0;
    int comp=0;
    for(int i=1;i<n;i++){
        int p=i-1;
        int key=arr[i];
        while(p>=0 && arr[p]>key){
            comp++;
            arr[p+1]=arr[p];
            p--;
        }
        arr[p+1]=key;
        swap++;
    }
    printf("Number of comparision in insertion sort is %d\n",comp+swap-1);
    printf("Number of swapping in insertion sort is %d\n",swap);
}



void bubblesort(int *arr, int n){
    int swap=0;
    int comp=0;
    int t = n;
    while (t!=1){
        for(int i=0;i<t-1;i++){
            comp++;
            if(arr[i]>arr[i+1]){
                swap++;
                int temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
            }
        }
        t--;
    }
    printf("Number of comparision in bubble sort is %d\n",comp);
    printf("Number of swapping in bubble sort is %d\n",swap);
}



void merge(int *arr, int l, int mid, int m){
    int i=l, j=mid+1, k=l;
    int temp[totallength];
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
void mergesort(int *arr, int l, int m){
    if(l<m){
        int mid = (l+m)/2;
        mergesort(arr, l, mid);
        mergesort(arr, mid+1, m);
        merge(arr, l, mid, m);
    }
}



int partition(int *arr, int l, int m){
    int pivot = arr[m];
    int i = l;
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
    for(int i=n-1;i>=0;i--){
        sortarr[newarr[arr[i]]-1]=arr[i];
        newarr[arr[i]]--;
    }
    for(int i=0; i<n;i++){
        arr[i]=sortarr[i];
    }
}



int main(){
    printf("\n Total six types of sorting is tested here.\n (1) For selection press 'S'\n (2) For insertion press 'I'\n (3) For bubble press 'B'\n (4) For merge press 'M'\n (5) For quick press 'Q'\n (6) For count press'C'\n");
    printf("\nEnter any one from 'S', 'I', 'B', 'M', 'Q', 'C': ");
    char ch;
    scanf("%c", &ch);
    int n;
    printf("\nEnter total number of numbers: ");
    scanf("%d",&n);
    totallength = n;
    int arr[n];
    input(arr, n);
    printf("Before sorting: ");
    display(arr, n);
    if(ch=='S' || ch=='s'){
        selectionsort(arr, n);
        printf("sorting is done by selection sort.\n");
    }
    else if(ch=='I' || ch=='i'){
        insertionsort(arr, n);
        printf("sorting is done by insertion sort.\n");
    }
    else if(ch=='B' || ch=='b'){
        bubblesort(arr, n);
        printf("sorting is done by bubble sort.\n");
    }
    else if(ch=='M' || ch=='m'){
        mergesort(arr, 0, n-1);
        printf("sorting is done by merge sort.\n");
    }
    else if(ch=='Q' || ch=='q'){
        quicksort(arr, 0, n-1);
        printf("sorting is done by quick sort.\n");
    }
    else if(ch=='C' || ch=='c'){
        countsort(arr, n);
        printf("sorting is done by count sort.\n");
    }
    else{
        printf("Enter valid character\n");
    }

    printf("After sorting: ");
    display(arr, n);
    return 0;
}