#include <iostream>
#include <map>

using namespace std;

class Solution
{
public:
  bool dup(string s, int str_len)
  {
    map<char, int> char_;
    for (int i = 0; i < str_len; i++)
    {
      if (char_.find(s[i]) == char_.end())
      {
        char_.insert({s[i], 1});
      }
      else
      {
        char_.at(s[i])++;
        if (char_.at(s[i]) > 1)
          return true;
      }
    }
    return false;
  }

  int lengthOfLongestSubstring(string s)
  {
    int longest = 0;
    int str_len = s.length();

    if (str_len == 0)
      return 0;

    if (str_len == 1)
      return 1;

    for (int i = 0; i < str_len; i++)
    {
      for (int j = 0; j < str_len; j++)
      {
        string sub = s.substr(i, j - i + 1);
        int sublen = sub.length();

        if (!dup(sub, sublen))
        {
          longest = max(sublen, longest);
        }
      }
    }
    return longest;
  }
};

int main(int argc, char const *argv[])
{
  Solution sol;
  cout << sol.lengthOfLongestSubstring("wllxdiklosdrdxfohgwringzefwbytmwgxtjhdxwycpbawphcnbmajmeokhoftlmsexakuyixplxmagoojdospvjbcxh");
  return 0;
}
