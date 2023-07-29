#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

void disp(vector<vector<int>> val)
{
  if (val.size() == 0)
  {
    cout << "[]" << endl;
    return;
  }
  for (int i = 0; i < val.size(); i++)
  {
    cout << "[";
    for (int j = 0; j < val[i].size() - 1; j++)
    {
      cout << val[i][j] << "\t";
    }
    cout << val[i][val[i].size() - 1] << "]" << endl;
  }
}

class Solution
{
public:
  vector<vector<int>> threeSum(vector<int> &nums)
  {
    set<vector<int>> temp;

    if (nums.size() == 3 && nums[0] + nums[1] + nums[2] == 0)
    {
      return {nums};
    }
    if (nums.size() <= 2)
      return {};

    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size(); i++)
    {
      cout << nums[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < nums.size() - 1; i++)
    {

      int k = nums.size() - 1;
      int j = i + 1;

      while (j < k)
      {
        if (nums[i] + nums[j] + nums[k] < 0)
          j++;

        else if (nums[i] + nums[j] + nums[k] > 0)
          k--;

        else
        {
          temp.insert({nums[i], nums[j], nums[k]});
          j++;
          k--;
        }
      }
    }
    vector<vector<int>> res(temp.begin(), temp.end());
    return res;
  }
};

int main(int argc, char const *argv[])
{
  Solution sol;
  vector<int> nums = {-4, -2, 1, -5, -4, -4, 4, -2, 0, 4, 0, -2, 3, 1, -5, 0};
  vector<vector<int>> val = sol.threeSum(nums);
  disp(val);
  // This should print
  // [-5	 1	  4]
  // [-4	 0	  4]
  // [-4	 1	  3]
  // [-2	 -2	  4]
  // [-2	 1	  1]
  // [0	   0	  0]
  return 0;
}
