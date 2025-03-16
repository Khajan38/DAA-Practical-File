#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//Question: Given an unsorted array of integers, design an algorithm and implement it using a program to sort an array of elements by partitioning the array into two subarrays based on a pivot element such that one of the sub array holds values smaller than the pivot element while another sub array holds values greater than the pivot element. Pivot element should be selected randomly from the array. Your program should also find number of comparisons and swaps required for sorting the array.

int partition (vector <int> & arr, int start, int end){
     int size = end - start + 1, randomNum = rand() % size + start;
	swap(arr[end], arr[randomNum]);
     cout<<"\nArray : "; for (int i = 0; i < size; ++i) cout<<arr[i]<<" ";
     int pivot = arr[end], i = start;
     for (int j = end - 1; i < j; )
          if (arr[i] < pivot) ++i;
          else swap(arr[i], arr[j--]);
     swap(arr[i], arr[end]);
     cout<<" ----> Array : "; for (int i = 0; i < size; ++i) cout << arr[i] << " ";
     return i;
}
void quickSort (vector <int> & arr, int start, int end){
     if (start >= end) return;
     int pivot = partition(arr, start, end);
     quickSort(arr, start, pivot - 1);
     quickSort(arr, pivot + 1, end);
}

int main (){
	int size;
     cout<<"\nEnter no. of elements : "; cin>>size; 
     cout<<"Enter elements : ";
     vector <int> arr (size);
     for (int i = 0; i < size; ++i) cin>>arr[i];
	// pair <int, int> values = mergeSort(arr, 0, arr.size() - 1);
     quickSort(arr, 0, arr.size() - 1);
	cout<<"\n\nSorted Array : ";
	for (int i = 0; i < size; ++i) cout << arr[i] << " ";
	// cout << "\nNo. of inversions : " << values.first;
	// cout << "\nNo. of comparisons : " << values.second << endl;
	return 0;
}