class Solution {
public:


    int hIndex(vector<int>& citations) {
        
        int n=citations.size();
        sort(citations.begin(), citations.end());

        int low =0, high = n-1;
        int mid;
        int valid;

        if(citations[0]>=n){
            return n;
        }
        
        while(low<=high){
            mid = low + (high-low)/2;

            if(citations[mid]==n-mid){
                return citations[mid];
            }
            else if(citations[mid]<n-mid){
                valid = mid;
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }

        return n-valid-1;
        
    }
};