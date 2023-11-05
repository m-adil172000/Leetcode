class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<int>after(2*k+1,0), curr(2*k+1,0);

        for(int i=n-1; i>=0; i--){
            for(int j=0; j<2*k; j++){
                if(j%2==0){
                    curr[j] = max(-prices[i] + after[j+1], after[j]);
                }
                else{
                    curr[j] = max(prices[i] + after[j+1], after[j]);
                }
            }
            after = curr;
        }

        return after[0];
    }
};