class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int l = 0, h = n-1;
        int m;
        while(l<=h){
            m = l + (h-l)/2;
            int missing = arr[m]-m-1;
            if(missing <k){
                l = m + 1;
            }
            else h = m -1;
        }

        return h + 1 + k; // arr[h]+more = arr[h]+(k-missing)= arr[h] + (k - (arr[h]-h-1)) -> k + h + 1
    }
};