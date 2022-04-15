#include <bits/stdc++.h>
using namespace std;

typedef long long unsigned int bigInt;
#define mod 1000000007;
#define deb(x) cout << # x << " = " << x << endl;
#define deb2(x, \
             y) cout << # x << " = " << x << ", " << # y << " = " << y << endl;
#define printArr(arr, size) cout << # arr << " : "; \
   for (int i = 0; i < size; i++) cout << arr[i] << " "; cout << endl;


void countLessThanOrEqualForEveryElementInArray1InArray2Naive(int *arr1,
                                                              int  size1,
                                                              int *arr2,
                                                              int  size2) {
   for (int i = 0; i < size1; i++) {
      int count = 0;

      for (int j = 0; j < size2; j++) {
         if (arr2[j] <= arr1[i]) {
            count++;
         }
      }
      cout << count << " ";
   }
}

void countLessThanOrEqualForEveryElementInArray1InArray2(int *arr1,
                                                         int  size1,
                                                         int *arr2,
                                                         int  size2) {
   sort(arr2, arr2 + size2);

   for (int i = 0; i < size1; i++) {
      int count = size2;
      int start = 0, stop = size2 - 1;

      while (start <= stop) {
         int mid = (start + stop) / 2;

         if (arr2[mid] <= arr1[i]) {
            start = mid + 1;
         } else {
            count = mid;
            stop  = mid - 1;
         }
      }
      cout << count << " ";
   }
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
      countLessThanOrEqualForEveryElementInArray1InArray2(arr1,
                                                          size1,
                                                          arr2,
                                                          size2);
      cout << endl;
   }
   return (0);
}
