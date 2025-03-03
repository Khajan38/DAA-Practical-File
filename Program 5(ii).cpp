#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
vector <int> twoSum (vector <int> & arr, int target){
  int size = arr.size();
  map <int, int> hash;
  for (int i = 0; i < size; ++i){
    int toFind = target - arr[i];
    if (hash.find(toFind) != hash.end())
      return {hash[toFind], i};
    if (hash.find(arr[i]) == hash.end()) hash[arr[i]] = i;
  }
  return {-1, -1};
}
vector <int> twoSum (vector <int> & arr, int target){
  int i = 0, j = arr.size() - 1;
  sort (arr.begin(), arr.end());
  while (i < j)
    if (arr[i] + arr[j] > target) --j;
    else if (arr[i] + arr[j] < target) ++i;
    else return {arr[i], arr[j]};
  return {-1, -1};
}
