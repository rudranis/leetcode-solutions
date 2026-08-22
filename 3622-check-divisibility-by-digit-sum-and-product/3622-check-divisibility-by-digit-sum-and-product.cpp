class Solution {
public:
    bool checkDivisibility(int n) {
        int digitsum=0;
        int digproduct=1;
        int original=n;
        while(n>0){
            int digit=n%10;
            n/=10;
            digitsum+=digit;
            digproduct*=digit;
        }
        return  original%(digitsum+digproduct)==0;
    }
};