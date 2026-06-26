class Solution {
public:
    int nextno(int n){
        int sum=0;
        while(n){
            int d=n%10;
            sum+=d*d;
            n=n/10;
        }
        return sum;
    }
    bool isHappy(int n) {
        int slow=n;
        int fast=n;
        do{
            slow=nextno(slow);
            fast=nextno(nextno(fast));
        }while(slow!=fast);
        return slow==1;
    }

};