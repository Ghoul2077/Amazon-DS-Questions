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
 * @brief      Given an array of numbers, find the product of all numbers except
 *             every ith index. The idea here is to first calculate the product
 *             of all index except all the ones with zero value and we also
 *             calculate the number of zeroes in the array. After precomputing
 *             all these information we loop through the array and based on
 *             4 conditions we append value to the array, first condition is
 *             that the current value to exclude is 0 and there is more than 1
 *             zero then we know the product will be zero, if current value to
 *             exclude is not zero and the count of zero is more than 0 then we
 *             know again that product will be 0, if the current value to be
 *             excluded is zero and there is only 1 zero then we know that the
 *             product of rest of the numbers is one we calculated earlier with
 *             the count of zeroes and lastly if there is no zero in the array
 *             then we get the current product by dividing the total product by
 *             current value. It's time complexity is O(n) and it's space
 *             complexity is O(1).
 *
 * @param      arr   The array
 * @param[in]  size  The size of the array
 *
 * @return     Array containing product of all index except ith
 */
int* formProductArray(int *arr, int size) {
   int *productArr   = new int[size];
   int  zeroCount    = 0;
   int  totalProduct = 1;

   for (int i = 0; i < size; i++) {
      if (arr[i] != 0) {
         totalProduct *= arr[i];
      } else {
         zeroCount++;
      }
   }

   for (int i = 0; i < size; i++) {
      if ((arr[i] != 0) && (zeroCount > 0)) {
         productArr[i] = 0;
      } else if ((arr[i] == 0) && (zeroCount > 1)) {
         productArr[i] = 0;
      } else if (arr[i] == 0) {
         productArr[i] = totalProduct;
      } else {
         productArr[i] = totalProduct / arr[i];
      }
   }
   return (productArr);
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
      int *productArr = formProductArray(arr, size);
      printArr(productArr, size);
   }
   return (0);
}
