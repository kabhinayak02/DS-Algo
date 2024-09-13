/*
[-2147483648, 2147483647]
INT_MAX = 2147483647,
INT_MIN = -2147483648

INT_MAX/10 = 214748364
INT_MIN/10 = -214748364

Now check with INT_MAX/10 and INT_MIN/10 before adding temp to rev.

tc: O(log10(x))
sc: O(1)
*/
class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        while (x != 0) {
            int temp = x % 10;
            x /= 10;
            if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && temp > 7)) {
                return 0;
            }
            if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && temp < -8)) {
                return 0;
            }
            rev = rev * 10 + temp;
        }
        return rev;
    }
};