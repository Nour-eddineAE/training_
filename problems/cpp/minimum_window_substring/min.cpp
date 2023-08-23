#include <bits/stdc++.h>

using namespace std;

/*
 * Binary search(on window length)
 * if window of length mid contains all chars of t, then we check a sub window
 * if window of length mid doesn't contain all chars, we cheack a larger window
 */
class Solution
{
public:
  /**
   * Check wether any substring of length mid has all the characters in t
   */
  bool checkAllCharsExist(string &s, string &t, int mid, int &start)
  {
    int count_frequency[256] = {0};

    int distinct_occurences = 0;

    bool found = false;

    // Count the frequency of each character in t
    for (char c : t)
    {
      count_frequency[c]++;
      if (count_frequency[c] == 1)
        distinct_occurences++;
    }

    // Stores the number of charcters in a substring of size
    // mid in s whose frequency is same as frequency in t
    int curr_count = 0;
    for (int i = 0; i < s.size(); i++)
    {
      count_frequency[s[i]]--;
      if (count_frequency[s[i]] == 0)
      {
        curr_count++;
      }
      if (i >= mid)
      {
        count_frequency[s[i - mid]]++;
        if (count_frequency[s[i - mid]] == 1)
        {
          curr_count--;
        }
      }
      if (i >= mid - 1)
      {

        // Found window
        if (curr_count == distinct_occurences)
        {

          found = true;

          // Starting index of the found window
          start = (i - mid) + 1;
          break;
        }
      }
    }

    return found;
  }

  string minWindow(string s, string t)
  {
    if (s.length() < t.length())
      return "";

    int high = s.length(), low = 1, lowest_index = 0, minLength = INT_MAX;

    while (low <= high)
    {
      int mid = (high + low) / 2;
      int start;
      // check all intervals of size mid
      if (checkAllCharsExist(s, t, mid, start))
      {
        // if window_size less than current min_window_size, we update
        if (mid < minLength)
        {
          minLength = mid;
          lowest_index = start;
        }
        high = mid - 1;
      }
      else
      {
        low = mid + 1;
      }
    }

    // * when nothing found
    if (minLength == INT_MAX)
      return "";

    return s.substr(lowest_index, minLength);
  }
};

int main(int argc, char const *argv[])
{

  string s, t;
  getline(cin, s);
  getline(cin, t);

  Solution sol;

  cout << sol.minWindow(s, t) << endl;
  return 0;
}