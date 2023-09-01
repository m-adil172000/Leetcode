class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int low = 0;
        int high = n-1;
        int mid;

        

        while(low <= high){
            mid = (high+low)/2;

            if(citations[mid]==(n-mid)){
                return citations[mid];
            }
            else if((n-mid) < citations[mid]){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }

        return n-low;
    }
};