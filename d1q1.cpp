/*
  You are given two integer arrays arr1 and arr2. Find the union of the two arrays. The union should contain all unique elements from both arrays. Return the result in sorted order.
  🧪 Test Case:
  
  Input:
  arr1 = [1, 2, 4, 5]
  arr2 = [2, 3, 5, 6]
  
  Output:
  [1, 2, 3, 4, 5, 6]
*/
  

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

vector<int> merge_arr(vector<int>& v1, vector<int>&v2) {
    vector<int> result;
    uint i = 0, j = 0;
    auto add = [&](int val) {
        if(result.empty() || result.back() != val) result.push_back(val);
    };

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    while(i < v1.size() && j < v2.size()) {
        if (v1[i] < v2[j]) add(v1[i++]);
        else if(v1[i] > v2[j]) add(v2[j++]);
        else { add(v1[i++]); ++j;}
    }
    while(i < v1.size()) add(v1[i++]);
    while(j < v2.size()) add(v2[j++]);

    return result;
}

int main() {
    vector<int> v1 = {10, 3, 4};
    vector<int> v2 = {2, 3, 4, 5};
    for (auto it: merge_arr(v1, v2)) cout << it << ", ";
    cout << endl;
    return 0;
}
