#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  int area(int low, int high, int img)
  {
    return (high - low) * img;
  }

  int maxArea(vector<int> &height)
  {
    int size = height.size();

    if (size == 0 || size == 1)
      return 0;

    int high = size - 1;
    int low = 0;
    int largest = 0;

    while (high > low)
    {
      largest = max(largest, area(low, high, min(height[low], height[high])));
      if (height[low] <= height[high])
        low++;
      else if (height[low] > height[high])
        high--;
    }

    return largest;
  }
};

int main(int argc, char const *argv[])
{
  vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
  Solution sol;
  cout << sol.maxArea(height);
  // should print 49
  return 0;
}