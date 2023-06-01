#include<bits/stdc++.h>
#define int long long int
#define pb push_back
#define pob pop_back
#define endl '\n'
using namespace std;
const int mod = 1e9+7;
int length=0;

void display(int *arr, int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

// void merge(int *arr, int l,int mid,int m){
//     int i=l,j=mid+1,k=l;
//     int newarr[length];
//     while(i<=mid && j<=m){
//         if(arr[i]<=arr[j]){
//             newarr[k]=arr[i];
//             i++;
//             k++;
//         }
//         else{
//             newarr[k]=arr[j];
//             j++;
//             k++;
//         }
//     }
//     while(i<=mid){
//         newarr[k]=arr[i];
//         i++;
//         k++;
//     }
//     while(j<=m){
//         newarr[k]=arr[j];
//         j++;
//         k++;
//     }
//     for(int z=l;z<=m;z++){
//         arr[z]=newarr[z];
//     }
// }

// void mergesort(int *arr, int l, int m){
//     if(l<m){
//         int mid=(l+m)/2;
//         mergesort(arr,l,mid);
//         mergesort(arr,mid+1,m);
//         merge(arr,l,mid,m);
//     }
// }



void countsort(int *arr,int n){
    int max1=0;
    for(int i=0;i<n;i++){
        if(max1<arr[i]){
            max1=arr[i];
        }
    }
    int newarr[max1+1];
    for(int i=0;i<=max1;i++){
        newarr[i]=0;
    }
    for(int i=0;i<n;i++){
        newarr[arr[i]]++;
    }
    for(int i=1;i<=max1;i++){
        newarr[i]+=newarr[i-1];
    }
    int sortarr[n];
    for(int i=0;i<n;i++){
        sortarr[newarr[arr[i]]-1]=arr[i];
        newarr[arr[i]]--;
    }
    for(int i=0;i<n;i++){
        arr[i]=sortarr[i];
    }
}

int32_t main(){
    /*ios_base::sync_with_stdio(false);
    cin.tie(NULL);*/

    /*********************************sk********************************/

    int arr[]={7,6,8,4,2,9,1};
    int n=7;
    length=n;

    display(arr,n);

    // //Selection sort
    // for(int i=0;i<n;i++){
    //     int min=arr[i];
    //     for(int j=i;j<n;j++){
    //         if(arr[j]<min){
    //             min=arr[j];
    //             arr[j]=arr[i];
    //             arr[i]=min;
    //         }
    //     }
    // }


    //Insertion sort
    // for(int j=1;j<n;j++){
    //     int curr=arr[j];
    //     int i=j;
    //     while(curr<arr[i-1] && i>0){
    //         arr[i]=arr[i-1];
    //         i--;
    //     }
    //     arr[i]=curr;
    // }


    //Bubble sort
    // int curr=n;
    // while(curr--){
    //     for(int i=1;i<=curr;i++){
    //         if(arr[i]<arr[i-1]){
    //             int temp=arr[i-1];
    //             arr[i-1]=arr[i];
    //             arr[i]=temp;
    //         }
    //     }
    // }

    // mergesort(arr, 0, n-1);

    countsort(arr,n);
    display(arr,n);
    return 0;
}