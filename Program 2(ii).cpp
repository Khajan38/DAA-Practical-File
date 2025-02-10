#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
void twoSum (vector <int> & arr, int sum){
  int n = arr.size();
  unordered_map <int, int> hash;
  for (int i = 1; i < n; ++i){
    int toFind = sum - arr[i];
    ++hash[arr[i - 1]];
    for (unordered_map <int, int> :: iterator itr : hash) cout<<itr->first<<":"<<itr->second<<", ";
    if (hash.find(toFind) != hash.end())
      for (int i = 0; i < hash[toFind]; ++i) cout<<arr[i]<<" + "<<toFind<<" = "<<sum<<endl;
  }
}
int main (){
  int n;
  cout<<"\nEnter number of elements : "; cin>>n;
  vector <int> arr (n);
  cout<<"Enter elements : "; 
  for (int i = 0; i < n; ++i) cin>>arr[i];
  if (n < 3) cout<<"Array don't even have 3 elements to begin with...";
  twoSum(arr, 4);
  return 0;
}
