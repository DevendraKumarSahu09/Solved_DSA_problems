class Solution {
public:
    string removeDuplicateLetters(string s) {

        stack<int> stAck;
        unordered_map<int,bool> visited;

        int lastIdx[26] ;
        string ans = "";
        
        for(int i=1 ; i<=26;i++)
            visited[i] = false;
        
        for(int i=0 ; i<s.size();i++)
            lastIdx[s[i] - 'a'] = i;
        
        for(int i=0 ; i<s.size();i++){
            
            int val = s[i] - 'a';
            if(visited[val]) continue;

            while(!stAck.empty()  && stAck.top() > val && lastIdx[stAck.top()] > i){
                visited[stAck.top()] = false;
                 stAck.pop();
            }

            stAck.push(val);
            visited[val] = true;
        }

        while(!stAck.empty()){
            ans+= stAck.top() + 'a';
            stAck.pop();
        }

        reverse(ans.begin(),ans.end());
        return ans;
    }
};