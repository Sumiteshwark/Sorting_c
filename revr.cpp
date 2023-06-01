#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int>arr;
    map<int,int> m;
    for(int i=0;i<n;i++){
        m[arr[i]]++;
    }
    for(auto it:m){
        if(it.second==1){
            cout<<it.first<<endl;
            break;
        }
    }
    return 0;
}