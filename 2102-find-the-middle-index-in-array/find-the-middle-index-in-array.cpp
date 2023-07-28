class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {

        int n = nums.size();
        int Lsum = 0;
        int Rsum = 0;

        for(int i=0; i<n; i++){
            Rsum += nums[i];
        }

        for(int i=0; i<n; i++){

            Rsum -= nums[i];
            if(Lsum == Rsum) {
                return i;
            }
            
            Lsum += nums[i];
        }

        return -1;
    }
};