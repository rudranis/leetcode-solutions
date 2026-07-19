class Solution {
public:
    int nextIndex(vector<int>& nums, int curr) {
        int n = nums.size();
        return ((curr + nums[curr]) % n + n) % n;
    }

    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            bool forward = nums[i] > 0;
            int slow = i;
            int fast = i;

            while (true) {
                int nextSlow = nextIndex(nums, slow);
                if ((nums[nextSlow] > 0) != forward)
                    break;
                int nextFast = nextIndex(nums, fast);

                if ((nums[nextFast] > 0) != forward)
                    break;

                nextFast = nextIndex(nums, nextFast);

                if ((nums[nextFast] > 0) != forward)
                    break;

                slow = nextSlow;
                fast = nextFast;

                if (slow == fast) {
                    if (slow == nextIndex(nums, slow))
                        break;

                    return true;
                }
            }
        }

        return false;
    }
};