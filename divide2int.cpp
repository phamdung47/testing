/*
LeetCode Problems #29. Divide Two Integers

Given two integers dividend and divisor, divide two integers without using
multiplication, division, and mod operator.

The integer division should truncate toward zero, which means losing its
fractional part. For example, 8.345 would be truncated to 8, and -2.7335 would
be truncated to -2.

Return the quotient after dividing dividend by divisor.

Note: Assume we are dealing with an environment that could only store integers
within the 32-bit signed integer range: [-231, 231 - 1]. For this problem, if
the quotient is strictly greater than 2^31 - 1, then return 2^31 - 1, and if
the quotient is strictly less than -2^31, then return -2^31.

Example 1:
    Input: dividend = 10, divisor = 3
    Output: 3
    Explanation: 10/3 = 3.33333.. which is truncated to 3.

Example 2:
    Input: dividend = 7, divisor = -3
    Output: -2
    Explanation: 7/-3 = -2.33333.. which is truncated to -2.

Constraints:
    -2^31 <= dividend, divisor <= 2^31 - 1
    divisor != 0
	
Success Details >

Runtime: 0 ms, faster than 100.00% of C++ online submissions for Divide Two Integers.

Memory Usage: 5.9 MB, less than 28.04% of C++ online submissions for Divide Two Integers.

*/

#include <stdio.h>
#include <stdlib.h>

class Solution {
public:
    int divide(int dividend, int divisor) {
        int sign=1, quotient=0;
        if (divisor == 1)
            return dividend;
        if (divisor == -1) {
            if (dividend == 2147483647)
                return -2147483648;
            if (dividend == -2147483648)
                return 2147483647;
			return -dividend;
        }
        if (dividend == 0 || divisor == 0)
			return 0;
		if (divisor == 2147483647)
			return (dividend == 2147483647 ? 1 : (dividend == -2147483648 ? -1 : 0));
		if (divisor == -2147483648)
            return (dividend == -2147483648 ? 1 : (dividend == 2147483647 ? 0 : 0));
        if (divisor < 0) {
            sign = -sign;
            divisor = -divisor;
        }
        if (dividend > 0) {
            while (dividend >= divisor) {
                int shift = 0, t;
                while ((t = (divisor << shift)) > 0 && t <= dividend)
                    shift += 1;
                quotient += (1 << (shift - 1));
                dividend -= divisor << (shift - 1);
            }
        }
        else {
            sign = -sign;
            while (dividend <= -divisor) {
                int shift = 0, t;
                while ((t = (divisor << shift)) > 0 && -t >= dividend)
                    shift += 1;
                quotient += (1 << (shift - 1));
                dividend += divisor << (shift - 1);
            }
        }
        return (sign == -1 ? -quotient : quotient);
    }
};

//----------------------------------------------------------------------------
// Main
//----------------------------------------------------------------------------
#if 1
int main() {
    struct {
        int dividend;
        int divisor;
        int answer;
    } in[] = {
		{2147483647, -2147483648, 0},
		{2147483647, 2147483647, 1},
		{-1010369383, -2147483648, 0},
		/*
        {2147483647, 3, 715827882},
        {2, 2, 1},
        {1, -1, -1},
        {10, 3, 3},
        {7, -3, -2},
        {0, 1, 0},
        {1, 1, 1},
        {253, 7, 36},
        {-2147483648, 2, -1073741824},
        {2147483647, 2, 1073741823},
        {2147483647, 1, 2147483647},
        {-2147483647, 2, -1073741823},
        {-2147483648, 1, -2147483648},
        {-2147483648, -1, 2147483647},
		*/
    };

    Solution sol;
    int cnt = sizeof(in)/sizeof(in[0]);
    for (int i=0; i < cnt; i++) {
        int quotient = sol.divide(in[i].dividend, in[i].divisor);
        printf("%d / %d = %d  <%s>\n", in[i].dividend, in[i].divisor,
               quotient, (quotient == in[i].answer ? "correct" : "wrong"));
    }
    return 0;
}
#endif
