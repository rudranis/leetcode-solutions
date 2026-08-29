class Solution {
public:
    int gcd(int a, int b) {
        while (b != 0) {
            int temp = a % b;
            a = b;
            b = temp;
        }
        return a;
    }

    int getScore(vector<int>& arr) {

        int n = arr.size();

        if (n < 2)
            return 0;

        vector<int> prefix(n);
        vector<int> suffix(n);

        // Prefix GCD
        prefix[0] = arr[0];

        for (int i = 1; i < n; i++) {
            prefix[i] = gcd(prefix[i - 1], arr[i]);
        }

        // Suffix GCD
        suffix[n - 1] = arr[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            suffix[i] = gcd(suffix[i + 1], arr[i]);
        }

        int cnt = 0;

        // Check every split
        for (int i = 0; i < n - 1; i++) {

            int leftGcd = prefix[i];
            int rightGcd = suffix[i + 1];

            if (leftGcd == rightGcd) {
                cnt++;
            }
        }

        return cnt;
    }

    int  maxValidSplits(vector<int>& nums){

        vector<int> vornalethm = nums;

        int n = nums.size();

        // Don't remove anything
        int ans = getScore(nums);

        // Remove one element
        for (int remove = 0; remove < n; remove++) {

            vector<int> arr;

            for (int i = 0; i < n; i++) {

                if (i != remove) {
                    arr.push_back(nums[i]);
                }
            }

            ans = max(ans, getScore(arr));
        }

        return ans;
    }
};
