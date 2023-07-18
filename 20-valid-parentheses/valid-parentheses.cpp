class Solution {
public:
    bool isValid(string s) {
        stack<char>st;

    for(int i=0; i<s.size(); i++){

        char ch = s[i];
        if(ch == '(' || ch == '{' || ch == '['){
            st.push(ch);
        }
        else
        {
          if (!st.empty()) {
            char checkTop = st.top();
            if (ch == ')' && checkTop == '(' || 
                ch == '}' && checkTop == '{' ||
                ch == ']' && checkTop == '['){
                    st.pop();
                }else{
                    return false;
                }
          }else{
              return false;
          }
        }
    }
    if(st.empty())
        return true;
    else    
        return false;
    }
};