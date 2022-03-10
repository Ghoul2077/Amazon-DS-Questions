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
 * @brief      Given an array of size n which will contain numbers from 1 to n,
 *             There can be some missing and some can be repeated. We need to
 *             print out the frequency of each number from 1 to n. Here we have
 *             used naive method where we loop from 1 to n and for each number
 *             we count the frequency in the array by iterating through it. It's
 *             time complexity is O(n^2) and it's space complexity is O(1).
 *
 * @param      arr   The array
 * @param[in]  size  The size of array
 */
void getFrequencyCountFromOneToNNaive(int *arr, int size) {
   for (int i = 1; i <= size; i++) {
      int count = 0;

      for (int j = 0; j < size; j++) {
         if (arr[j] == i) {
            count++;
         }
      }
      cout << i << " => " << count << endl;
   }
}

/**
 * @brief      Given an array of size n which will contain numbers from 1 to n,
 *             There can be some missing and some can be repeated. We need to
 *             print out the frequency of each number from 1 to n. Here we use
 *             a hashmap to calculate the frequency of each distinct element in
 *             the array and for the ones that are missing from 1 to n, we use
 *             the fact that by default hashmap gives value 0 to values not
 *             present in it if you try to access them. It's time complexity is
 *             O(n) and it's space complexity is O(n).
 *
 * @param      arr   The array
 * @param[in]  size  The size of array
 */
void getFrequencyCountFromOneToN(int *arr, int size) {
   unordered_map<int, int> map;

   for (int i = 0; i < size; i++) {
      map[arr[i]]++;
   }

   for (int i = 1; i <= size; i++) {
      cout << i << " => " << map[i] << endl;
   }
}

/**
 * @brief      Given an array of size n which will contain numbers from 1 to n,
 *             There can be some missing and some can be repeated. This is a
 *             tricky solution to think of where we redcue time complexity to
 *             O(n) and space complexity to O(1). The idea is to use the same
 *             array which we iterate to store the frequencies of elements but
 *             we store frequencies as negatives to differentiate them from
 *             normal numbers. We loop through the array and for every element
 *             we encounter 2 conditions, one that the current element is > 0 &
 *             second that the element is <= 0. For the first condition we know
 *             that this is an element so we go to (elem - 1) position in array
 *             and see if it is <= 0 which if it is we just decrement that
 *             position indicating we found another one of current value (elem)
 *             otherwise we set (elem - 1) to -1 (Indicates only 1 of such value
 *             is found until now) and as for the value that was initially
 *             present here we put that in place of the current ith value that
 *             we just processed so we can process this ith element again with
 *             the new value.
 *
 * @param      arr   The array
 * @param[in]  size  The size of array
 */
void getFrequencyCountFromOneToNOptimized(int *arr, int size) {
   int i = 0;

   while (i < size) {
      if (arr[i] <= 0) {
         i++;
         continue;
      }
      int indexToUpdate = arr[i] - 1;

      if (arr[indexToUpdate] > 0) {
         arr[i]             = arr[indexToUpdate];
         arr[indexToUpdate] = -1;
      } else {
         arr[indexToUpdate]--;
         arr[i] = 0;
         i++;
      }
   }

   for (int i = 0; i < size; i++) {
      cout << i + 1 << " => " << -arr[i] << endl;
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
      getFrequencyCountFromOneToNOptimized(arr, size);
      cout << endl;
   }
   return (0);
}
