#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  map<int, char> int_rom = {
      {1, 'I'},
      {5, 'V'},
      {10, 'X'},
      {50, 'L'},
      {100, 'C'},
      {500, 'D'},
      {1000, 'M'},
  };

  string intToRoman_(int num)
  {
    // My 100 lines approach
    int mod = 10;
    int prev = 0;
    string res = "";
    int index = 0;
    while (num % (mod / 10) != num)
    {
      int to_convert = (num % mod) - prev;
      prev = (num % mod);

      if (mod <= 1000)
      {
        int step = mod / 10;

        if (to_convert == 0)
        {
          mod *= 10;
          continue;
        }

        else if (to_convert <= 3 * step && to_convert > 0)
          while (to_convert > 0)
          {
            res = int_rom.at(step) + res;
            to_convert -= step;
          }

        else if (to_convert == 4 * step)
        {
          res = int_rom.at(5 * step) + res;
          res = int_rom.at(step) + res;
        }

        else if (to_convert >= (5 * step) && to_convert < (9 * step))
        {
          int to_add = to_convert % (5 * step);
          cout << "toadd: " << to_add << endl;
          while (to_add > 0)
          {
            res = int_rom.at(step) + res;
            to_add -= step;
          }
          res = int_rom.at(5 * step) + res;
        }

        else
        {
          res = int_rom.at(10 * step) + res;
          res = int_rom.at(step) + res;
        }

        cout << "index: " << index << " mod: " << mod << " num_mod: " << num % mod << " result: " << res << endl;
        index++;
      }
      else
      {
        int thousands = num / (mod / 10);
        cout << "mod: " << mod << " thousands: " << thousands << endl;
        while (thousands > 0)
        {
          res = int_rom.at(1000) + res;
          thousands--;
        }

        return res;
      }

      mod *= 10;
    }
    return res;
  }

  // a way clever way and more hard coding
  string intToRoman(int num)
  {
    string ones[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
    string tens[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
    string hrns[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
    string ths[] = {"", "M", "MM", "MMM"};

    return ths[num / 1000] + hrns[(num % 1000) / 100] + tens[(num % 100) / 10] + ones[num % 10];
  }
};

int main(int argc, char const *argv[])
{
  int num;
  cin >> num;
  Solution sol;
  cout << sol.intToRoman(num);
  return 0;
}