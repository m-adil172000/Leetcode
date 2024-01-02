class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        bool dec=false;
        int n = nums.size();

        for(int i=1; i<n; i++){
            if(nums[i]<=nums[i-1]) dec=true;
            else{
                dec=false;
                break;
            }
        }

        if(dec){
            sort(nums.begin(),nums.end());
        }
        else{
            for(int i=n-1; i>0; i--){
                if(nums[i-1]<nums[i]){
                    int minv = nums[i-1];
                    int idx=i;
                    int repl = INT_MAX;
                    for(int j=i; j<n; j++){
                        if(nums[j]>nums[i-1]){
                            if(nums[j]<repl){
                                repl = nums[j];
                                idx=j;
                            }
                        }
                    } 
                    swap(nums[i-1],nums[idx]);
                    sort(nums.begin()+i,nums.end());
                    break;
                }
            }
        }
    }
};