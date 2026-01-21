#include <iostream>
using namespace std;

int max(int a, int b, int c) {
    if (a >= b && a >= c)
        return a;
    else if (b >= a && b >= c)
        return b;
    else
        return c;
}

int maxCrossingSum(int arr[], int l, int m, int h) {
    int sum = 0;
    int left_sum = -100000;

    for (int i = m; i >= l; i--) {
        sum += arr[i];
        if (sum > left_sum)
            left_sum = sum;
    }

    sum = 0;
    int right_sum = -100000;

    for (int i = m + 1; i <= h; i++) {
        sum += arr[i];
        if (sum > right_sum)
            right_sum = sum;
    }
     return left_sum + right_sum;
}

int maxSubArraySum(int arr[], int l, int h) {
    if (l == h)
        return arr[l];
    int m = (l + h) / 2;
    int maxsumL= maxSubArraySum(arr, l, m);
    int maxsumR=maxSubArraySum(arr, m + 1, h);
    int maxMid=maxCrossingSum(arr, l, m, h);

    return max( maxsumL,maxsumR,maxMid);
       
}

int main() {
    int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Maximum subarray sum : "
         << maxSubArraySum(arr, 0, n - 1);

    return 0;
}
