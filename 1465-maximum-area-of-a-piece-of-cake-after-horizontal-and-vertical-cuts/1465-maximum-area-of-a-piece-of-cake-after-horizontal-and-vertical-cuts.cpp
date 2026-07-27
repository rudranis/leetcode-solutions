class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        const int MOD=1e9+7;
        sort(horizontalCuts.begin(),horizontalCuts.end());
        sort(verticalCuts.begin(),verticalCuts.end());
        long long maxh=horizontalCuts[0];
        for(int i=1;i<horizontalCuts.size();i++){
            maxh=max(maxh,(long long ) (horizontalCuts[i]-horizontalCuts[i-1]));
        }
        maxh=max(maxh,(long long)(h-horizontalCuts.back()));
        long long maxw=verticalCuts[0];
        for(int i=1;i<verticalCuts.size();i++){
            maxw=max(maxw,(long long)(verticalCuts[i]-verticalCuts[i-1]));
        }
        maxw=max(maxw,(long long )(w-verticalCuts.back()));
        return (maxh*maxw)%MOD;

    }
};