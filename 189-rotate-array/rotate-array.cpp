class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k%(nums.size());
        int n =nums.size();
        
        reverse(nums.begin(), nums.begin()+n-k);
        reverse(nums.begin()+n-k, nums.end());
        reverse(nums.begin(), nums.end());
        
    }
};
/*

1 2 3 4 5 6 7
4 2 3 1 5 6 7
4 5 3 1 2 6 7
4 5 6 1 2 3 7
4 5 6 7 1 2 3
5 6 7 1 2 3 4

*/