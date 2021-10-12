//两数相除
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0)
            return 0;
        if (divisor == 1)
            return dividend;
        if (divisor == -1)
        {
            if (dividend > INT_MIN)
                return -dividend;
            return INT_MAX;
        }
        int sign = 1;
        long a = dividend, b = divisor;
        if ((a < 0 && b > 0) || (a > 0 && b < 0))
            sign = -1;
        a = a > 0 ? a : -a;
        b = b > 0 ? b : -b;
        long res = div(a, b);
        if (sign == 1)
            return res > INT_MAX ? INT_MAX : res;
        return -res;
    }
    long div(long a, long b)
    {
        if (a < b) return 0;
        long count = 1;
        long tb = b;
        while ((tb + tb) <= a)
        {
            count += count;
            tb += tb;
        }
        return count + div(a - tb, b);
    }
};
//快速幂
class Solution {
public:
    double QuickMul(double x, long long N)
    {
        if (N == 0)
            return 1.0;
        double y = QuickMul(x, N / 2);
        return N % 2 == 0 ? y * y : y * y * x;
    }
    double myPow(double x, int n) {
        long long N = n;
        return N >= 0 ? QuickMul(x, N) : 1.0 / QuickMul(x, -N);
    }
};
