#include <iostream>
#include <string>
using namespace std;

// check if number is power of 2
bool isPowerOfTwo(int n) {
    if (n <= 0)
        return false;

    while (n % 2 == 0) {
        n = n / 2;
    }

    return n == 1;
}
string smallestString(string s, int k) {
    int n = s.length();
    if (isPowerOfTwo(n))
        k = k / 2;
    else
        k = 2 * k;

    string result = "";
    for (int i = 0; i < n; i++) {
        while (!result.empty() && k > 0 && result.back() > s[i]) {
            result.pop_back();  
            k--;
        }
        result.push_back(s[i]);
    }
// remove remaining K
    while (k > 0) {
        result.pop_back();
        k--;
    }
    return result;
}

int main() {
    string s;
    int k;

    cout << "Enter string: ";
    cin >> s;

    cout << "Enter k: ";
    cin >> k;

    cout << "Result: " << smallestString(s, k);
    return 0;
}
