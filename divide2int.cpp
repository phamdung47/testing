/*
LeetCode Problems #29. Divide Two Integers

Given two integers dividend and divisor, divide two integers without using 
multiplication, division, and mod operator.

The integer division should truncate toward zero, which means losing its 
fractional part. For example, 8.345 would be truncated to 8, and -2.7335 would
be truncated to -2.

Return the quotient after dividing dividend by divisor.

Note: Assume we are dealing with an environment that could only store integers
within the 32-bit signed integer range: [−231, 231 − 1]. For this problem, if
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

*/
#include <iostream>

class Solution {
public:
    int divide(int dividend, int divisor) {
        return 0;
    }
};

#if 0
//----------------------------------------------------------------------------
// Main
//----------------------------------------------------------------------------
int main() {
    struct {
        int dividend;
        int divisor;
        int answer;
    } in[] = {
        {10, 3, 3},
        {7, -3, -2},
    };
    Solution sol;
    int cnt = sizeof(in)/sizeof(in[0]);
    
    for (int i=0; i < cnt; i++) {
        int quotient = sol.divide(in[i].dividend, in[i].divisor);
        printf("%d / %d = %d %s\n", in[i].dividend, in[i].divisor,
               quotient, (quotient == in[i].answer ? "correct" : "wrong"));
    }
    return 0;
}
#endif
