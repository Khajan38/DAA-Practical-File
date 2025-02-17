#include <bits/stdc++.h>
using namespace std;
pair <int, int> insertionSort (vector <int> & arr){
  int size = arr.size();
  int shifts = 0, comparisons = 0;
  if (size <= 1) return {0, 0};
  for (int i = 1; i < size; ++i){
    int pivot = arr[i], j = i - 1;
    for (; j >= 0; --j){
      ++comparisons;
      if (arr[j] <= pivot) break;
      arr[j + 1] = arr[j];
      ++shifts;
    }                                           
    if (j < 0) ++comparisons;
    arr[j + 1] = pivot;
  }
  return {shifts, comparisons};
}
pair <int, int> insertionSort (vector <int> & arr){
  int size = arr.size();
  int shifts = 0, comparisons = 0;
  if (size <= 1) return {0, 0};
  for (int i = 1; i < size; ++i){
    int pivot = arr[i], j = i - 1;
    while (j >= 0 && arr[j] > pivot){
      arr[j + 1] = arr[j];
      ++shifts;
      --j;
    }
    comparisons += i - j;
    arr[j + 1] = pivot;
  }
  return {shifts, comparisons};
}
int main (){
  vector <int> arr = {3, 5, 4, 1, 2};
  cout<<"Sorted Array : ";
  pair <int, int> values = insertionSort(arr);
  int size = arr.size();
  for (int i = 0; i < size; ++i) cout<<arr[i]<<", ";
  cout<<"\nNo. of shifts : "<<values.first;
  cout<<"\nNo. of comparisons : "<<values.second<<endl;
  return 0;
}
