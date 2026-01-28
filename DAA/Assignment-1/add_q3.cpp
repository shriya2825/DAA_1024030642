#include <iostream>
using namespace std;

long long canfit(long long x, long long w, long long h, long long n) {
    long long maxw = x / w;
    long long maxh = x / h;
    return maxw * maxh >= n;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        long long width, height, n;
        cin >> width >> height >> n;

        long long low = 1;
        long long high = max(width, height) * n;
        long long ans = high;

        while (low <= high) {
            long long mid = (low + high) / 2;

            if (canfit(mid, width, height, n)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        cout << ans << endl;
    }

    return 0;
}