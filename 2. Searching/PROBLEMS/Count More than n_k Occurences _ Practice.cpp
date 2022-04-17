#include <bits/stdc++.h>
using namespace std;

typedef long long unsigned int bigInt;
#define mod 1000000007;
#define deb(x) cout << # x << " = " << x << endl;
#define deb2(x, \
             y) cout << # x << " = " << x << ", " << # y << " = " << y << endl;
#define printArr(arr, size) cout << # arr << " : "; \
   for (int i = 0; i < size; i++) cout << arr[i] << " "; cout << endl;


int countElementsWithMoreThanNByKOccurances(int *arr, int size, int k) {
   unordered_map<int, int> map;

   for (int i = 0; i < size; i++) {
      map[arr[i]]++;
   }
   int res                     = 0;
   int minimumOccurancesNeeded = size / k;

   for (auto i : map) {
      if (i.second > minimumOccurancesNeeded) {
         res++;
      }
   }
   return (res);
}

int main() {
   int testCases;

   srand(time(0));
   cin >> testCases;
   cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

   for (int i = 0; i < testCases; i++) {
      int size, k;
      cin >> size;
      int *arr = new int[size];

      for (int i = 0; i < size; i++) {
         cin >> arr[i];
      }
      cin >> k;
      cout << countElementsWithMoreThanNByKOccurances(arr, size, k);
      cout << endl;
   }
   return (0);
}
