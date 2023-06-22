class Solution {
private:
    void solve(vector<int> nums, int index, vector<vector<int> > &ans){
        if(index >= nums.size()){
            ans.push_back(nums);
            return;
        }
        unordered_set<int>s;

        for(int j=index; j<nums.size(); j++){
            
            if(s.find(nums[j])!= s.end()) continue;
            s.insert(nums[j]);

            swap(nums[index], nums[j]);
            solve(nums,index+1,ans);

            swap(nums[index], nums[j]);
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int> > ans;
        int index = 0;
        solve(nums,index,ans);
        return ans;
    }
};
