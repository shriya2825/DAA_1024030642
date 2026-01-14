// merge sort
#include<iostream>
using namespace std;
void merge(int arr[],int low,int mid, int high){
    int n1=mid-low+1;
    int n2=high-mid;
    
    int L[n1],R[n2];

    for(int i=0;i<n1;i++){
        L[i]=arr[low+i];
    }
    for(int i=0;i<n2;i++){
        R[i]=arr[mid+1+i];
    }
    
    int i=0;
    int j=0;
    int k=low;

    while(i<n1 && j<n2){
        if(L[i]<=R[j]){
            arr[k]=L[i];
            i++;
        }
        else {
            arr[k]=R[j];
            j++;
        }
        k++;
    }
    //remaining elements of array
    while(i<n1){
        arr[k]=L[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k]=R[j];
        j++;
        k++;
    } 

}
void mergesort(int arr[],int left,int right){
    if(left<right){
        int mid=left+(right-left)/2;
        mergesort(arr,left,mid);
        mergesort(arr,mid+1,right);
        merge(arr,left,mid,right);
    }
}


int main(){
    int arr[]={34,65,11,23,89,45,01};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<"original array\n";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    mergesort(arr,0,n-1);
    cout<<"\nmerge sort\n";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}
