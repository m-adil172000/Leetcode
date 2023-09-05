class Solution {
public:
    
    int gcd(int a, int b){
        if(b==0){
            return a;
        }

        return gcd(b, a%b);
    }

    int findGCD(vector<int>& nums) {
        int mine=INT_MAX;
        int maxe=INT_MIN;
        int n=nums.size();

        for(int i=0; i<n; i++){
            mine = min(mine, nums[i]);
            maxe = max(maxe, nums[i]);
        }

        if(mine==maxe) return mine;
        else return gcd(mine,maxe);
    }
};