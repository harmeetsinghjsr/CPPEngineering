#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void buildMaxHeap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
}

void heapSort(int arr[], int n) {
    buildMaxHeap(arr, n);
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {
    int no, n1, n2;
    cin >> no;
    int arr[no];
    for (int i = 0; i < no; i++)
        cin >> arr[i];
    cin >> n1;
    for (int i = no; i < no + n1; i++)
        cin >> arr[i];
    cin >> n2;
    for (int i = no + n1; i < no + n1 + n2; i++)
        cin >> arr[i];

    int totalLights = no + n1 + n2;
    heapSort(arr, totalLights);

    for (int i = 0; i < totalLights; i++)
        cout << arr[i] << " ";

    return 0;
}
