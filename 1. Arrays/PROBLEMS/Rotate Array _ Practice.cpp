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
 * @brief      Rotate the given array by D elements to the left (i.e counter
 *             clockwise). The idea is to reverse first D elements, reverse
 *             the elements after first D elements and at last reverse the whole
 *             array. It's time complexity is O(n) and O(1).
 *
 * @param      arr   The array
 * @param[in]  size  The size of the array
 * @param[in]  d     Number of elements to rotate by
 */
void rotateArrayByDElements(int *arr, int size, int d) {
   reverse(arr,     arr + d);
   reverse(arr + d, arr + size);
   reverse(arr,     arr + size);
}

int main() {
   int testCases;

   srand(time(0));
   cin >> testCases;
   cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

   for (int i = 0; i < testCases; i++) {
      int size, d;
      cin >> size;
      cin >> d;
      int *arr = new int[size];

      for (int i = 0; i < size; i++) {
         cin >> arr[i];
      }
      rotateArrayByDElements(arr, size, d);
      printArr(arr, size);
      cout << endl;
   }
   return (0);
}
