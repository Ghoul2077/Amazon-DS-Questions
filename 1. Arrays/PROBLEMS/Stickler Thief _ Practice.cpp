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
 * @brief      A thief wants to loot an array of houses with the given condition
 *             that no 2 houses he loots from be adjacent. The idea is to solve
 *             this problem using reccursion. At any given point there can be
 *             only 2 conditions i.e we either take the current value and then
 *             check for current element - 2 or we don't take the current
 *             element and check for it's adjacent element. The tricky part here
 *             is the base cases. We need to make sure that we handle both base
 *             cases i.e of 0 and negatives, as we keep on subtracting so we are
 *             bound to end up with negative in which case we return 0 and in
 *             case of 0 we return the first element of the array. It's time
 *             complexity is O(2^n) and it's space complexity is O(2^n).
 *
 * @param      arr   The array
 * @param[in]  size  The size of the array
 * @param      dp    Dynamic programming table
 *
 * @return     Maximum loot possible
 */
int findMaximumLootPossibleNaive(int *arr, int size) {
   if (size < 0) {
      return (0);
   }

   if (size == 0) {
      return (arr[0]);
   }

   int val1 = findMaximumLootPossibleNaive(arr, size - 1);
   int val2 = arr[size] + findMaximumLootPossibleNaive(arr, size - 2);

   return (max(val1, val2));
}

/**
 * @brief      A thief wants to loot an array of houses with the given condition
 *             that no 2 houses he loots from be adjacent. The idea is to solve
 *             this problem using reccursion but while avoiding repeating
 *             calculation. This is made possible by a DP array which we pass
 *             to the function and in this array we store the solution of
 *             subarrays which we have calculated. Next time we need the
 *             solution of any subarray to build next solution we will refer the
 *             DP table rather than calculating it all over again. It's time
 *             complexity is O(n) and it's space complexity is O(n).
 *
 * @param      arr   The array
 * @param[in]  size  The size of the array
 * @param      dp    Dynamic programming table
 *
 * @return     Maximum loot possible
 */
int findMaximumLootPossible(int *arr, int size, vector<int>& dp) {
   if (size < 0) {
      return (0);
   }

   if (size == 0) {
      return (arr[0]);
   }

   if (dp[size] != -1) {
      return (dp[size]);
   }

   int val1 = findMaximumLootPossible(arr, size - 1, dp);
   int val2 = arr[size] + findMaximumLootPossible(arr, size - 2, dp);

   return (dp[size] = max(val1, val2));
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
      vector<int> dp(size + 1, -1);
      cout << findMaximumLootPossible(arr, size, dp);
      cout << endl;
   }
   return (0);
}
