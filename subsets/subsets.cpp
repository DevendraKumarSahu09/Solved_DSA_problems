class Solution {
private:
    void solve(vector<int> nums,int index, vector<int> output, vector<vector<int> >& ans){
        //base case
        if(index >= nums.size()){
            ans.push_back(output);
            return;
        }

        //exclude part
        solve(nums, index+1, output, ans);

        //include part
        int element = nums[index];
        output.push_back(element);
        solve(nums, index+1, output, ans);
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int> > ans;
        int index = 0;
        vector<int>output;
        solve(nums, index, output, ans);
        return ans;
    }
};