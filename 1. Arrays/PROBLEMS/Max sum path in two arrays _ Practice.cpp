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
 * @brief      Finds the path to end of either of the 2 given sorted array
 *             having the maximum sum, the condition being that you are allowed
 *             to jump to the other array on common elements. The idea is to use
 *             the fact that the arrays are sorted and build the solution on
 *             that. What we do is we iterate both the arrays simultaneously and
 *             keep track of the sum of both individual array, one thing to note
 *             is that the common elements divide the arrays into subarrays and
 *             between these subarray we have to choose the one with the greater
 *             sum so for that we need to compare our currently being calculated
 *             sum of both the arrays whenever we encounter a common element.
 *             This common element is encountered by comparing the elements
 *             pointers are currently pointing to and incrementing the pointer
 *             of the smaller of the two because incrementing the greater one
 *             will never allow us to reach the common point. In such way we
 *             will reach a point where one of the array will complete iteration
 *             after which we know we have reach the last segment of both the
 *             arrays and we just need to add the max of the 2 segments and we
 *             will have our path with maximum sum. It's time complexity is
 *             O(m + n) and it's space complexity is O(1).
 *
 * @param      arr1   The array 1
 * @param[in]  size1  The size of array 1
 * @param      arr2   The array 2
 * @param[in]  size2  The size of array 2
 */
void findMaximumSumPathToReachEndOfEitherOfThe2Arrays(int *arr1,
                                                      int  size1,
                                                      int *arr2,
                                                      int  size2) {
   int pathSum = 0;
   int pointer1 = 0, pointer2 = 0;
   int sum1 = 0, sum2 = 0;

   while (pointer1 < size1 && pointer2 < size2) {
      if (arr1[pointer1] > arr2[pointer2]) {
         sum2 += arr2[pointer2++];
      } else if (arr1[pointer1] < arr2[pointer2]) {
         sum1 += arr1[pointer1++];
      } else {
         pathSum += max(sum1, sum2);
         pathSum += arr1[pointer1];
         sum1     = 0;
         sum2     = 0;
         pointer1++;
         pointer2++;
      }
   }

   while (pointer1 < size1) {
      sum1 += arr1[pointer1++];
   }

   while (pointer2 < size2) {
      sum2 += arr2[pointer2++];
   }

   pathSum += max(sum1, sum2);

   cout << pathSum;
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
      findMaximumSumPathToReachEndOfEitherOfThe2Arrays(arr1,
                                                       size1,
                                                       arr2,
                                                       size2);
      cout << endl;
   }
   return (0);
}
