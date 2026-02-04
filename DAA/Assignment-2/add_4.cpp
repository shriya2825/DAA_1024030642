#include<iostream>
using namespace std;
int cancompleteloop(int gas[],int cost[],int n ){
    int totalfuel=0,totalcost=0;
    int fuel=0;int start=0;
    for(int i=0;i<n;i++){
        totalfuel+=gas[i];
        totalcost+=cost[i];

        fuel+=gas[i]-cost[i];

        if(fuel<0){
        start=i+1;
        fuel=0;
       }
    }
    if(totalfuel<totalcost){
        return -1;
    }
    return start;
}
int main(){
    int n;
    cout<<"Enter no of gas stations: ";
    cin>>n;
    int gas[n],cost[n];
    cout<<"Enter gas station fuel: ";
    for(int i=0;i<n;i++){
        cin>>gas[i];
    }
    cout<<"Enter travelling fuel: ";
    for(int i=0;i<n;i++){
        cin>>cost[i];
    }
    int index=cancompleteloop(gas,cost,n);
    cout<<index;
    return 0;
}