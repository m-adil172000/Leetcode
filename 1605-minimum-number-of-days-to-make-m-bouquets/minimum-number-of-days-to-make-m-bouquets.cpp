class Solution {
private:
    int bouquet(int days, vector<int>bloomDay, int k){
        int ans=0;

        int curr=0;
        for(int i=0; i<bloomDay.size(); i++){
            if(bloomDay[i]<=days){
                curr++;
                if(curr==k){
                    ans++;
                    curr=0;
                }
            }
            else curr=0;
        }
        return ans;
    }

public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if((long long)m*k > n) return -1;

        int l=INT_MAX, r=INT_MIN;
        for(auto it:bloomDay){
            r = max(it,r);
            l = min(l,it);
        }
        int ans=0;
        while(l<=r){
            int mid = l + (r-l)/2;

            if(bouquet(mid,bloomDay,k)>=m){
                ans = mid;
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }

        return ans;
    }
};