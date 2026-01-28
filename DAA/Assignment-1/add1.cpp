// remove interval
#include<iostream>
#include<vector>
#include<climits>
using namespace std;

bool overlap(pair<int,int>a,pair<int,int>b){
    return max(a.first,b.first)<=min(a.second,b.second);
}
int main(){
    int n;
    cin>>n;

    vector<pair<int,int>>intv(n);
    for(int i=0;i<n;i++){
        cin>>intv[i].first>>intv[i].second;
    }
    int mincost=INT_MAX;
    for(int i=0;i<n;i++){
        int count=0;
        for(int j=0;j<n;j++){
            if(i!=j && overlap(intv[i],intv[j])){
                count++;
            }
        }
        mincost=min(mincost,count);
    }
    cout<<mincost<<endl;
    return 0;
}
