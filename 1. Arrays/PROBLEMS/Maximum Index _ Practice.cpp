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
 * @brief      Given an array we need to find the maximum difference (j - i)
 *             given the condition arr[j] >= arr[i]. Here we have used the naive
 *             method of calculating every difference using 2 nested for loops.
 *             It's time complexity is O(n^2) and it's space complexity is O(1).
 *
 * @param      arr   The array
 * @param[in]  size  The size of array
 */
void maxIndexDiffNaive(int *arr, int size) {
   int res = INT_MIN;

   for (int i = 0; i < size; i++) {
      for (int j = i + 1; j < size; j++) {
         if (arr[i] <= arr[j]) {
            res = max(res, j - i);
         }
      }
   }
   cout << (res == INT_MIN ? 0 : res);
}

/**
 * @brief      Given an array we need to find the maximum difference (j - i)
 *             given the condition arr[j] >= arr[i]. The idea is to understand
 *             that for every element of the array we are finding the rightmost
 *             bigger element, suppose we know the rightmost biggest element of
 *             every index (suppose you have them stored in an array) then we
 *             know the rightmost bigger element of every index is going to be
 *             from this array. So we loop the array and for every element we
 *             perform binary search on the array where the rightmost biggest
 *             elements are stored to find all the bigger elements than our
 *             current element we perform the difference of index on every such
 *             hit and store maximum of all of them in a variable. It's time
 *             compelxity is O(nlogn) and it's space complexity is O(1).
 *
 *
 * @param      arr   The array
 * @param[in]  size  The size of array
 */
void maxIndexDiff1(int *arr, int size) {
   int *biggestFromEnd = new int[size];

   biggestFromEnd[size - 1] = arr[size - 1];

   for (int i = size - 2; i >= 0; i--) {
      biggestFromEnd[i] = max(biggestFromEnd[i + 1], arr[i]);
   }
   int res = 0;

   for (int i = 0; i < size; i++) {
      int start = i, end = size - 1, mid;

      while (start <= end) {
         mid = (start + end) / 2;

         if (biggestFromEnd[mid] <= arr[i]) {
            end = mid - 1;
         } else {
            res   = max(res, mid - i);
            start = mid + 1;
         }
      }
   }

   cout << res;
}

/**
 * @brief      Given an array we need to find the maximum difference (j - i)
 *             given the condition arr[j] >= arr[i]. This is the most logical
 *             non naive solution. If you see the problem clearly we see that we
 *             need to find the first smallest value and it's corresponding
 *             largest rightmost value. So to accomplish that we store indexes
 *             in a hashmap then we sort the array as by this way we will get
 *             smallest values first and then we iterate this sorted array and
 *             keep track of smallest index we can find of these smallest values
 *             and at every iteration we keep subtracting the last index of the
 *             current element with the smallest index of smaller value we keep
 *             track of. This way at every iteration we can compare from
 *             previous maximum difference and at end we reach our solution.
 *             It's time complexity is O(nlogn) and it's space complexity is
 *             O(n)
 *
 * @param      arr   The array
 * @param[in]  size  The size of array
 */
void maxIndexDiff2(int *arr, int size) {
   unordered_map<int, vector<int> > map;

   for (int i = 0; i < size; i++) {
      map[arr[i]].push_back(i);
   }
   sort(arr, arr + size);
   int currI = size, maxDiff = INT_MIN;

   for (int i = 0; i < size; i++) {
      currI   = min(currI, map[arr[i]].front());
      maxDiff = max(maxDiff, map[arr[i]].back() - currI);
   }
   cout << maxDiff;
}

/**
 * @brief      Given an array we need to find the maximum difference (j - i)
 *             given the condition arr[j] >= arr[i]. This is a very tricky
 *             solution where we need to know what does it mean by finding lmin
 *             and rmax of a given array. lmin of array means a lower bound for
 *             an every index and rmax means upperbound of every index. Both
 *             lmin and rmax have unique properties, for lmin it is that lmin
 *             only changes from left to right when we encounter a lower value &
 *             for rmax it's value only changes when we pass the current maximum
 *             value that we have been seeing in continuation. So we start
 *             iterating both lmin and rmax, we stop at every first occurance
 *             of each distinct value and for rmax we stop at every last
 *             occurance of each distinct value bigger than current lmin now we
 *             subtract the indexes and compare with our previously stored
 *             maximum and update accordingly. The below implementation follows
 *             the same concept just the while loop has been made simpler in
 *             code format so it takes difference each time we change i or j.
 *             It's time complexity is O(n) and it's space complexity is O(n).
 *
 * @param      arr   The array
 * @param[in]  size  The size of array
 */
void maxIndexDiffOptimized(int *arr, int size) {
   int  res = 0;
   int *lmin = new int[size], *rmax = new int[size];

   lmin[0]        = arr[0];
   rmax[size - 1] = arr[size - 1];

   for (int i = 1; i < size; i++) {
      lmin[i] = min(lmin[i - 1], arr[i]);
   }

   for (int i = size - 2; i >= 0; i--) {
      rmax[i] = max(rmax[i + 1], arr[i]);
   }

   int i = 0, j = 0;

   while (i < size && j < size) {
      if (lmin[i] <= rmax[j]) {
         res = max(res, j - i);
         j++;
      } else {
         i++;
      }
   }
   cout << res;
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
      maxIndexDiffOptimized(arr, size);
      cout << endl;
   }
   return (0);
}
