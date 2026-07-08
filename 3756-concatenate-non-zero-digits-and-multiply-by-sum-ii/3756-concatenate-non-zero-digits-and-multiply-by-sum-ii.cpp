class Solution {
public:
    typedef long long ll;
    int MOD=1e9+7;
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n=s.length();
        vector<int>nonzerocount(n,0);
        vector<ll>numberupto(n,0);
        vector<ll>digitsumupto(n,0);
        vector<ll>pow10(n+1,0);
        pow10[0]=1;
        for(int i=1;i<=n;i++){
            pow10[i]=(pow10[i-1]*10)%MOD;
        }
        nonzerocount[0]=(s[0]!='0')?1:0;
        for(int i=1;i<n;i++){
            int digit=s[i]-'0';
            nonzerocount[i]=nonzerocount[i-1]+((digit!=0)?1:0);
        }
        numberupto[0]=(s[0]!='0') ? s[0]-'0' : 0;
        for(int i=1;i<n;i++){
            int digit=s[i]-'0';
            if(digit!=0){
                numberupto[i]=((numberupto[i-1]*10)+digit)%MOD;
            }
            else{
                numberupto[i]=numberupto[i-1];
            }
        }
        digitsumupto[0]=s[0]-'0';
        for(int i=1;i<n;i++){
            int digit=s[i]-'0';
            digitsumupto[i]=digitsumupto[i-1]+digit;
        }

        int q=queries.size();
        vector<int>result(q);
        for(int i=0;i<q;i++){
            int l=queries[i][0];
            int r=queries[i][1];
            //sum*x;
            ll sum=digitsumupto[r]-((l==0)?0:digitsumupto[l-1]);
            long long numbefore=(l==0)?0:numberupto[l-1];
            int k=nonzerocount[r]-((l==0)?0:nonzerocount[l-1]);
            ll x=(numberupto[r]-(numbefore* pow10[k]%MOD)+MOD)%MOD;
            result[i] = (x * sum) % MOD;
        }
        return result;
    }
};