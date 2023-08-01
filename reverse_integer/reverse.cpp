#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  int reverse(int x)
  {
    // numbers made out of one digit are reversed by definition
    if (x > -9 && x <= 9)
      return x;

    int res = 0;
    int abs_x = abs(x);

    while (abs_x > 0)
    {
      if (res * 10 + abs_x % 10 > INT_MAX)
        return 0;
      res = res * 10 + abs_x % 10;
      abs_x /= 10;
    }

    return x < 0 ? -res : res;
  }
};

int main(int argc, char const *argv[])
{
  int n;
  cin >> n;
  Solution sol;
  cout << sol.reverse(n);
  return 0;
}