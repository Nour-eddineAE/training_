#include <bits/stdc++.h>

using namespace std;

/**
 * Print a 2D vector of strings
 * @param {vector<vector<string>> vec}
 * @return Returns nothing
 */
void disp(vector<vector<string>> vec)
{
  for (auto strs : vec)
  {
    for (auto str : strs)
      cout << str << " ";
    cout << endl;
  }
}
