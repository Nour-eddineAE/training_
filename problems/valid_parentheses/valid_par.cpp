#include <iostream>
#include <stack>

using namespace std;

class Solution
{
public:
  bool isValid(string s)
  {
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
      switch (s[i])
      {
      case ']':
        if (st.empty())
          return false;
        if (st.top() == '[')
          st.pop();
        else
          return false;
        break;

      case ')':
        if (st.empty())
          return false;
        if (st.top() == '(')
          st.pop();
        else
          return false;
        break;

      case '}':
        if (st.empty())
          return false;
        if (st.top() == '{')
          st.pop();
        else
          return false;
        break;

      default:
        st.push(s[i]);
        break;
      }
    }

    return st.empty();
  }
};

int main(int argc, char const *argv[])
{
  Solution sol;
  string str = "[(){}]";
  cout << "Is " << str << " valid? " << sol.isValid(str);
  // should print true
  return 0;
}