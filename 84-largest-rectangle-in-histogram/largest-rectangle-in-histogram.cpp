class Solution {

public:
    
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        vector<int>prevSmall;
        stack<int>st1;
        for(int i=0; i<n; i++){
            while(st1.size()>0 && heights[st1.top()] >= heights[i]){
                st1.pop();
            }
            if(st1.size()>0){
                prevSmall.push_back(st1.top());
            }
            else prevSmall.push_back(-1);

            st1.push(i);
        }
        vector<int>nxtSmall;
        stack<int>st2;
        for(int i=n-1; i>=0; i--){
            while(st2.size()>0 && heights[st2.top()] >= heights[i]) {
                st2.pop();
            }
            if(st2.size()>0){
                nxtSmall.push_back(st2.top());
            }
            else nxtSmall.push_back(n);

            st2.push(i);
        }
        reverse(nxtSmall.begin(), nxtSmall.end());
        int ans=0;
        for(int i=0; i<n; i++){
            ans = max(ans, heights[i]*(nxtSmall[i]-prevSmall[i]-1));
        }

        return ans;



    }
};