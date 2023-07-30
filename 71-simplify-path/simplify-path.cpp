class Solution {
public:
    void buildAns(stack<string> &s, string& ans){

        if(s.empty()) return;

        string minPath = s.top(); s.pop();
        buildAns(s, ans);
        ans += minPath;
    }

    string simplifyPath(string path) {
        
        stack<string>s;
        int index = 0;
        
        while(index < path.size()){
            int start = index;
            int end = index + 1;

            while(end<path.size() && path[end] != '/'){
                ++end;
            }
            string minPath = path.substr(start, end-start);
            index = end;

            if(minPath == "/" || minPath == "/.") continue;

            if(minPath != "/..")
                s.push(minPath);
            else if(!s.empty())
                s.pop();
        }
        string ans = s.empty() ? "/" : "";

        buildAns(s, ans);
        return ans;
    }
};