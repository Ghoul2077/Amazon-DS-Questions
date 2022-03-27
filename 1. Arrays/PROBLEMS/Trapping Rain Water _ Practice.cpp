#include <bits/stdc++.h>
using namespace std;

typedef long long unsigned int bigInt;
#define mod 1000000007;
#define deb(x) cout << # x << " = " << x << endl;
#define deb2(x, \
             y) cout << # x << " = " << x << ", " << # y << " = " << y << endl;
#define printArr(arr, size) cout << # arr << " : "; \
   for (int i = 0; i < size; i++) cout << arr[i] << " "; cout << endl;


int findAmountOfWaterThatCanBeTrapped(int *arr, int size) {
   int  res = 0;
   int *leftMaxArr = new int[size], *rightMaxArr = new int[size];

   leftMaxArr[0] = arr[0];

   for (int i = 1; i < size; i++) {
      leftMaxArr[i] = max(arr[i], leftMaxArr[i - 1]);
   }

   rightMaxArr[size - 1] = arr[size - 1];

   for (int i = size - 2; i >= 0; i--) {
      rightMaxArr[i] = max(arr[i], rightMaxArr[i + 1]);
   }

   for (int i = 1; i < size - 1; i++) {
      res += abs(arr[i] - min(leftMaxArr[i], rightMaxArr[i]));
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
      int *arr = new int[size];

      for (int i = 0; i < size; i++) {
         cin >> arr[i];
      }
      cout << findAmountOfWaterThatCanBeTrapped(arr, size);
      cout << endl;
   }
   return (0);
}
