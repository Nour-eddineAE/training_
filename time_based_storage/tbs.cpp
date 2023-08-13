#include <bits/stdc++.h>

using namespace std;

class TimeMap
{
public:
  // ? used by set1, get1 and get2(one map and complex key)
  map<pair<string, int>, string> key_time_to_value;

  // ? used by set2, get3 and get4(nested map)
  unordered_map<string, map<int, string>> key_to_time_to_value;

  TimeMap()
  {
  }

  void set1(string key, string value, int timestamp)
  {
    key_time_to_value[{key, timestamp}] = value;
  }

  void set2(string key, string value, int timestamp)
  {
    key_to_time_to_value[key][timestamp] = value;
  }

  // ? Brute force using iterators
  string get1(string key, int timestamp)
  {
    for (auto it = key_time_to_value.rbegin(); it != key_time_to_value.rend(); ++it)
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
    auto it = key_time_to_value.upper_bound({key, timestamp});

    if (it == key_time_to_value.begin())
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

  // ? This is so slow and memory consuming(manually implementing binary search)
  string get3(string key, int timestamp)
  {
    auto &map = key_to_time_to_value[key];

    if (map.empty())
      return "";

    auto start = map.begin();
    auto end = prev(map.end());

    // if target timestamp is less than the first saved timestamp
    if (timestamp < start->first)
      return "";

    // if target timestamp is greater than the last saved timestamp
    if (timestamp >= end->first)
      return end->second;

    while (distance(start, end) > 0)
    {
      auto mid = start;
      advance(mid, (distance(start, end)) / 2);

      if (mid->first > timestamp)
      {
        end = prev(mid);
      }
      else if (mid->first < timestamp)
      {
        start = next(mid);
      }
      else
      {
        return mid->second;
      }
    }

    if (start->first > timestamp)
      --start;

    return start->second;
  }

  // ? Best runtime(pretty much same impl as get2, but with differnt data structure, allowing better performance)
  string get4(string key, int timestamp)
  {
    if (key_to_time_to_value.count(key))
    {
      auto &map = key_to_time_to_value[key];
      auto it = map.upper_bound(timestamp);

      if (it == map.begin())
      {
        return "";
      }
      return (--it)->second;
    }
    return "";
  }
};

int main(int argc, char const *argv[])
{

  TimeMap *timeMap = new TimeMap();
  timeMap->set2("a", "high", 10);
  timeMap->set2("a", "low", 20);
  cout << timeMap->get4("a", 5) << endl;  // should print ""
  cout << timeMap->get4("a", 10) << endl; // should print "high"
  cout << timeMap->get4("a", 15) << endl; // should print "high"
  cout << timeMap->get4("a", 20) << endl; // should print "low"
  cout << timeMap->get4("a", 25) << endl; // should print "low"
  return 0;
}