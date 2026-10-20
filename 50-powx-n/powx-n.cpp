class Solution {
public:
    double myPow(double x, int n) {
        long long binform = n;
        bool neg = false;
        if (binform < 0) {
            neg = true;
            binform = -binform;
        }
        double ans = 1.0;
        while (binform > 0) {
            if (binform % 2 == 1) {
                ans *= x;
            }
            x *= x;
            binform /= 2;
        }
        return neg ? 1.0 / ans : ans;
    }
};