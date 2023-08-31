#include <bits/stdc++.h>

using namespace std;

/**
 * Print a vector of strings
 * @param {vector<string> vec}
 * @return Returns nothing
 */
void disp(vector<string> vec)
{
  for (auto str : vec)
  {
    cout << str << endl;
  }
}

/**
 * Print a vector of integers
 * @param {vector<int> vec}
 * @return Returns nothing
 */
void disp(vector<int> vec)
{
  for (auto val : vec)
  {
    cout << val << " ";
  }
  cout << endl;
}