#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Customer {
    int arrival;
    int departure;
};

// sort customers by departure time
bool compare(Customer a, Customer b) {
    return a.departure < b.departure;
}

int main() {
    int K, N;
    cout << "Enter number of compartments (K): ";
    cin >> K;

    cout << "Enter number of customers (N): ";
    cin >> N;

    vector<int> arrival(N), departure(N), preferred(N);

    cout << "Enter arrival times:\n";
    for (int i = 0; i < N; i++)
        cin >> arrival[i];

    cout << "Enter departure times:\n";
    for (int i = 0; i < N; i++)
        cin >> departure[i];

    cout << "Enter preferred compartment of each customer:\n";
    for (int i = 0; i < N; i++)
        cin >> preferred[i];

    // compartments (1-based indexing)
    vector<Customer> comp[K + 1];

    // group customers by preferred compartment
    for (int i = 0; i < N; i++) {
        comp[preferred[i]].push_back({arrival[i], departure[i]});
    }

    int maxCustomers = 0;

    // apply activity selection for each compartment
    for (int i = 1; i <= K; i++){
        sort(comp[i].begin(), comp[i].end(), compare);

        int lastFinish = -1;
        for (auto c : comp[i]) {
            if (c.arrival >= lastFinish) {
                maxCustomers++;
                lastFinish = c.departure;
            }
        }
    }

    cout << "\nMaximum number of customers that can dine = "
         << maxCustomers;

    return 0;
}
