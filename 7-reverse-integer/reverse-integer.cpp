class Solution {
public:
    int reverse(int x) {
        bool neg=false;
        if(x<0){
            neg=true;
            x = abs(x);
        }

        long long ans=0;
        while(x>0){
            ans = ans*10 + (x%10);
            x = x/10;
        }
        if(neg){
            ans = -1*ans;
        }

        if(ans>pow(2,31)-1 || ans<-pow(2,31)){
            return 0;
        }
        return ans;
    }
};