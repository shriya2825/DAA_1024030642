#include<iostream>
#include<algorithm>
using namespace std;
int minplatformsreq(int arr[],int dep[],int n){
    sort(arr,arr+n);
    sort(dep,dep+n);
    // using two pointers
    int i=1; // for arrival
    int j=0; // departure
    int result=1, platform_need=1;
    while(i<n && j<n){
        if(arr[i]<=dep[j]){
            platform_need++;
            i++;
        }
        else{
            platform_need--;
            j++;
        }
        result=max(platform_need,result);
    }
    return result;

}
int main(){
    int n;
    cout<<"enter no of trains: ";
    cin>>n;

    int arr[n], dep[n];
    
    cout<<"enter arrival time of trains: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"enter departure time of trains: ";
    for(int i=0;i<n;i++){
        cin>>dep[i];
    }
    
    cout<<"min platforms required: "<<minplatformsreq(arr,dep,n);
    return 0;
}