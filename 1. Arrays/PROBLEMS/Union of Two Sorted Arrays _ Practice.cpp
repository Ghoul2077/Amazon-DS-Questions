#include <bits/stdc++.h>
using namespace std;

typedef long long unsigned int bigInt;
#define mod 1000000007;
#define deb(x) cout << # x << " = " << x << endl;
#define deb2(x, \
             y) cout << # x << " = " << x << ", " << # y << " = " << y << endl;
#define printArr(arr, size) cout << # arr << " : "; \
   for (int i = 0; i < size; i++) cout << arr[i] << " "; cout << endl;


vector<int>unionOfSortedArrays(int *arr1, int size1, int *arr2, int size2) {
   vector<int> res;
   int i = 0, j = 0;

   while (i < size1 && j < size2) {
      if ((arr1[i] < arr2[j])) {
         res.push_back(arr1[i++]);
      } else {
         res.push_back(arr2[j++]);
      }

      while (i < size1 && res.back() == arr1[i]) {
         i++;
      }

      while (j < size2 && res.back() == arr2[j]) {
         j++;
      }

      if ((i == size1) || (j == size2)) {
         break;
      }
   }

   while (i < size1) {
      if (res.back() != arr1[i]) {
         res.push_back(arr1[i++]);
      } else {
         i++;
      }
   }

   while (j < size2) {
      if (res.back() != arr2[j]) {
         res.push_back(arr2[j++]);
      } else {
         j++;
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
      int size1, size2;
      cin >> size1;
      cin >> size2;
      int *arr1 = new int[size1];
      int *arr2 = new int[size2];

      for (int i = 0; i < size1; i++) {
         cin >> arr1[i];
      }

      for (int i = 0; i < size2; i++) {
         cin >> arr2[i];
      }
      vector<int> res = unionOfSortedArrays(arr1, size1, arr2, size2);
      printArr(res, res.size());
      cout << endl;
   }
   return (0);
}
