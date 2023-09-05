class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string>ans;

        int n = nums.size();
        if(n==0) return ans;
        string s ="";
        int str=nums[0];
        int end=nums[0];
        for(int i=1; i<n; i++){
            if(nums[i]==end+1){
                end++;
            }
            else{
                string c= to_string(str);
                string d = to_string(end);
                
                if(str==end){
                    s += c;
                }
                else{
                    s += c;
                    s += "->";
                    s += d;
                }
                ans.push_back(s);
                s="";

                str = nums[i];
                end = nums[i];
            }
        }
        string c= to_string(str);
        string d = to_string(end);
        if(str==end){
            s += c;
        }
        else{
            s += c;
            s += "->";
            s += d;
        }
        ans.push_back(s);

        return ans;

    

    }
};