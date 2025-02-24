#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& arr, int start, int pivot, int end) {
    vector<int> temp(end - start + 1); 
    int n1 = pivot - start + 1; 
    int n2 = end - pivot; 

    // Copy data into temp arrays
    for (int i = 0; i < n1; ++i) 
        temp[i] = arr[start + i];
    
    for (int i = 0; i < n2; ++i) 
        temp[n1 + i] = arr[pivot + 1 + i];

    int i = 0, j = n1, k = start;

    // Merge the two halves back into arr
    while (i < n1 && j < n1 + n2) {
        if (temp[i] <= temp[j]) {
            arr[k] = temp[i];
            i++;
        } else {
            arr[k] = temp[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements from the left half
    while (i < n1) {
        arr[k] = temp[i];
        i++;
        k++;
    }

    // Copy remaining elements from the right half
    while (j < n1 + n2) {
        arr[k] = temp[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& arr, int start, int end) {
    if (start < end) {
        int mid = (start + end) / 2;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }
}

int main() {
    vector<int> arr = {12, 13, 14, 10, 15, 18};
    int n = arr.size();
    mergeSort(arr, 0, n - 1);

    cout << "\nSorted Array: ";
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}

