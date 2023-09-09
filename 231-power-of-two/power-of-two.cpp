class Solution {
public:
    bool isPowerOfTwo(int n) {
        // if a number is a power of 2 then it will have only one set bit
        // and the number less than that number will have all other set bits before the set bit in the above number
        // for eg: 8(1000) , 7(0111)
        //  16(10000) , 15(01111)

        if(n<=0) return false;

        return (n&(n-1))==0;
    }
};

/*
int cnt=0;
        while(n>0){
            n = n&(n-1);
            cnt++;
        }

        return cnt==1;
*/