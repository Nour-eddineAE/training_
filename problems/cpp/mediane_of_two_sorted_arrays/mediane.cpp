#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
  {
    int n = nums1.size();
    int m = nums2.size();
    int k = ((n + m - 1) / 2);
    while (k > 0)
    {
      if (nums1.size() >= 1 && nums2.size() >= 1)
      {
        if (nums1[0] <= nums2[0])
        {
          // remove first element of nums1
          nums1.erase(nums1.begin());
        }
        else
        {
          // remove first element of nums2
          nums2.erase(nums2.begin());
        }
      }

      else if (nums1.size() >= 1)
      {
        nums1.erase(nums1.begin());
      }

      else if (nums2.size() >= 1)
      {
        nums2.erase(nums2.begin());
      }

      k -= 1;
    }

    int leftA = nums1.size() >= 1 ? nums1[0] : INT_MAX;
    int leftB = nums2.size() >= 1 ? nums2[0] : INT_MAX;
    int rightA = nums1.size() >= 2 ? nums1[1] : INT_MAX;
    int rightB = nums2.size() >= 2 ? nums2[1] : INT_MAX;

    if ((n + m) % 2 == 0)
    {
      // take the two smallest among th 4 number(represent the mediane when n+m is even)
      int temp[4] = {leftA, rightA, leftB, rightB};
      sort(temp, temp + 4);
      return (temp[0] + temp[1]) / 2.0;
    }

    return min(leftA, leftB);
  }
};

int main(int argc, char const *argv[])
{
  vector<int> vec1 = {};
  vector<int> vec2 = {1, 2, 3, 4};
  Solution sol;
  cout << sol.findMedianSortedArrays(vec1, vec2);
  // should print 2.5
  return 0;
}