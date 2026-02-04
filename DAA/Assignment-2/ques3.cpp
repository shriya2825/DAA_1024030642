#include <iostream>
#include <algorithm>
using namespace std;

struct Item {
    int p, w;
    double r;   
};

bool compare(Item a, Item b) {
    return a.r > b.r;   // decreasing order
}

int main() {
    int n, W;
    cout << "Enter number of items: ";
    cin >> n;

    cout << "Enter capacity of knapsack: ";
    cin >> W;

    Item a[n];

    cout << "Enter profit:\n";
    for (int i = 0; i<n; i++) {
        cin >> a[i].p;
    }
    cout<<"enter weight:";
    for(int i=0;i<n;i++){
        cin>>a[i].w;
        a[i].r = (double)a[i].p / a[i].w;
    }


    // Sort items by profit/weight ratio
    sort(a, a + n, compare);

    double profit = 0.0;

    for (int i = 0; i < n; i++) {
        if (W >= a[i].w) {
            profit += a[i].p;
            W -= a[i].w;
        } else {
            profit += a[i].r * W;
            break;
        }
    }

    cout << "Maximum profit = " << profit;
    return 0;
}
