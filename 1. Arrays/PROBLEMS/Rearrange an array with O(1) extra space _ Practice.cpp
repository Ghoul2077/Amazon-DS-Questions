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
 * @brief      Given an array arr, we need to convert array by aapplying the
 *             following function => arr[i] = arr[arr[i]]. In this method we
 *             have created a new array of same size as original array and then
 *             by applying the formula on the original index we store the
 *             resulting values in auxillary array which we will use to
 *             overwrite the values of original array. It's time complexity is
 *             O(n) and it's space complexity is O(n).
 *
 * @param      arr   The array
 * @param[in]  size  The size of the array
 */
void rearrangeArrayNaive(int *arr, int size) {
   int *res = new int[size];

   for (int i = 0; i < size; i++) {
      res[i] = arr[arr[i]];
   }

   for (int i = 0; i < size; i++) {
      arr[i] = res[i];
   }
   delete[] res;
}

/**
 * @brief      Given an array arr, we need to convert array by aapplying the
 *             following function => arr[i] = arr[arr[i]]. In this method we
 *             use the fact that all values are less than size of the array
 *             hence we transform all values into such that both the original
 *             and new can be found by minimal work and no dependencies. This
 *             is done by using the formula (new value * size) + old value.
 *             Dividing the result of this formula by size gives us the new
 *             value and modulus of this gives us the old value. It's time
 *             complexity is O(n) and it's space complexity is O(1).
 *
 * @param      arr   The array
 * @param[in]  size  The size of the array
 */
void rearrangeArray(int *arr, int size) {
   for (int i = 0; i < size; i++) {
      arr[i] += (arr[arr[i]] % size) * size;
   }

   for (int i = 0; i < size; i++) {
      arr[i] /= size;
   }
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
      rearrangeArray(arr, size);
      printArr(arr, size);
   }
   return (0);
}
