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
 * @brief      Given an array we need to find the maximum sum of subarrays in
 *             the given array. Here we use the naive method where we loop
 *             through the array and in treat each element as a starting element
 *             and then use a nested loop to find sum of each subarray with
 *             starting element as i and we keep changing last element using j.
 *             We are basically calculating sum of each subarray and finding the
 *             maximum from them. It's time complexity is O(n^2) and it's space
 *             complexity is O(1).
 *
 * @param      arr   The array
 * @param[in]  size  The size of array
 */
void subarrayWithMaximumSumNaive(int *arr, int size) {
   int maximumSum = INT_MIN;

   for (int i = 0; i < size; i++) {
      int sum = 0;

      for (int j = i; j < size; j++) {
         sum       += arr[j];
         maximumSum = max(maximumSum, sum);
      }
   }
   cout << maximumSum;
}

/**
 * @brief      Given an array we need to find the maximum sum of subarrays in
 *             the given array. The idea is to use a modified version of kadanes
 *             algorithm where we keep calculating the maximum sum by using the
 *             fact that we have 2 conditions, first that when we add the next
 *             element of the array the sum increases and the other is that on
 *             adding the sum decreases (this happens when the next element is
 *             negative) if the sum decreases we need to make 2 choices that
 *             even though sum decreases is it lower or greater than the element
 *             we just added to the sum (the negative element) hence we need to
 *             choose the greater of the 2 which will give us our running sum.
 *             Now we compare this running sum with our previous maximum sum
 *             like our standard kadane algorithm to get the maximum sum of any
 *             subarray. It's time complexity is O(n) and it's space complexity
 *             is O(1).
 *
 * @param      arr   The array
 * @param[in]  size  The size of array
 */
void subarrayWithMaximumSum(int *arr, int size) {
   int currMaximumSum = arr[0];
   int res            = arr[0];

   for (int i = 1; i < size; i++) {
      currMaximumSum = max(currMaximumSum + arr[i], arr[i]);
      res            = max(res, currMaximumSum);
   }

   cout << (res);
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
      subarrayWithMaximumSum(arr, size);
      cout << endl;
   }
   return (0);
}
