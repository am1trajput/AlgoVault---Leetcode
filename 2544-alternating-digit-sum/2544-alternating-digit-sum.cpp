class Solution {
public:
    int alternateDigitSum(int n) {
        int reverse = 0;
        while(n > 0) {
            int digit = n % 10;
            reverse = reverse * 10 + digit;
            n = n / 10;
        }
        int ans = 0;
        int sign = 1;
        while(reverse > 0) {
            int digit = reverse % 10;
            ans += sign * digit;
            reverse = reverse / 10;
            sign *= -1;
        }

        return ans;
    }
};