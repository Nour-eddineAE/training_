#include <iostream>
#include <set>

using namespace std;

class Solution
{
public:
  int lengthOfLongestSubstring(string s)
  {
    int str_len = s.length();

    if (str_len == 0)
      return 0;

    if (str_len == 1)
      return 1;

    int longest = 0;

    for (int i = 0; i < str_len; i++)
    {
      set<char> checked;
      for (int j = i; j < str_len; j++)
      {
        if (checked.find(s[j]) != checked.end())
          break;
        else
        {
          longest = max(longest, j - i + 1);
          checked.insert(s[j]);
        }
      }
      checked.erase(s[i]);
    }
    return longest;
  }
};

int main(int argc, char const *argv[])
{
  Solution sol;
  cout << sol.lengthOfLongestSubstring("dvdf");
  return 0;
}
