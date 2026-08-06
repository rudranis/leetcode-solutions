class Solution {
public:
    bool check (int num,int t){
        int prod=1;
        while(num>0){
            prod*=(num%10);
            num/=10;
            if(prod==0) break;
        }
        return prod%t==0;
    }
    int smallestNumber(int n, int t) {
        while(!check(n,t)){
            n++;
        }
        return n;
    }
};
