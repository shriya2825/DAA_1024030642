#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int>activity_prob(int s[],int f[],int n){
    vector<int>A;
    A.push_back(0);
    int i=0;
    for (int m=1;m<n;m++){
        if(s[m]>=f[i]){
            A.push_back(m);
             i=m;
        }
       
    }
    return A;
}
int main(){
    int n;
    cout<<"Enter no of activities: ";
    cin>>n;
    int s[n],f[n];
    cout<<"enter starting time of activities: ";
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    cout<<"enter finishing time of activities: ";
    for(int i=0;i<n;i++){
        cin>>f[i];
    }

    vector<pair<int,int>>activities;
    for(int i=0;i<n;i++){
        activities.push_back({f[i],s[i]});
    }
    sort(activities.begin(),activities.end());

    vector<int>result=activity_prob(s,f,n);

    cout<<"selected activities\n";
    for(int i:result){
        cout<<"A"<<i+1<<" ";
    }
    return 0;
}