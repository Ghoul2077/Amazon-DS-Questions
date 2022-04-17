#include <bits/stdc++.h>
using namespace std;

typedef long long unsigned int bigInt;
#define mod 1000000007;
#define deb(x) cout << # x << " = " << x << endl;
#define deb2(x, \
             y) cout << # x << " = " << x << ", " << # y << " = " << y << endl;
#define printArr(arr, size) cout << # arr << " : "; \
   for (int i = 0; i < size; i++) cout << arr[i] << " "; cout << endl;


int findTransitionPointNaive(int *arr, int size) {
   int i;

   for (i = 0; i < size; i++) {
      if ((arr[i] == 1) && (arr[i - 1] == 0)) {
         break;
      }
   }

   if (i == size) {
      return (-1);
   }
   return (i);
}

int findTransitionPoint(int *arr, int size) {
   int start = 0, stop = size - 1;
   int transitionPoint = -1;

   while (start <= stop) {
      int mid = (start + stop) / 2;

      if (arr[mid] == 0) {
         start = mid + 1;
      } else {
         transitionPoint = mid;
         stop            = mid - 1;
      }
   }
   return (transitionPoint);
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
      cout << findTransitionPoint(arr, size);
      cout << endl;
   }
   return (0);
}
