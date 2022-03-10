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
 * @brief      Finds distinct intersecting elements from given 2 arrays. The
 *             idea is to use hashsets to get distinct elements of both of the
 *             arrays. Now we just loop through any one of the set and count
 *             how many of it's elements are present in the second hashset. It's
 *             time complexity is O(m+n) and it's space complexity is O(m+n).
 *
 * @param      arr1   The array 1
 * @param[in]  size1  The size of array 1
 * @param      arr2   The array 2
 * @param[in]  size2  The size of array 2
 */
void findIntersectingElementsFrom2Arrays(int *arr1,
                                         int  size1,
                                         int *arr2,
                                         int  size2) {
   unordered_set<int> set1(arr1, arr1 + size1);
   unordered_set<int> set2(arr2, arr2 + size2);
   int count = 0;

   for (auto i : set1) {
      if (set2.count(i) == 1) {
         count++;
      }
   }
   cout << count;
}

/**
 * @brief      Finds distinct intersecting elements from given 2 arrays. The
 *             idea is to use hashset to get distinct elements of any one of the
 *             arrays (preferrable the smaller one), then we loop through the
 *             second array and see if the current element is present in the
 *             hashset or not. If the element is present in the hashset then we
 *             increase the value of count variable and then we also remove that
 *             element from the hashset so as to not count it again. It's time
 *             complexity is O(m + n) and it's space complexity is O(min(m,n)).
 *
 * @param      arr1   The array 1
 * @param[in]  size1  The size of array 1
 * @param      arr2   The array 2
 * @param[in]  size2  The size of array 2
 */
void findIntersectingElementsFrom2ArraysOptimized(int *arr1,
                                                  int  size1,
                                                  int *arr2,
                                                  int  size2) {
   unordered_set<int> set(arr1, arr1 + size1);
   int count = 0;

   for (int i = 0; i < size2; i++) {
      if (set.count(arr2[i]) == 1) {
         set.erase(arr2[i]);
         count++;
      }
   }
   cout << count;
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
      findIntersectingElementsFrom2Arrays(arr1, size1, arr2, size2);
      cout << endl;
   }
   return (0);
}
