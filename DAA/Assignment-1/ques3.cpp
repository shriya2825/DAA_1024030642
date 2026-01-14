// quicksort
#include<iostream>
using namespace std;
int partition(int arr[],int low,int high){
    int pivot=arr[low];
    int i=low,j=high;
    while(i<j){
        while(arr[i]<=pivot && i<high)
        i++;
        while(arr[j]>pivot && j>low)
        j--;
        if(i<j) swap(arr[i],arr[j]);
    }
    swap(arr[low],arr[j]); 
    return j;
}
void quicksort(int arr[],int low,int high){
    if(low<high){
        int partidx=partition(arr,low,high);
        quicksort(arr,low,partidx-1);
        quicksort(arr,partidx+1,high);
    }
}

void display(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int arr[]={34,65,11,23,89,45,01};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<"original array\n";
    display(arr,n);
    quicksort(arr,0,n-1);
    cout<<"\nquick sort\n";
    display(arr,n);
    cout<<endl;
    return 0;
}