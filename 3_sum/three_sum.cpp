#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
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

  // Old impl, using set(doesn't allow dup values)
  vector<vector<int>> threeSum_(vector<int> &nums)
  {
    set<vector<int>> temp;

    if (nums.size() == 3 && nums[0] + nums[1] + nums[2] == 0)
    {
      return {nums};
    }
    else
      return {};

    if (nums.size() <= 2)
      return {};

    sort(nums.begin(), nums.end());

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

  vector<vector<int>> threeSum(vector<int> &nums)
  {
    int size = nums.size();
    vector<vector<int>> res;

    if (size == 3 && nums[0] + nums[1] + nums[2] == 0)
    {
      return {nums};
    }
    if (size < 3)
      return {};

    sort(nums.begin(), nums.end());

    for (int i = 0; i < size - 1; i++)
    {
      while (i > 0 && i < size - 1 && nums[i] == nums[i - 1])
      {
        i++;
      };
      int k = size - 1;
      int j = i + 1;

      while (j < k)
      {
        if (nums[i] + nums[j] + nums[k] < 0)
          j++;

        else if (nums[i] + nums[j] + nums[k] > 0)
          k--;

        else
        {
          res.push_back({nums[i], nums[j], nums[k]});

          while (j < k && nums[j] == nums[j + 1])
            j++;

          while (j < k && nums[k] == nums[k - 1])
            k--;

          j++;
          k--;
        }
      }
    }
    return res;
  }
};

int main(int argc, char const *argv[])
{
  Solution sol;
  vector<int> nums = {-4, -2, 1, -5, -4, -4, 4, -2, 0, 4, 0, -2, 3, 1, -5, 0};
  sol.disp(sol.threeSum(nums));
  // should print
  // [-5	 1	  4]
  // [-4	 0	  4]
  // [-4	 1	  3]
  // [-2	 -2	  4]
  // [-2	 1	  1]
  // [0	   0	  0]
  return 0;
}