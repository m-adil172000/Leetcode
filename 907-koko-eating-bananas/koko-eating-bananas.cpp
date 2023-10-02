class Solution {
private:
    long long check(int k, vector<int> piles, int h){
        long long ans=0;

        for(int i=0; i<piles.size(); i++){
           ans += ceil((double)piles[i]/(double)k);
        }

        return ans;
    }


public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        if(n==1){
            if(piles[0]%h==0) return piles[0]/h;
            else return piles[0]/h +1;
        }


        int l = 1, r = INT_MIN;
        for(int i=0; i<n; i++){
            r = max(piles[i],r);
        }
        int ans=0;

        while(l<=r){
            int m = l + (r-l)/2;
            if(check(m,piles,h) <= h){
                ans =m;
                r = m-1;
            }
            else{
                l = m+1;
            }
        }

        return ans;
    }
};