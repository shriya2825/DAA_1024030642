#include<iostream>
using namespace std;

int binarysearch(int arr[],int n,int x){
    int low=0,high=n-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(arr[mid]==x){
            return mid;
        }
        else if(arr[mid]>x){
            high=mid-1;
        }
        else {
            low=mid+1;
        }
    }
    return -1;
}
int main(){
    int arr[]={2,4,5,6,7,8,10};
    int n=sizeof(arr)/sizeof(arr[0]);
    int x;
    cout<<"enter the element to be searched: ";
    cin>>x;
    int result=binarysearch(arr,n,x);
    if(result==-1) cout<<"eleent not found\n";
    else cout<<"element found at "<<result<<" index";

    return 0;

}