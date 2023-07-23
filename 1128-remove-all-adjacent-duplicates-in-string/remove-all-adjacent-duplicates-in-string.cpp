class Solution {
public:
    string removeDuplicates(string s) {
        
        stack<char>sTack;
        for(int i=0; i<s.size(); i++){

            char ch = s[i];
        
            if(!sTack.empty() && sTack.top() == ch){
                sTack.pop();
            }else{
                sTack.push(ch);
            }
        }
        
        string ans;
        while(!sTack.empty()){
            ans += sTack.top();
            sTack.pop();
        }
        reverse(ans.begin(), ans.end());

        return ans;
    }
};