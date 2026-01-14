//binary search
#include<iostream>
using namespace std;
int binarysearch(int arr[],int n,int x){
    int low=0;int high=n-1;
    while(low<=high){
        int mid=(high-low)/2+low;
        if(x==arr[mid]) return mid ;
        else if(x>arr[mid]) low=mid+1;
        else high=mid-1;
    }
    return -1;
}
int main(){
    int arr[]={3,7,9,10,34,56,67};
    int n=sizeof(arr)/sizeof(arr[0]);
    int x;
    cout<<"enter the element which is to be searched:";
    cin>>x;
    int result=binarysearch(arr,n,x);
    if(result==-1) cout<<"element is not found\n";
    else{
        cout<<"element is found at index: "<<result<<endl;
    }
    return 0;
}


