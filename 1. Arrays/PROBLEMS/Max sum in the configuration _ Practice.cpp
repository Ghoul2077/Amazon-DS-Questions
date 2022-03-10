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
 * @brief      Finds the maximum weighted sum of a given circular array.
 *             Weighted sum is sum of array as (arr[i] * i). The idea here we
 *             use is that we iterate through the array and use every current
 *             element as a starting point and use another nested for loop to
 *             calculate the weighted sum this way we get every weighted sum
 *             possible and we just pick the maximum from it. It's time
 *             complexity is O(n^2) and it's space complexity is O(1).
 *
 * @param      arr   The array
 * @param[in]  size  The size of array
 */
void maximumWeightedSumNaive(int *arr, int size) {
   int maximumSum = 0;

   for (int i = 0; i < size; i++) {
      int currSum = 0;

      for (int j = i; j < i + size; j++) {
         int index = (j % size);
         currSum += (arr[index] * (j - i));
      }
      maximumSum = max(maximumSum, currSum);
   }
   cout << maximumSum;
}

/**
 * @brief      Finds the maximum weighted sum of a given circular array.
 *             Weighted sum is sum of array as (arr[i] * i). The idea here we
 *             use is that we make some pre computations i.e we calculate the
 *             sum of the array and first weighted sum (starting index as 0). We
 *             use the previous weighted sum to calculate the next weighted sum
 *             using the formula (previous sum - sum of array + current starting
 *             value + (current starting value * size - 1)). It's time
 *             complexity is O(n) and it's space complexity is O(1).
 *
 * @param      arr   The array
 * @param[in]  size  The size of array
 */
void maximumWeightedSum(int *arr, int size) {
   int previousWeightedSum = 0;
   int arrSum              = 0;

   for (int i = 0; i < size; i++) {
      previousWeightedSum += (arr[i] * i);
      arrSum              += arr[i];
   }
   int maximumWeightedSum = previousWeightedSum;

   for (int i = 1; i < size; i++) {
      int currWeightedSum = previousWeightedSum - (arrSum - arr[i - 1]) +
                            arr[i - 1] * (size - 1);
      maximumWeightedSum = max(maximumWeightedSum, currWeightedSum);
   }
   cout << maximumWeightedSum;
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
      maximumWeightedSum(arr, size);
      cout << endl;
   }
   return (0);
}
