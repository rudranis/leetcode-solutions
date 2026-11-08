class Solution {
public:
    long long minimumMaxValue(int n, int index, int value) {
        if (value == 1) return -1;

        long long p = value;

        for (long long i = 2; i * i <= value; i++) {
            if (value % i == 0) {
                p = i;
                break;
            }
        }

        long long maxLeft = (value - p) / 2;

        if (index > maxLeft) return -1;

        long long right = n - index - 1;

        if (right == 0) return value;

        return value + p + 2 * (right - 1);
    }
};