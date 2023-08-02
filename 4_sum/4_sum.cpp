#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  void disp(vector<vector<int>> vec)
  {
    for (int i = 0; i < vec.size(); i++)
    {
      for (int j = 0; j < vec[i].size(); j++)
      {
        cout << vec[i][j] << " ";
      }
      cout << endl;
    }
    cout << "end" << endl;
  }
  vector<vector<int>> fourSum(vector<int> &vec, int target)
  {
    int size = vec.size();
    if (size < 4)
      return {};

    sort(vec.begin(), vec.end());
    vector<vector<int>> result;

    for (int i = 0; i < size - 3; i++)
    {
      if (i > 0 && vec[i] == vec[i - 1])
        continue;

      for (int j = i + 1; j < size - 2; j++)
      {
        if (j > i + 1 && vec[j] == vec[j - 1])
          continue;

        int k = j + 1;
        int l = size - 1;

        while (k < l)
        {
          long long sum = static_cast<long long>(vec[i] + vec[j]) + static_cast<long long>(vec[k] + vec[l]);

          if (sum == target)
          {
            result.push_back({vec[i], vec[j], vec[k], vec[l]});

            while (k < l && vec[k] == vec[k + 1])
              k++;
            while (k < l && vec[l] == vec[l - 1])
              l--;

            k++;
            l--;
          }
          else if (sum < target)
          {
            k++;
          }
          else
          {
            l--;
          }
        }
      }
    }

    return result;
  }
};

int main(int argc, char const *argv[])
{
  vector<int> vec = {1, 0, -1, 0, -2, 2};
  int target = 0;
  Solution sol;
  sol.disp(sol.fourSum(vec, target));
  return 0;
}