class Solution {
public:


    int hIndex(vector<int>& citations) {
        
        int n=citations.size();
        int maxe;
        sort(citations.begin(), citations.end());
        maxe = citations[n-1];

        int ans=-1;
        for(int i=0; i<=maxe; i++){
            int papers=0;
            for(int j=0; j<n; j++){
                if(citations[j]>=i){
                    papers++;
                }
            }
            if(papers>=i){
                ans = max(ans, i);
            }
            else{
                break;
            }
        }

        return ans;
    }
};