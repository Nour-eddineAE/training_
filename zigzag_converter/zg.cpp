#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  // here's the lazy approach(what i always start with)
  string convert_(string s, int numRows)
  {
    if (numRows == 1)
      return s;
    vector<string> chars;
    chars.resize(numRows);
    int col = 0;
    int index = 0;
    while (index < s.length())
    {
      for (int i = 0; i < numRows; i++)
      {
        if ((col / (numRows - 1) + col) % numRows == 0)
        {
          chars[i] += s[index];
          // s.erase(0, 1);
          index++;
        }
        else
        {
          if (col % (numRows - 1) == numRows - i - 1)
          {
            chars[i] += s[index];
            index++;
          }
          else
            chars[i] += " ";
        }
        if (index >= s.length())
          break;
      }
      col++;
    }

    string res = "";
    for (int i = 0; i < chars.size(); i++)
    {
      for (int j = 0; j < chars[i].length(); j++)
      {
        if (chars[i][j] != ' ')
          res += chars[i][j];
      }
    }
    return res;
  }

  // here's a better approach
  string convert(string s, int numRows)
  {
    if (numRows == 1 || s.length() <= numRows)
      return s;

    string res;
    int cycleLen = 2 * numRows - 2;

    for (int i = 0; i < numRows; i++)
    {
      for (int j = i; j < s.length(); j += cycleLen)
      {
        res += s[j];

        if (i != 0 && i != numRows - 1)
        {
          int diagIdx = j + cycleLen - 2 * i;

          if (diagIdx < s.length())
          {
            res += s[diagIdx];
          }
        }
      }
    }

    return res;
  }
};

int main(int argc, char const *argv[])
{
  string s;
  int n;
  getline(cin, s);
  cin >> n;
  Solution sol;
  cout << sol.convert(s, n);
  return 0;
}