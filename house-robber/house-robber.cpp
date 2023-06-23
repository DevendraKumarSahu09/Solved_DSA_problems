class Solution {
private:
    int solve(vector<int> &nums){
    int n = nums.size();

    if(n<1)
        return 0;
    if(n==1)
        return nums[0];
    
    vector<int> dpArr(n, 0);

    dpArr[0] = nums[0];
    dpArr[1] = max(nums[1] , nums[0]);

    for(int i=2; i<n; i++){
     
        dpArr[i] = max(dpArr[i-2] + nums[i], dpArr[i-1]);

    }
    return dpArr[n-1];
}
public:
    int rob(vector<int>& nums) {  
        return solve(nums);
    }
};