#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  double recursive_pow(double x, int n)
  {
    long long abs_n = abs(static_cast<long long>(n));

    if (abs_n == 1)
      return n < 0 ? 1 / x : x;

    if (abs_n == 0)
      return 1;

    double pow = recursive_pow(x, abs_n / 2);
    pow *= pow;

    if (abs_n % 2 == 1)
      pow *= x;

    return n < 0 ? 1 / pow : pow;
  }

  double binary_search_power(double x, int n)
  {
    int abs_n = abs(n);
    if (n == 0)
      return 1;

    double pow = 1;

    while (abs_n > 0)
    {
      if (abs_n % 2 == 1)
      {
        pow *= x;
      }
      x *= x;
      abs_n /= 2;
    }

    return n < 0 ? 1 / pow : pow;
  }
};

int main(int argc, char const *argv[])
{
  double x;
  int n;
  cin >> x >> n;
  Solution sol;
  cout << "recursive calls: " << sol.recursive_pow(x, n) << endl;
  cout << "binary search: " << sol.binary_search_power(x, n) << endl;

  // Both should give the same power
  return 0;
}