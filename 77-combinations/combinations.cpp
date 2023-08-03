class Solution {
private:
    void solve(int n, int k, int index, vector<vector<int>> &ans, vector<int>&combi){
        
        if(combi.size() >= k){
            ans.push_back(combi);
            return;
        }

        for(int i=index; i<=n; i++){
            combi.push_back(i);
            solve(n, k, i+1, ans, combi);
            combi.pop_back();
        }
    }
public:

    vector<vector<int>> combine(int n, int k) {
        vector< vector<int> > ans;
        vector<int> combi;
        
        int index = 1;
        solve(n, k, index, ans, combi);

        return ans;
    }
};