#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int binarySearch (vector <int> & arr, int key){
   int i = 0, j = arr.size() - 1;
   while (i <= j){
      int mid = (i + j)/2;
      if (arr[mid] == key) return mid;
      else if (arr[mid] < key) i = mid + 1;
      else j = mid - 1;
   }
   return -1;
}
int findCopies (vector <int> & arr, int keyIndex){
  int key = arr[keyIndex];
  int k = keyIndex, j = arr.size() - 1, count = 1;
  while (k < j && arr[++k] == key) ++count;
  k = keyIndex;
  while (k >= 1 && arr[--k] == key) ++count;
  return count;
}
int main (){
  int n;
  cout<<"\nEnter number of elements : "; cin>>n;
  vector <int> arr (n);
  cout<<"Enter elements : "; 
  for (int i = 0; i < n; ++i) cin>>arr[i];
  sort(arr.begin(), arr.end());
  int key;
  cout<<"\nEnter the key to be searched : "; cin>>key;
  int found = binarySearch(arr, key);
  if (found != -1) cout<<"\n\tElement found with "<<findCopies(arr, found) <<" copies...\n";
  else cout<<"\tElement not found...\n";
  return 0;
}
