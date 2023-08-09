class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        // int n = nums.size();

        // sort(nums.begin(), nums.end());

        // return nums[n/2];

        unordered_map<int, int> mp;

        for(int i:nums)
            mp[i]++;
        
        int maxVal = nums[0];

        for(auto i:mp){
            if(i.second > mp[maxVal])
                maxVal = i.first;
        }
        return maxVal;
    }
};