#include <bits/stdc++.h>
using namespace std;

typedef long long unsigned int bigInt;
#define mod 1000000007;
#define deb(x) cout << # x << " = " << x << endl;
#define deb2(x, \
             y) cout << # x << " = " << x << ", " << # y << " = " << y << endl;
#define printArr(arr, size) cout << # arr << " : "; \
   for (int i = 0; i < size; i++) cout << arr[i] << " "; cout << endl;


vector<int>findSortedSubsequenceOfSize3Naive(int *arr, int size) {
   for (int i = 0; i < size; i++) {
      vector<int> res;
      res.push_back(arr[i]);

      for (int j = i + 1; j < size; j++) {
         if (res.size() == 3) {
            break;
         }

         if (arr[j] > res.back()) {
            res.push_back(arr[j]);
         }
      }

      if (res.size() == 3) {
         return (res);
      }
   }
   return {};
}

vector<int>findSortedSubsequenceOfSize3(int *arr, int size) {
   int *smallerToTheLeft          = new int[size];
   int  runningIndexOfSmallestVal = 0;

   smallerToTheLeft[0] = -1;

   for (int i = 1; i < size; i++) {
      if (arr[i] <= arr[runningIndexOfSmallestVal]) {
         smallerToTheLeft[i]       = -1;
         runningIndexOfSmallestVal = i;
      } else {
         smallerToTheLeft[i] = runningIndexOfSmallestVal;
      }
   }

   int *greaterToTheRight                  = new int[size];
   int  runningIndexOfGreatestValFromRight = size - 1;

   greaterToTheRight[size - 1] = -1;

   for (int i = size - 2; i >= 0; i--) {
      if (arr[i] >= arr[runningIndexOfGreatestValFromRight]) {
         greaterToTheRight[i]               = -1;
         runningIndexOfGreatestValFromRight = i;
      } else {
         greaterToTheRight[i] = runningIndexOfGreatestValFromRight;
      }
   }

   vector<int> res;

   for (int i = 0; i < size; i++) {
      if ((greaterToTheRight[i] != -1) && (smallerToTheLeft[i] != -1)) {
         res.push_back(arr[smallerToTheLeft[i]]);
         res.push_back(arr[i]);
         res.push_back(arr[greaterToTheRight[i]]);
         return (res);
      }
   }

   return (res);
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

      vector<int> res = findSortedSubsequenceOfSize3(arr, size);
      cout << (res.size() > 0 ? 1 : 0);
      cout << endl;
   }
   return (0);
}
