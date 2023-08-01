#include <bits/stdc++.h>

using namespace std;
class Solution
{
public:
  int myAtoi(string s)
  {
    int str_len = s.length();
    long long res = 0;
    bool positive = true;
    int pt = s.find_first_of("0123456789");
    int char_pt = s.find_first_not_of(" -+0123456789");
    int sign_pt = s.find_first_of("-+");

    if (pt == string::npos)
      return 0;

    if (char_pt != string::npos && char_pt < pt)
      return 0;

    if (sign_pt != string::npos && pt - sign_pt > 1)
      return 0;

    if (pt - 1 >= 0)
    {
      positive = s[pt - 1] != '-';
    }

    while (pt < str_len)
    {
      int dig = s[pt] - '0';
      res = res * 10 + dig;
      pt++;

      if (pt < str_len && (s[pt] < '0' || s[pt] > '9'))
        break;
    }

    if (!positive)
      res = -res;

    if (res < INT_MIN)
      res = INT_MIN;
    if (res > INT_MAX)
      res = INT_MAX;

    return res;
  }
};

int main(int argc, char const *argv[])
{
  string str;
  getline(cin, str);
  Solution sol;
  cout << sol.myAtoi(str);
  return 0;
}