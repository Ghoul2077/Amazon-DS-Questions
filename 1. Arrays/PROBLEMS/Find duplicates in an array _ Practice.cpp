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
 * @brief      Finds a duplicates in a given array. This is a super naive method
 *             where we loop through the array and find if the current selected
 *             element has already been accounted for earlier or not, if yes
 *             then we directly jump to next iteration otherwise we loop through
 *             right side of the current selected object to find if it has any
 *             duplicates and if duplicates are found we print this number and
 *             more to next iteration. It's time complexity is O(n^2) and it's
 *             space complexity is O(1).
 *
 * @param      arr   The array
 * @param[in]  size  The size of the array
 */
void findDuplicatesSuperNaive(int *arr, int size) {
   int totalDistinctDuplicatesCount = 0;

   for (int i = 0; i < size; i++) {
      bool hasAlreadyBeenAccountedFor = false;

      for (int j = 0; j < i; j++) {
         if (arr[i] == arr[j]) {
            hasAlreadyBeenAccountedFor = true;
            break;
         }
      }

      if (hasAlreadyBeenAccountedFor) {
         continue;
      }
      int count = 1;

      for (int j = i + 1; j < size; j++) {
         if (arr[j] == arr[i]) {
            count++;
         }
      }

      if (count > 1) {
         cout << arr[i] << " ";
         totalDistinctDuplicatesCount++;
      }
   }

   if (totalDistinctDuplicatesCount == 0) {
      cout << -1;
   }
}

/**
 * @brief      Finds a duplicates in a given array. The idea of this method is
 *             to use sorting. The benefit we gain from sorting is that all the
 *             duplicate elements get arranged adjacent to each other. Now for
 *             duplicates we just needs to check that if the next of current
 *             distinct element is equal then the current element has duplicates
 *             . It's time complexity is O(nlogn) and it's space complexity is
 *             O(1).
 *
 * @param      arr   The array
 * @param[in]  size  The size of the array
 */
void findDuplicatesNaive(int *arr, int size) {
   int totalDistinctDuplicatesCount = 0;

   sort(arr, arr + size);

   for (int i = 0; i < size; i++) {
      if (arr[i] == arr[i + 1]) {
         cout << arr[i] << " ";
         totalDistinctDuplicatesCount++;
      }

      while (arr[i + 1] == arr[i]) {
         i++;
      }
   }

   if (totalDistinctDuplicatesCount == 0) {
      cout << -1;
   }
}

/**
 * @brief      Finds a duplicates in a given array. This is the most optimal
 *             solution for this problem, here we use a hashset to store
 *             distinct elements as we encounter them. If we hit a element that
 *             is already present in the hashset we know that it is duplicate
 *             hence we just print it out. It's time complexity is O(n) and it's
 *             space complexity is O(n).
 *
 * @param      arr   The array
 * @param[in]  size  The size of the array
 */
void findDuplicates(int *arr, int size) {
   unordered_map<int, int> map;

   for (int i = 0; i < size; i++) {
      map[arr[i]]++;
   }

   int totalDistinctDuplicatesCount = 0;

   for (auto i : map) {
      if (i.second > 1) {
         cout << i.first << " ";
         totalDistinctDuplicatesCount++;
      }
   }

   if (totalDistinctDuplicatesCount == 0) {
      cout << -1;
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
      findDuplicatesNaive(arr, size);
      cout << endl;
   }
   return (0);
}
