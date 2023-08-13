#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  int threeSumClosest(vector<int> &nums, int target)
  {
    set<int> temp;

    if (nums.size() <= 2)
      return 0;

    if (nums.size() == 3)
      return nums[0] + nums[1] + nums[2];

    sort(nums.begin(), nums.end());

    // init diff
    int lowsest_diff = target - nums[0] - nums[1] - nums[3];

    for (int i = 0; i < nums.size() - 1; i++)
    {
      int k = nums.size() - 1;
      int j = i + 1;
      while (j < k)
      {
        int curr_diff = target - nums[i] - nums[j] - nums[k];

        if (abs(curr_diff) < abs(lowsest_diff))
          lowsest_diff = curr_diff;

        if (curr_diff > 0)
          j++;

        else if (curr_diff < 0)
          k--;

        else
        {
          j++;
          k--;
        }
      }
    }
    return target - lowsest_diff;
  }
};

int main(int argc, char const *argv[])
{
  vector<int> vec = {2, 3, 8, 9, 10};
  Solution sol;
  cout << sol.threeSumClosest(vec, 16);
  // should print 15
  return 0;
}