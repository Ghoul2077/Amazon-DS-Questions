#include <bits/stdc++.h>
using namespace std;

typedef long long unsigned int bigInt;
#define mod 1000000007;
#define deb(x) cout << # x << " = " << x << endl;
#define deb2(x, \
             y) cout << # x << " = " << x << ", " << # y << " = " << y << endl;
#define printArr(arr, size) cout << # arr << " : "; \
   for (int i = 0; i < size; i++) cout << arr[i] << " "; cout << endl;


int lomutoPartition(int *arr, int size, int start, int stop) {
   int pivot = arr[stop];
   int i     = -1;

   for (int j = 0; j <= stop; j++) {
      if (arr[j] <= pivot) {
         swap(arr[++i], arr[j]);
      }
   }

   return (i);
}

int findThirdLargestElementNaive(int *arr, int size) {
   priority_queue<int> maxHeap;

   for (int i = 0; i < size; i++) {
      maxHeap.push(arr[i]);
   }

   for (int i = 0; i < 2; i++) {
      if (maxHeap.size() > 0) {
         maxHeap.pop();
      }
   }
   return (maxHeap.size() > 0 ? maxHeap.top() : -1);
}

int findThirdLargestElement(int *arr, int size) {
   int start = 0, stop = size - 1;

   while (start <= stop) {
      int correctedIndex = lomutoPartition(arr, size, start, stop);

      if (correctedIndex == 2) {
         return (arr[correctedIndex]);
      } else if (correctedIndex < 3) {
         start = correctedIndex + 1;
      } else {
         stop = correctedIndex - 1;
      }
   }

   return (-1);
}

int findThirdLargestElementOptimized(int *arr, int size) {
   int largest = arr[0], secondLargest = -1, thirdLargest = -1;

   for (int i = 1; i < size; i++) {
      if (arr[i] > largest) {
         thirdLargest  = secondLargest;
         secondLargest = largest;
         largest       = arr[i];
      } else if ((arr[i] > secondLargest) || (secondLargest == -1)) {
         thirdLargest  = secondLargest;
         secondLargest = arr[i];
      } else if ((arr[i] > thirdLargest) || (thirdLargest == -1)) {
         thirdLargest = arr[i];
      }
   }

   return (thirdLargest);
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
      cout << findThirdLargestElementOptimized(arr, size);
      cout << endl;
   }
   return (0);
}
