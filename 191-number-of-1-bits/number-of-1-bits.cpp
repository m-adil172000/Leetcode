class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans=0;

        while(n>0){
            n = n&(n-1);
            ans++;
        }

        return ans;
    }
};

/*
int ans=0;
        while(n>0){
            if((n&1)==1){
                ans++;
            }
            n = n>>1;
        }

        return ans;
*/