class Solution {
public:
    bool checkGoodInteger(int n) {
        int squareSum = 0, digitSum = 0;
        while(n){
            int x = n % 10;
            squareSum += x*x;
            digitSum += x;
            n /= 10;
        }
        return squareSum - digitSum >= 50;
    }
};