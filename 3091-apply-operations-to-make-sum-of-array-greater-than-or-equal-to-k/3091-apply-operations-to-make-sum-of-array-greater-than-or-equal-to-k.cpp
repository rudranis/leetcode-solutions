class Solution {
public:
    int minOperations(int k) {
        if(k==1) return 0;
         int a = sqrt(k);
        return a + (k - 1) / a - 1;
    }
};