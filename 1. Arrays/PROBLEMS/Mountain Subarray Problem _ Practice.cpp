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
 * @brief      We are given an array of numbers and another array of pair of
 *             numbers which in this case are queries containing a starting
 *             index and an ending index, our job is to find whether the given
 *             range is mountain or not, mountain can be increasing and then
 *             decreasing, only increasing or only decreasing ranges. The idea
 *             we use here is to loop through all the queries and for each query
 *             we loop through the range provided in the query and look for the
 *             one case that violates the mountain property that is between 3
 *             consecutive numbers in the query range if there is condition
 *             (1st > 2nd and 3rd > 2nd) existing then we can say that the given
 *             range cannot be mountain. The time complexity of this method is
 *             O(n^2) and it's space complexity is O(1).
 *
 * @param      arr            The array
 * @param[in]  size           The size of the array
 * @param      subarrays      The subarrays (Array containing queries (pair))
 * @param[in]  subarrayCount  The count of subarray / queries
 */
void processQueriesNaive(int  *arr,
                         int   size,
                         int **subarrays,
                         int   subarrayCount) {
   for (int i = 0; i < subarrayCount; i++) {
      int  start = subarrays[i][0], stop = subarrays[i][1];
      bool isMountain = true;
      int  prevIndex  = start + 1;

      for (int j = start + 2; j <= stop; j++) {
         if ((arr[j] > arr[j - 1]) && (arr[prevIndex] < arr[prevIndex - 1])) {
            isMountain = false;
            break;
         }
         prevIndex = j;

         while (j < stop && arr[j] == arr[j + 1]) {
            j++;
         }
      }

      if (isMountain) {
         cout << "Yes";
      } else {
         cout << "No";
      }

      cout << endl;
   }
}

/**
 * @brief      We are given an array of numbers and another array of pair of
 *             numbers which in this case are queries containing a starting
 *             index and an ending index, our job is to find whether the given
 *             range is mountain or not, mountain can be increasing and then
 *             decreasing, only increasing or only decreasing ranges. This
 *             optimized solution is a bit tricky as for this we need to do some
 *             precomputations. In this case we first compute the nearest last
 *             strictly increasing number to the left of each index and secondly
 *             we calculate the nearest first element of a strictly decreasing
 *             series to the right of each index. By using these 2 precomputed
 *             array we use the fact that to form a mountain the nearest
 *             decresing series to starting index must occure after the nearest
 *             increasing series of the ending index, only when this condition
 *             violates we see that mountain is not formed. The time complexity
 *             of this method is O(n) and it's space complexity is O(n).
 *
 * @param      arr            The array
 * @param[in]  size           The size of the array
 * @param      subarrays      The subarrays (Array containing queries (pair))
 * @param[in]  subarrayCount  The count of subarray / queries
 */
void processQueries(int *arr, int size, int **subarrays, int subarrayCount) {
   int *incrementArr = new int[size];
   int *decrementArr = new int[size];

   incrementArr[0] = 0;

   for (int i = 1; i < size; i++) {
      incrementArr[i] = (arr[i] > arr[i - 1] ? i : incrementArr[i - 1]);
   }

   decrementArr[size - 1] = size - 1;

   for (int i = size - 2; i >= 0; i--) {
      decrementArr[i] = (arr[i] > arr[i + 1] ? i : decrementArr[i + 1]);
   }

   for (int i = 0; i < subarrayCount; i++) {
      int start = subarrays[i][0], stop = subarrays[i][1];

      if (incrementArr[stop] <= decrementArr[start]) {
         cout << "Yes";
      } else {
         cout << "No";
      }
      cout << endl;
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
      int numberOfSubarrays;
      cin >> numberOfSubarrays;
      int **subarrays = new int *[numberOfSubarrays];

      for (int i = 0; i < numberOfSubarrays; i++) {
         subarrays[i] = new int[2];
         cin >> subarrays[i][0];
         cin >> subarrays[i][1];
      }

      processQueries(arr, size, subarrays, numberOfSubarrays);
      cout << endl;
   }
   return (0);
}
