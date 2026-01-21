#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        long long mn, mx;
        cin >> mn;        
        mx = mn;

        for (int i = 1; i < N; i++) {
            long long x;
            cin >> x;

            if (x < mn)
                mn = x;
            if (x > mx)
                mx = x;
        }

        cout << mn + mx << endl;
    }

    return 0;
}
