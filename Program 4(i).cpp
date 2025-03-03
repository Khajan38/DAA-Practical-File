#include <iostream>
#include <vector>
using namespace std;
void merge (vector <int> & arr, int start, int pivot, int end){
  vector <int> temp (end - start + 1);
  for (int i = 0; i < end - start + 1; ++i) temp[i] = arr[start + i];
  int i = 0, j = pivot - start + 1, k = start;
  while (i <= pivot - start && j <= end - start){
    if (temp[i] <= temp[j]) arr[k++] = temp[i++];
    else arr[k++] = temp[j++];
  }
  while (i <= pivot - start) arr[k++] = temp[i++];
  while (j <= end - start) arr[k++] = temp[j++];
}
void mergeSort (vector <int> & arr, int start, int end){
  if (start >= end) return;
  int mid = start + (end - start)/2;
  mergeSort(arr, start, mid);
  mergeSort(arr, mid + 1, end);
  merge(arr, start, mid, end);
}
