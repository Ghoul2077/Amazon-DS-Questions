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
 * @brief      Gets the minimum absolute difference between indexes of 2 given
 *             numbers in the given array. The naive idea is to run 2 for loops,
 *             the first one checks if the current element is x and if it is
 *             then we find the corresponding y via the nested loop and then for
 *             every hit of y we calculate the difference of index i.e
 *             abs(j - i) and then update the result to minimum accordingly.
 *             It's time complexity is O(n) and it's space complexity is O(1).
 *
 * @param      arr   The array
 * @param[in]  size  The size of the array
 * @param[in]  x     The first element of the pair between whom we find distance
 * @param[in]  y     The second element of the pair between whom we find distance
 */
void getMinDiffNaive(int *arr, int size, int x, int y) {
   int res = INT_MAX;

   for (int i = 0; i < size; i++) {
      if (arr[i] != x) {
         continue;
      }

      for (int j = 0; j < size; j++) {
         if (arr[j] == y) {
            res = min(res, abs(j - i));
         }
      }
   }
   cout << (res == INT_MAX ? -1 : res);
}

/**
 * @brief      Gets the minimum absolute difference between indexes of 2 given
 *             numbers in the given array. The idea is that we need to first
 *             understand that to get minimum difference we need to find closest
 *             indexes which means we need to find the closest pairs. Suppose
 *             we are traversing the array using a single loop and at every
 *             iteration we check if current element is x or y or both, this
 *             ensures that we always get closest pair along with other ones. At
 *             every iteration we calculate the absolute difference and update
 *             the result accordingly. It's time complexity is O(n) and it's
 *             space complexity is O(1).
 *
 * @param      arr   The array
 * @param[in]  size  The size of the array
 * @param[in]  x     The first element of the pair between whom we find distance
 * @param[in]  y     The second element of the pair between whom we find distance
 */
void getMinDiff(int *arr, int size, int x, int y) {
   int res = INT_MAX;
   int xIndex = -1, yIndex = -1;

   for (int i = 0; i < size; i++) {
      if (arr[i] == x) {
         xIndex = i;
      }

      if (arr[i] == y) {
         yIndex = i;
      }

      if ((xIndex != -1) && (yIndex != -1)) {
         res = min(res, abs(yIndex - xIndex));
      }
   }
   cout << (res == INT_MAX ? -1 : res);
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
      int x, y;
      cin >> x;
      cin >> y;
      getMinDiff(arr, size, x, y);
      cout << endl;
   }
   return (0);
}
