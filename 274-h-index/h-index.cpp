class Solution {
public:
    int hIndex(vector<int>& citations) {
        
        int n=citations.size();

        int minv=INT_MAX, maxv = INT_MIN;

        for(int i=0; i<n; i++){
            maxv = max(maxv,citations[i]);
            minv = min(minv, citations[i]);
        }
        unordered_map<int,int>hidx;

        for(int i=0; i<=maxv; i++){
            int cnt=0;
            for(int j=0; j<n; j++){
                if(citations[j]>=i) cnt++;
            }
            hidx[i]=cnt;
        }

        int ans=-1;
        for(auto it:hidx){
            if(it.second>=it.first){
                ans = max(ans, it.first);
            }
        }

        return ans;

    }
};