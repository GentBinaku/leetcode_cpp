#include <cmath>
#include <dbg.h>
#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  int findMin(vector<int> &nums) {
    int target = *max_element(nums.begin(), nums.end());
    int left = 0;
    int right = nums.size() - 1;
    int mid;
    int biggest_index = -1;
    while (left <= right) {
      mid = left + (right - left) / 2;
      if (nums[mid] == target) {
        biggest_index = mid;
        right = mid - 1;
      } else if (nums[mid] > target) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }
    return nums[(biggest_index + 1) % nums.size()];
  }
};

int main() {

  Solution s;
  vector<int> values = {2, 3, 4, 5, 1};
  int res = s.findMin(values);
  cout << res << endl;
  return 0;
};
