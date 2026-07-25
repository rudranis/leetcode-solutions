class Solution {
public:
    int extract(int n){
        return n%10;
    }
    int maxProduct(int n) {
        int first = -1;
        int second = -1;
        while (n > 0) {
            int digit = extract(n);
            if (digit >= first) {
                second = first;
                first = digit;
            }
            else if (digit > second) {
                second = digit;
            }
            n /= 10;
        }
        return first * second;
    }
};
   