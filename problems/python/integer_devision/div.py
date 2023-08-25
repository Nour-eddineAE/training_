class Solution:
    # ?  Implementing integer division without using division, multiplication nor modulo operators
    # ? Arguments are in range of 4Bytes signed integers
    # ? If output exceeds the range, then return max or min value of signed 4Bytes int

    def divide(self, dividend: int, divisor: int) -> int:
        if divisor == 0:
            raise ArithmeticError('Division by zero.')

        q = 0
        cumulation = 0
        negative = (dividend < 0) ^ (divisor < 0)

        divisor = abs(divisor)
        dividend = abs(dividend)

        for i in range(31, -1, -1):
            if (cumulation + (divisor << i) <= dividend):
                cumulation += divisor << i
                q += 1 << i

        max_int = 2147483647
        min_int = -2147483648
        if negative:
            if -q < min_int:
                return min_int
            return -q
        if q > max_int:
            return max_int
        return q


print(Solution().divide(-10, 3))
