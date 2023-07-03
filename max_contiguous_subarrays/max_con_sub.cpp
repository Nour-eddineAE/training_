#include <iostream>
#include <deque>
using namespace std;

#include <iostream>
#include <deque>
using namespace std;

void printKMax(int arr[], int n, int k)
{
  deque<pair<int, int>> dq;

  // get the max of the first subarray
  for (int i = 0; i < k; i++)
  {
    while (!dq.empty() && dq.back().first < arr[i])
    {
      dq.pop_back();
    }
    dq.push_back({arr[i], i});
  }

  cout << dq.front().first << " ";

  // For each of the other subarrays
  for (int i = 1; i < n - k + 1; i++)
  {
    // Remove elements outside the current subarray
    while (!dq.empty() && dq.front().second <= i - 1)
    {
      dq.pop_front();
    }

    // Add the new element to the deque
    while (!dq.empty() && dq.back().first < arr[i + k - 1])
    {
      dq.pop_back();
    }
    dq.push_back({arr[i + k - 1], i + k - 1});

    cout << dq.front().first << " ";
  }

  cout << endl;
}

int main()
{

  int t;
  cin >> t;
  while (t > 0)
  {
    int n, k;
    cin >> n >> k;
    int i;
    int arr[n];
    for (i = 0; i < n; i++)
      cin >> arr[i];
    printKMax(arr, n, k);
    t--;
  }
  return 0;
}