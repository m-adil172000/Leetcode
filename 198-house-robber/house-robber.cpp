class Solution {
public:

    

    int rob(vector<int>& nums) {
        int n=nums.size();
        int rob1=0, rob2=0;

        // [rob1, rob2, i, i+1, i+2, ....]
        for(int i=0; i<n; i++){
            int temp = max(nums[i]+rob1, rob2);
            rob1 = rob2;
            rob2 = temp;
        }

        return rob2;
    }
};

/*
int n = nums.size();

        vector<int>ans = nums;
        if(n-3>=0){
            ans[n-3] += ans[n-1];
        }
        for(int i=n-4; i>=0; i--){
            
            int maxe=0;
            int j=i+2;
            while(j<n){
                maxe = max(maxe,ans[j]);
                j++;
            }
            ans[i] += maxe;
        }

        int money=0;
        for(int i=0; i<n; i++){
            money = max(money, ans[i]);
        }

        return money;
*/