#include <bits/stdc++.h>
using namespace std;

typedef long long unsigned int bigInt;
#define mod 1000000007;
#define deb(x) cout << # x << " = " << x << endl;
#define deb2(x, \
             y) cout << # x << " = " << x << ", " << # y << " = " << y << endl;
#define printArr(arr, size) cout << # arr << " : "; \
   for (int i = 0; i < size; i++) cout << arr[i] << " "; cout << endl;


// Helper function
int findMaximumSubarraySum(int *arr, int size) {
   int currMax = arr[0];
   int res     = arr[0];

   for (int i = 1; i < size; i++) {
      currMax = max(currMax + arr[i], arr[i]);
      res     = max(res, currMax);
   }
   return (res);
}

/**
 * @brief      Finds a maximum of a subarray of a circular array that is range
 *             of the starting index of subarray is i then it's ending index can
 *             range from i to (i + size) % size. The idea we use here is we
 *             create a new array which is nothing but original array
 *             concatenated with itself. Now we iterate over first n elements of
 *             this new array and by taking each index as starting of array we
 *             use kadane's algorithm for maximum sum of subarray (non circular)
 *             to find the maximum in the current array and similarly for all
 *             other n arrays we get. At the end we just take the maximum of all
 *             these and present it as our answer. It's time complexity is
 *             O(n^2) and it's space complexity is O(n).
 *
 * @param      arr   The array
 * @param[in]  size  The size of the array
 */
void findMaximumSubarraySumInCircularFashionNaive(int *arr, int size) {
   int res = INT_MIN;

   int *extendedArr = new int[size * 2];

   for (int i = 0; i < size * 2; i++) {
      extendedArr[i] = arr[i % size];
   }

   for (int i = 0; i < size; i++) {
      int currMax = findMaximumSubarraySum(extendedArr + i, size);
      res = max(res, currMax);
   }

   cout << res;
}

/**
 * @brief      Finds a maximum of a subarray of a circular array that is range
 *             of the starting index of subarray is i then it's ending index can
 *             range from i to (i + size) % size. This is very interesting
 *             solution. The idea we need to know is that we have basically 3
 *             types of arrays one where all elements are positive, second where
 *             all elements are negative and third where elements are mix of
 *             positive and negative. For the first 2 we know that applying
 *             general non circular method to find maximum we can get our answer
 *             the problem is for the third type of array. For that we use a
 *             clever trick where we find the sum of all elements and we just
 *             need to add maximum value which had been subtracted from maximum
 *             subarray sum to get this total. To find this maximum value we
 *             invert the array i.e multiply -1 with all the elements of the
 *             array and now find maximum sum of subarray on this array. The
 *             result will be what we need to add to our initial total to get
 *             our answer for maximum of circular subarray. It's time complexity
 *             is O(n) and it's space complexity is O(1).
 *
 * @param      arr   The array
 * @param[in]  size  The size of the array
 */
void findMaximumSubarraySumInCircularFashion(int *arr, int size) {
   int normalMax = findMaximumSubarraySum(arr, size);

   if (normalMax < 0) {
      cout << normalMax;
      return;
   }

   int totalSum = 0;

   for (int i = 0; i < size; i++) {
      totalSum += arr[i];
      arr[i]    = -arr[i];
   }

   int res = totalSum + findMaximumSubarraySum(arr, size);

   cout << max(normalMax, res);
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
      findMaximumSubarraySumInCircularFashion(arr, size);
      cout << endl;
   }
   return (0);
}
