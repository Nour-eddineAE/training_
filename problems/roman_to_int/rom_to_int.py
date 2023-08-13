# a trivial way is to use cases, but the approach is long 

# 2nd approach

class Solution:
    def romanToInt(self, s: str) -> int:
        roman_to_int = {
            'I': 1,
            'V': 5,
            'X': 10,
            'L': 50,
            'C': 100,
            'D': 500,
            'M': 1000
        }

        num = 0
        prev_value = 0

        for char in s:
            value = roman_to_int[char]
            if value > prev_value:
                num += value - 2 * prev_value
            else:
                num += value
                
            prev_value = value

        return num

print(Solution().romanToInt("CMDLXIV"))
# should print 1464