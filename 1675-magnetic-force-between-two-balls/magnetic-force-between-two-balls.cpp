class Solution {
private:
    int check(int idx, vector<int>position){
        int cnt=1;
        int prev=position[0];
        for(int i=1; i<position.size(); i++){
            if(position[i]-prev>=idx){
                cnt++;
                prev = position[i];
            }
        }

        return cnt;
    }

public:
    // Problem similar to Aggresive Cows
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int n = position.size();
        int l=0, r = (position[n-1]-position[0]);
        int ans=0;


        while(l<=r){
            int mid = l + (r-l)/2;

            if(check(mid,position)>=m){
                ans=mid;
                l=mid+1;
            }
            else r= mid-1;
        }

        return ans;


    }
};