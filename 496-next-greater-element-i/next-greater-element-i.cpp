class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        unordered_map<int,int>mp; // to store the value and it's index in nums2

        stack<int>stk;
        vector<int>ans;

        for(int i=m-1;i>=0; i--){
            int elem = nums2[i];
            while(stk.size()>0 && stk.top()<=elem){
                stk.pop();
            }
            int res= (stk.empty()) ? -1 : stk.top();
            mp[elem]=res;
            stk.push(elem);
        }

        for(int i=0; i<n; i++){
            ans.push_back(mp[nums1[i]]);
        }        

        return ans;


    }
};