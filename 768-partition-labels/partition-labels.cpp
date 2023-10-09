class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.length();
        unordered_map<char,int>mp; // to store the last occuring index of each character in the string
        for(int i=n-1; i>=0; i--){
            if(mp.find(s[i])==mp.end()){
                mp[s[i]]=i;
            }
        }

        vector<int>ans;
        int last = mp[s[0]];
        int len=1;
        for(int i=1; i<n; i++){
            if(mp[s[i]]<=last && i<=last){
                len++;
            }
            else{
                if(i>last){
                    ans.push_back(len);
                    len=1;
                    last = mp[s[i]];
                }
                else if(mp[s[i]]>last){
                    last = mp[s[i]];
                    len++;
                }
            }
        }
        
        ans.push_back(len);
        return ans;



       
    }
};