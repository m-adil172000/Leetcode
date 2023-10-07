class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int curr_sum=0;
        int total=0;
        for(auto it:cardPoints) total+=it;
        int i=0, j=n-k-1;
        for(int x=i;x<=j; x++) curr_sum += cardPoints[x];
        int ans=0;

        while(j+1<n){
            ans = max(ans,total-curr_sum);
            curr_sum -= cardPoints[i];
            i++;
            j++;
            curr_sum += cardPoints[j];
            ans = max(ans,total-curr_sum);
        }
        
        return ans;
    }
};