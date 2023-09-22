class Solution {
public:

    static bool compr(vector<int>&a, vector<int>&b){
        return a[1]>b[1];
    }

    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int n = boxTypes.size();

        sort(boxTypes.begin(), boxTypes.end(), compr);

        int ans=0;
        int box=0;

        for(int i=0; i<n; i++){
            if(truckSize >= boxTypes[i][0] + box){
                box += boxTypes[i][0];
                ans += boxTypes[i][0]*boxTypes[i][1];
            }
            else{
                int rem = truckSize - box;
                ans += rem * boxTypes[i][1];
                break;
            }
        }

        return ans;
    }
};