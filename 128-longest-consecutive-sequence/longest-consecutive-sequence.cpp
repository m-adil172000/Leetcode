class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        int n=nums.size();
        if(n==0) return 0;

        unordered_set<int>st;
        for(int i=0; i<nums.size(); i++){
            st.insert(nums[i]);
        }
        
        int ans=1;
        
        // we will iterate in the set
        for(auto it: st){
            //check if the current number is the starting sequence or not
            if(st.find(it-1)==st.end()){ //the number has no element before it then it must be the starting of the sequence
                int curr=1;
                //Now , we will find how long this sequence can be
                int x=it;
                while(st.find(x+1) != st.end()){
                    x++;
                    curr++;
                }

                // let's update our ans
                ans = max(ans, curr);

            }
        }

        return ans;

    }
};