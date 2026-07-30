class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(),skill.end());
        int l=0,r=skill.size()-1;
        int target=skill[l]+skill[r];
        long long ans=0;
        while(l<r){
            if(skill[l]+skill[r]!=target){
                return -1;
            }
            ans+=1LL*skill[l]*skill[r];
            l++;
            r--;
        }
        return ans;
    }
};