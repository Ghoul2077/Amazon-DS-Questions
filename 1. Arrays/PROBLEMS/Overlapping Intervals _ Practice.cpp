#include <bits/stdc++.h>
using namespace std;

typedef long long unsigned int bigInt;
#define mod 1000000007;
#define deb(x) cout << # x << " = " << x << endl;
#define deb2(x, \
             y) cout << # x << " = " << x << ", " << # y << " = " << y << endl;
#define printArr(arr, size) cout << # arr << " : "; \
   for (int i = 0; i < size; i++) cout << arr[i] << " "; cout << endl;

bool comparator(pair<int, int>a, pair<int, int>b) {
   return (a.first < b.first);
}

/**
 * @brief      Given an array of integer pairs, we need to merge overlapping
 *             intervals. The idea we use is to first sort the array on the
 *             basis of the first element and then we need to just loop through
 *             the array maintaining a start and stop variable where we store
 *             which we keep updating based on the condition whether current and
 *             previous intervals are overlapping or not by checking if the
 *             starting of the current interval is smaller than the ending of
 *             the previous interval. This way whenever the condition fails we
 *             will know that we have covered a merged interval and we just push
 *             the pair of start and stop uptill now to the result array and
 *             update the start and stop to the current pair value. It's time
 *             complexity is O(nlogn) and it's space complexity is O(n).
 *
 * @param[in]  vec   The vector of pairs
 * @param[in]  size  The size of vector
 */
void mergeOverlappingInterval(vector<pair<int, int> >vec, int size) {
   sort(vec.begin(), vec.end(), comparator);
   vector<pair<int, int> > res;
   int start = vec[0].first, stop = vec[0].second;

   for (int i = 1; i < size; i++) {
      if (vec[i].first <= stop) {
         stop = max(stop, vec[i].second);
      } else {
         res.push_back(make_pair(start, stop));
         start = vec[i].first;
         stop  = vec[i].second;
      }
   }

   res.push_back(make_pair(start, stop));

   for (int i = 0; i < res.size(); i++) {
      cout << res[i].first << "," << res[i].second << "  ";
   }
}

int main() {
   int testCases;

   srand(time(0));
   cin >> testCases;
   cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

   for (int i = 0; i < testCases; i++) {
      vector<pair<int, int> > v;
      int size;
      cin >> size;

      for (int i = 0; i < size; i++) {
         int val1, val2;
         cin >> val1;
         cin >> val2;
         v.push_back(make_pair(val1, val2));
      }
      mergeOverlappingInterval(v, size);
      cout << endl;
   }
   return (0);
}
