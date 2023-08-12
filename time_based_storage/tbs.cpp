#include <bits/stdc++.h>

using namespace std;

class TimeMap
{
public:
  map<pair<string, int>, string> key_val_time;

  TimeMap() {}

  void set(string key, string value, int timestamp)
  {
    key_val_time[{key, timestamp}] = value;
  }

  // ? Brute force using iterators
  string get1(string key, int timestamp)
  {
    for (auto it = key_val_time.rbegin(); it != key_val_time.rend(); ++it)
    {
      if (it->first.first == key && it->first.second <= timestamp)
      {
        return it->second;
      }
    }
    return "";
  }

  // ? This thing uses the fact that we used a map(sorted elements), but it's quite slower, idk how it passed
  string get2(string key, int timestamp)
  {
    auto it = key_val_time.upper_bound({key, timestamp});

    if (it == key_val_time.begin())
    {
      return "";
    }

    --it;

    if (it->first.first != key)
    {
      return "";
    }

    return it->second;
  }

  // TODO: try using binary search
};

int main(int argc, char const *argv[])
{
  TimeMap *timeMap = new TimeMap();
  timeMap->set("a", "bar", 1);
  timeMap->set("x", "b", 3);
  cout << timeMap->get1("b", 3) << endl; // should print b
  timeMap->set("foo", "bar2", 4);
  cout << timeMap->get1("foo", 4) << endl; // should print bar2
  cout << timeMap->get1("foo", 5) << endl; // should print bar2
  return 0;
}