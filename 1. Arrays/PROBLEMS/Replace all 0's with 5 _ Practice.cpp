#include <bits/stdc++.h>
using namespace std;

typedef long long unsigned int bigInt;
#define mod 1000000007;
#define deb(x) cout << # x << " = " << x << endl;
#define deb2(x, \
             y) cout << # x << " = " << x << ", " << # y << " = " << y << endl;
#define printArr(arr, size) cout << # arr << " : "; \
   for (int i = 0; i < size; i++) cout << arr[i] << " "; cout << endl;


int convertZeroesToFive(int num) {
   int num2  = num;
   int count = 1;

   while (num2 > 0) {
      int currentNum = num2 % 10;

      if (currentNum == 0) {
         num += (5 * count);
      }
      num2  /= 10;
      count *= 10;
   }
   return (num);
}

int main() {
   int testCases;

   srand(time(0));
   cin >> testCases;
   cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

   for (int i = 0; i < testCases; i++) {
      int num;
      cin >> num;
      cout << convertZeroesToFive(num);
      cout << endl;
   }
   return (0);
}
