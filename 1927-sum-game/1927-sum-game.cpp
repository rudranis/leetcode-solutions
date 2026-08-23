class Solution {
public:
    bool sumGame(string num) {

        int n = num.size();

        int leftSum = 0;
        int rightSum = 0;

        int leftQ = 0;
        int rightQ = 0;

        // First half
        for (int i = 0; i < n / 2; i++) {
            if (num[i] == '?')
                leftQ++;
            else
                leftSum += num[i] - '0';
        }

        // Second half
        for (int i = n / 2; i < n; i++) {
            if (num[i] == '?')
                rightQ++;
            else
                rightSum += num[i] - '0';
        }

        int diff = leftSum - rightSum;
        int qDiff = rightQ - leftQ;

        // Bob wins only in this exact case
        return 2 * diff != 9 * qDiff;
    }
};