#include <iostream>
using namespace std;

void countingSort(int arr[], int n) {
    int maxVal = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > maxVal) maxVal = arr[i];

    int count[maxVal + 1] = {0};

    for (int i = 0; i < n; i++)
        count[arr[i]]++;

    int idx = 0;
    for (int v = 0; v <= maxVal; v++) {
        while (count[v] > 0) {
            arr[idx++] = v;
            count[v]--;
        }
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {4, 2, 2, 8, 3, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Before sorting: ";
    printArray(arr, n);

    countingSort(arr, n);

    cout << "After sorting: ";
    printArray(arr, n);

    return 0;
}
