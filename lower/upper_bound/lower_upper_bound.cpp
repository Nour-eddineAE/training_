#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
  int n, q;
  cin >> n;

  vector<int> arr;
  arr.reserve(n);

  set<int> s;

  for (int i = 0; i < n; i++)
  {
    int temp;
    cin >> temp;
    arr.push_back(temp);
    s.insert(temp);
  }

  cin >> q;

  for (int i = 0; i < q; i++)
  {
    int query;
    cin >> query;

    auto it = s.lower_bound(query);

    if (it != s.end() && *it == query)
    {
      cout << "Yes " << (distance(arr.begin(), lower_bound(arr.begin(), arr.end(), query)) + 1) << endl;
    }
    else
    {
      cout << "No " << (distance(arr.begin(), upper_bound(arr.begin(), arr.end(), query)) + 1) << endl;
    }
  }

  return 0;
}
