class Solution {
public:
    int pivotIndex(vector<int>& nums) {
       
        int LeftSum = 0;
        int RightSum = 0;

        for(int i=0; i<nums.size(); i++)
            RightSum += nums[i];

        for(int i=0; i<nums.size(); i++){

            RightSum -= nums[i];

            if(LeftSum == RightSum) return i;
            
            LeftSum += nums[i];

        }
        return -1;
    }
};