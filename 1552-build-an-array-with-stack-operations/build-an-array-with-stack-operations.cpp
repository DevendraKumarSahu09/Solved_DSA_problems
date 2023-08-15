class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {

        int value=1, maxi=target[target.size()-1], i=0;

        vector<string> ans;

        while(value<=maxi){

            ans.push_back("Push");

            if(target[i]==value){
                i++;        
            }else ans.push_back("Pop");

            value++;
        }
        
        return ans;
    }
};