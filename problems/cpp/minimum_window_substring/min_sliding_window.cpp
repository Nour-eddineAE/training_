#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  string minWindow(string s, string t)
  {
    // Immidiate break
    if (s.length() < t.length())
      return "";

    int t_chars_count[256] = {0};
    int s_chars_count[256] = {0};

    // * store frequencies of each character in t
    for (auto c : t)
    {
      t_chars_count[c]++;
    }

    int count = 0;
    int start = 0;
    int min_window_len = INT_MAX;
    int start_of_window = 0;

    for (int i = 0; i < s.length(); ++i)
    {
      // * for each character in s, we increment its frequency
      s_chars_count[s[i]]++;

      // * if frequency of the current character in t, is bigger than or equal to its frequency in s.substring(start, i - start + 1)
      // * in other words: for a given character, as long as its frequency in what we have processed of s is not yet equal to
      // * its frequency in t, we expand the window
      // ? Example: s = "this is a test string", t = "sitt", the frequency of 't' in t is 2, as long as what we
      // ? have processed of s doesn't contain 2 't's, we expand the window,
      // ? we'll stop at "this is a t" as we have all characters included
      if (t_chars_count[s[i]] >= s_chars_count[s[i]])
      {
        count++;
      }
      if (count == t.length())
      {
        // * 1) first case
        // * if frequency of the character at position start in s is greater than
        // * frequency of the same character in t, this means there will still be occurences
        // * of that character in s, so no worry if we ignore it(i.e we advance start)
        // * 2) second case
        // * if the character at position start is not in t, (its frequency is 0), we simply ignore it(increment start)
        while (s_chars_count[s[start]] > t_chars_count[s[start]] || t_chars_count[s[start]] == 0)
        {
          // * if the first case(decrement the frequency of that char as we are only interested
          // * in its frequency in the remaining substring(after start)), in other words, we slide the window forward
          if (s_chars_count[s[start]] > t_chars_count[s[start]])
            s_chars_count[s[start]]--;
          start++;
        }

        // * we check the length of the optimized window, if it's less than the length of the current minimum window,
        // * we update the current minimum length as well as the beginning og the new minimum window
        int possibe_window_len = i - start + 1;
        if (min_window_len > possibe_window_len)
        {
          min_window_len = possibe_window_len;
          start_of_window = start;
        }
      }
    }

    // * get the window based of the start index and the amount to take
    return min_window_len == INT_MAX ? "" : s.substr(start_of_window, min_window_len);
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