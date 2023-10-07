class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=0;

        int oddcnt=0;
        vector<int>prevodd;
        prevodd.push_back(n);
        int pos=n;
        if(nums[n-1]%2!=0) pos =n-1;
        for(int i=n-2; i>=0; i--){
            prevodd.push_back(pos);
            if(nums[i]%2!=0) pos=i;
        }
        reverse(prevodd.begin(),prevodd.end());
        int i=0,j=0;

        while(j<n){
            if(nums[j]%2 != 0) oddcnt++;
            while(oddcnt==k){
                ans += prevodd[j]-j;
                if(nums[i]%2!=0) oddcnt--;
                i++;
            }
            j++;
        }

        return ans;
    }
};