class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        
        vector<vector<int>>ans;
        vector<pair<int, int>>store;
        int n = groupSizes.size();

        for(int i=0; i<n; i++){
            store.push_back(make_pair(groupSizes[i], i));
        }

        sort(store.begin(), store.end());

        vector<int>currGrp;
        for(int i=0; i<n; i++){

            currGrp.push_back(store[i].second);

            if(currGrp.size() == store[i].first){
                ans.push_back(currGrp);
                currGrp.clear();
            }
        }

        return ans;
     
    }
};
