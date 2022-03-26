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
 * @brief      Finds the subarrays with given sum. The idea is to store sum of
 *             all subarrays starting with 0 index in a hashmap and then we need
 *             to understand that any of these subarray subtracting any smaller
 *             0 index subarray can give us all subarrays. So now we just need
 *             to find if there is any smaller subarray with difference of the
 *             current subarray sum and the one we need to find, if yes then
 *             that means we can subtract that extras and we will get our
 *             subarray with the given sum. It's time complexity is O(n) and
 *             it's space complexity is O(n).
 *             Note : This method gives us all possible subarrays on contrary
 *             to the optimized method.
 *
 * @param      arr   The array
 * @param[in]  size  The size of the array
 * @param[in]  sum   The sum of the subarray to be found
 */
void findSubarrayWithSumSNaive(int *arr, int size, int sum) {
   unordered_map<int, int> map;
   int runningSum = 0;
   int resCount   = 0;

   for (int i = 0; i < size; i++) {
      runningSum += arr[i];
      map.insert({ runningSum, i + 1 });

      if (runningSum == sum) {
         cout << 1 << " to " << i + 1 << endl;
         resCount++;
      }

      if (map.count(runningSum - sum) != 0) {
         cout << (map[runningSum - sum]) + 1 << " to " << i + 1 << endl;
         resCount++;
      }
   }

   if (resCount == 0) {
      cout << "No such subarray exists";
   }
}

/**
 * @brief      Finds the subarrays with given sum. Here we use sliding window
 *             technique. If our current running sum is smaller then we increase
 *             the end pointer otherwise if it is smaller we emit the current
 *             starting index from the sum and then increase the starting index.
 *             This way if we get a hit on our sum we can just print the indexes
 *             and return. It's time complexity is O(n) and it's space
 *             complexity is O(1).
 *
 * @param      arr   The array
 * @param[in]  size  The size of the array
 * @param[in]  sum   The sum of the subarray to be found
 */
void findSubarrayWithSumS(int *arr, int size, int sum) {
   int slidingWindowSum = arr[0];
   int start = 0, end = 0;

   while (start <= end && end < size && start < size) {
      if (slidingWindowSum > sum) {
         slidingWindowSum -= arr[start++];
      } else if (slidingWindowSum < sum) {
         slidingWindowSum += arr[++end];
      } else {
         cout << start + 1 << " to " << end + 1;
         return;
      }
   }

   cout << "No such subarray exists";
}

int main() {
   int testCases;

   srand(time(0));
   cin >> testCases;
   cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

   for (int i = 0; i < testCases; i++) {
      int size, sum;
      cin >> size;
      cin >> sum;
      int *arr = new int[size];

      for (int i = 0; i < size; i++) {
         cin >> arr[i];
      }
      findSubarrayWithSumS(arr, size, sum);
      cout << endl;
   }
   return (0);
}
