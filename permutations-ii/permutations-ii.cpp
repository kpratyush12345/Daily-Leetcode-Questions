class Solution {
public:
    void recurPermute(vector<int>& ds,vector<int>& nums,set<vector<int>>& ans,vector<int>& freq){
        if(ds.size() == nums.size()){
            ans.insert(ds);
            return;
        }
        for(int i = 0;i<nums.size();i++){
            if(!freq[i]){
                ds.push_back(nums[i]);
                freq[i] = 1;
                recurPermute(ds,nums,ans,freq);
                freq[i] = 0;
                ds.pop_back();
            }
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> ans;
        vector<int> ds;
        vector<int> freq(nums.size(),0);
        recurPermute(ds, nums, ans, freq);
        vector<vector<int>> res;
        for(vector<int> p: ans){
            res.push_back(p);
        }
        return res;
    }
};