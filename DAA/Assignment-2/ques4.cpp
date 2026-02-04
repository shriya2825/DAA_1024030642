#include <iostream>
#include <algorithm>
using namespace std;

struct Job {
    int id;
    int deadline;
    int profit;
};

bool compare(Job a, Job b) {
    return a.profit > b.profit;
}

int main() {
    cout<<"Enter no of Jobs: ";
    int n;
    cin >> n;

    Job jobs[n];
    cout<<"Enter id, deadline and profit: ";
    for(int i = 0; i < n; i++) {
        cin >> jobs[i].id >> jobs[i].deadline >> jobs[i].profit;
    }

    sort(jobs, jobs + n, compare);

    int slot[n];
    for(int i = 0; i < n; i++)
        slot[i] = -1;

    int totalProfit = 0;

    for(int i = 0; i < n; i++) {
        for(int j = jobs[i].deadline - 1; j >= 0; j--) {
            if(slot[j] == -1) {
                slot[j] = jobs[i].id;
                totalProfit += jobs[i].profit;
                break;
            }
        }
    }
    cout<<"Selected slots: ";
    for(int i = 0; i < n; i++) {
        if(slot[i] != -1)
            cout << "J" << slot[i] << " ";
    }
    cout<<"\nTotal Profit: ";
    cout << totalProfit;
}
