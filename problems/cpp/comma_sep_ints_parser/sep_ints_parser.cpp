#include <sstream>
#include <vector>
#include <iostream>
#include <string>
using namespace std;

vector<int> parseInts(string str)
{
  vector<int> parsedInts;
  size_t commaPos = str.find_first_of(',');
  while (commaPos != string::npos)
  {
    int parsedInt = stoi(str.substr(0, commaPos));
    parsedInts.push_back(parsedInt);
    str = str.substr(commaPos + 1);
    commaPos = str.find_first_of(',');
  }
  parsedInts.push_back(stoi(str));
  return parsedInts;
}

int main()
{
  string str;
  cin >> str;
  vector<int> integers = parseInts(str);
  for (int i = 0; i < integers.size(); i++)
  {
    cout << integers[i] << endl;
  }

  return 0;
}