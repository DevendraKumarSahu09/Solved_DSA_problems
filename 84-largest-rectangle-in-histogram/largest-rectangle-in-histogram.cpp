class Solution {
public:

    vector<int> prevSmallerElement(vector<int>& heights){
        stack<int>s;
        s.push(-1);

        vector<int> ans(heights.size());

        for(int i=0; i<heights.size(); i++){
            
            int curr = heights[i];

            while(s.top() != -1 && heights[s.top()] >= curr){
                s.pop();
            }

            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }

    vector<int> nextSmallerElement(vector<int>& heights){
        stack<int>s;
        s.push(-1);

        vector<int> ans(heights.size());

        for(int i=heights.size()-1; i>=0; i--){
            
            int curr = heights[i];

            while(s.top() != -1 && heights[s.top()] >= curr){
                s.pop();
            }

            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }

    int largestRectangleArea(vector<int>& heights) {
        
        int size = heights.size();

        vector<int> prev(size);
        prev = prevSmallerElement(heights);

        vector<int> next(size);
        next = nextSmallerElement(heights);

        int maxArea = INT_MIN;
        for(int i=0; i<size; i++){

            if(next[i] == -1){
                next[i] = size;   
            }

            int l = heights[i];
            int b = next[i] - prev[i] - 1;
            int area = l*b;

            maxArea = max(maxArea, area);
        }
        return maxArea;
    }
};