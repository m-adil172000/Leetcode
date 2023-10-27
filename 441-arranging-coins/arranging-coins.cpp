class Solution {
public:
    int arrangeCoins(int n) {
        long long l=1, r=n;
        int ans=0;
        while(l<=r){
            long long m = l + (r-l)/2;

            if((m*(m+1)/2) >n){
                r=m-1;
            }
            else if((m*(m+1)/2) <n){
                l = m +1;
                ans = l;
            }
            else return m;
        }

        return ans-1;
    }
};