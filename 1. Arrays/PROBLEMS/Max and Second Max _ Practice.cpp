#include <bits/stdc++.h>
using namespace std;

typedef long long unsigned int bigInt;
#define mod 1000000007;
#define deb(x) cout << # x << " = " << x << endl;
#define deb2(x, \
             y) cout << # x << " = " << x << ", " << # y << " = " << y << endl;
#define printArr(arr, size) cout << # arr << " : "; \
   for (int i = 0; i < size; i++) cout << arr[i] << " "; cout << endl;


/**
 * @brief      Finds a maximum and second maximum element from a given array.
 *             The idea is to use kadane's algorithm with modification being
 *             whenever we change maximum element we take it's previous value as
 *             second largest otherwise we know the current value is less than
 *             maximum then just check it with second largest and choose maximum
 *             of the two. It's time complexity is O(n) and it's space
 *             complexity is O(1).
 *
 * @param      arr   The array
 * @param[in]  size  The size of the array
 */
void findMaxAndSecondMax(int *arr, int size) {
   int maxElem       = INT_MIN;
   int secondMaxElem = INT_MIN;

   for (int i = 1; i < size; i++) {
      if (arr[i] > maxElem) {
         secondMaxElem = maxElem;
         maxElem       = arr[i];
      } else {
         secondMaxElem = max(secondMaxElem, arr[i]);
      }
   }
   cout << "Max : " << maxElem << endl;
   cout << "Second max : " <<
      (maxElem == secondMaxElem ||
       secondMaxElem == INT_MIN ? -1 : secondMaxElem) << endl;
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
      findMaxAndSecondMax(arr, size);
      cout << endl;
   }
   return (0);
}
