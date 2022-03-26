#include <bits/stdc++.h>
using namespace std;

typedef long long unsigned int bigInt;
#define mod 1000000007;
#define deb(x) cout << # x << " = " << x << endl;
#define deb2(x, \
             y) cout << # x << " = " << x << ", " << # y << " = " << y << endl;
#define printArr(arr, size) cout << # arr << " : "; \
   for (int i = 0; i < size; i++) cout << arr[i] << " "; cout << endl;


vector<int>removeDuplicatesFromPrimeNumberArray(vector<int>& arr, int size) {
   unordered_set<int> set;
   vector<int> res;

   for (int i = 0; i < size; i++) {
      if (set.count(arr[i]) == 0) {
         res.push_back(arr[i]);
      }
      set.insert(arr[i]);
   }
   return (res);
}

int main() {
   int testCases;

   srand(time(0));
   cin >> testCases;
   cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

   for (int i = 0; i < testCases; i++) {
      int size;
      cin >> size;
      vector<int> arr;

      for (int i = 0; i < size; i++) {
         int val;
         cin >> val;
         arr.push_back(val);
      }
      vector<int> res = removeDuplicatesFromPrimeNumberArray(arr, size);
      printArr(res, res.size());
      cout << endl;
   }
   return (0);
}
