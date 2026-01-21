#include <iostream>
using namespace std;

void merge(int arr[], int low, int mid, int high) {
    int n1 = mid - low + 1;
    int n2 =high - mid;

    int L[n1], R[n2];
    for (int i = 0; i < n1; i++)
        L[i] = arr[low + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = low;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1)
        arr[k++] = L[i++];

    while (j < n2)
        arr[k++] = R[j++];
}
void iterativeMergeSort(int arr[], int n) {
    for (int curr= 1; curr < n;curr *= 2) {
        for (int left = 0; left < n - 1; left += 2 * curr) {
            int mid = min(left + curr - 1, n - 1);
            int right = min(left + 2 * curr - 1, n - 1);

            merge(arr, left, mid, right);
        }
    }
}
int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout<<"Original array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
        cout<<endl;
    iterativeMergeSort(arr, n);
   
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}
