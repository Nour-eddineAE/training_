#include <bits/stdc++.h>

using namespace std;
class Solution
{
public:
  map<int, string> dig_to_str = {
      {2, "abc"},
      {3, "def"},
      {4, "ghi"},
      {5, "jkl"},
      {6, "mno"},
      {7, "pqrs"},
      {8, "tuv"},
      {9, "wxyz"},
  };

  void disp(vector<string> vec)
  {
    for (int i = 0; i < vec.size(); i++)
    {
      cout << vec[i] << endl;
    }
  }

  void generateCombinations(const string &digits, int index, string &comb, vector<string> &res)
  {
    if (index == digits.length())
    {
      res.push_back(comb);
      return;
    }

    int digit = digits[index] - '0';
    const string chars = dig_to_str.at(digit);

    for (int i = 0; i < chars.length(); i++)
    {
      comb.push_back(chars[i]);
      generateCombinations(digits, index + 1, comb, res);
      comb.pop_back();
    }
  }

  vector<string> letterCombinations(string digits)
  {
    int str_len = digits.length();
    vector<string> res = {};

    if (str_len == 0)
      return res;

    string comb;

    generateCombinations(digits, 0, comb, res);

    return res;
  }
};

int main(int argc, char const *argv[])
{
  string digits;
  getline(cin, digits);
  Solution sol;
  sol.disp(sol.letterCombinations(digits));
  return 0;
}