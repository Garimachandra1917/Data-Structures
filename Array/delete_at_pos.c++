#include<iostream>
using namespace std;
int main(){
    int n,i,pos,a[10];
    cout<<"Enter the size of the array";
    cin>>n;
    cout<<"Enter elements";
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<"Enter the position to be deleted";
    cin>>pos;
    pos=pos-1;            //to delete element in array with indexing staring from [1......n]
    for(i=pos;i<n;i++){
        a[i]=a[i+1];
    }
    n=n-1;
    cout<<"Array after deletion"<<endl;
    for(i=0;i<n;i++){
        cout<<a[i]<<endl;
    }

    return 0;
}