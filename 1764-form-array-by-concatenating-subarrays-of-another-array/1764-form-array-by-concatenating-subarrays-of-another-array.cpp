class Solution {
public:
    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
        int i = 0; 
    int j = 0;       
    while(i < groups.size() && j < nums.size()){
            
        int k = 0;
        while(k < groups[i].size() && j + k < nums.size() && 
              groups[i][k] == nums[j + k]){
            k++;
        }
        if(k == groups[i].size()){
            j = j + k; 
            i++;
        }
        else{
            j++; 
        }
    }
        
    return i == groups.size();
    }
};