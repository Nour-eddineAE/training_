#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  void disp(vector<string> vec)
  {
    for (auto str : vec)
    {
      cout << str << endl;
    }
  }

  // ? Using recursion(invalid combs are counted)
  bool isValidComb(string s)
  {
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
      if (s[i] == ')')
      {
        if (st.empty())
          return false;
        if (st.top() == '(')
          st.pop();
        else
          return false;
      }

      else
        st.push(s[i]);
    }

    return st.empty();
  }

  void generateCombinations(int n, string current, vector<string> &result)
  {
    if (n == 0)
    {
      if (isValidComb(current))
        result.push_back(current);
      return;
    }

    generateCombinations(n - 1, current + "(", result);
    generateCombinations(n - 1, current + ")", result);
  }

  vector<string> generateParenthesis(int n)
  {
    vector<string> combinations;
    generateCombinations(2 * n, "", combinations);
    return combinations;
  }

  // ? Using dynamic programming(builds only valid combs => better runtime and effecient use of space )
  vector<string> _generateParenthesis(int n)
  {
    if (n == 0)
    {
      return {};
    }

    vector<vector<string>> combs_build(n + 1);
    combs_build[0] = {""};

    for (int i = 1; i <= n; ++i)
    {
      for (int j = 0; j < i; ++j)
      {
        for (const string &left : combs_build[j])
        {
          for (const string &right : combs_build[i - j - 1])
          {
            combs_build[i].push_back("(" + left + ")" + right);
          }
        }
      }
    }

    return combs_build[n];
  }
};

int main(int argc, char const *argv[])
{
  Solution sol;
  sol.disp(sol.generateParenthesis(3));
  sol.disp(sol._generateParenthesis(3));
  // both should print: ()()() ()(()) (())() (()()) ((()))
  return 0;
}