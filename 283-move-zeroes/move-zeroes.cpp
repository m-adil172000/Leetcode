class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        /*
        First, using a loop, we will place the pointer j. If we don’t find any 0, we will not perform the following steps.
        After that, we will point i to index j+1 and start moving the pointer using a loop.
        While moving the pointer i, we will do the following:
        If a[i] != 0 i.e. a[i] is a non-zero element: We will swap a[i] and a[j]. Now, the current j is pointing to the non-zero 
         a[i]. So, we will shift the pointer j by 1 so that it can again point to the first zero.
        Finally, our array will be set in the right manner.
        */
        int n=nums.size();
        if(n==1) return;

        int j=-1;
        for(int i=0; i<n; i++){
            if(nums[i]==0){
                j=i;
                break;
            }
        }
        if(j==-1) return;

        for(int i=j+1; i<n; i++){
            if(nums[i]!=0){
                swap(nums[i],nums[j]);
                j++;
            }
        }
    }
};

/*
void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return;

        vector<int>temp;
        for(int i=0; i<n; i++){
            if(nums[i]!=0) temp.push_back(nums[i]);
        }

        int i=0;
        int j=0;
        while(j<temp.size()){
            if(temp[j]==nums[i]){
                i++;
                j++;
            }
            else{
                nums[i]=temp[j];
                i++;
                j++;
            }
        }
        while(i<n){
            nums[i]=0;
            i++;
            }        
    }
*/