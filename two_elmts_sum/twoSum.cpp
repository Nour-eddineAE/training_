#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  vector<int> twoSum(vector<int> &nums, int target)
  {
    unordered_map<int, int> value_index_map;
    vector<int> res;

    for (int i = 0; i < nums.size(); i++)
    {
      int diff = target - nums[i];

      if (value_index_map.count(diff))
      {
        // there should be a pair of elements in the vector, if this condition is satisfied =>
        //  we have already stored the the first part of the pair
        res.push_back(value_index_map[diff]);
        res.push_back(i);
        return res;
      }

      value_index_map[nums[i]] = i;
    }

    return res;
  }
};

int main(int argc, char const *argv[])
{
  // Sample input
  vector<int> vec = {1, 2, 5, 3};
  Solution sol;
  vector<int> sol_ = sol.twoSum(vec, 5);

  for (int i = 0; i < sol_.size(); i++)
  {
    cout << sol_.at(i) << endl;
  }

  return 0;
}
