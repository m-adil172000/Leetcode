class Solution {
public:
    int majorityElement(vector<int>& nums) {

        //Moore’s Voting Algorithm
        /*
        If the array contains a majority element, its occurrence must be greater than the floor(N/2). Now, we can say that the count of minority elements and majority elements is equal up to a certain point in the array. So when we traverse through the array we try to keep track of the count of elements and the element itself for which we are tracking the count. 

After traversing the whole array, we will check the element stored in the variable. If the question states that the array must contain a majority element, the stored element will be that one but if the question does not state so, then we need to check if the stored element is the majority element or not. If not, then the array does not contain any majority element.
        */
        int cnt=0;
        int el;
        for(int i=0; i<nums.size(); i++){
            if(cnt==0){
                el = nums[i];
                cnt=1;
            }
            else if(nums[i]==el){
                cnt++;
            }
            else{
                cnt--;
            }
        }

        /*
        if majority element doesn't always exist 

        //checking if the stored element
        // is the majority element:
        int cnt1 = 0;
        for (int i = 0; i < n; i++) {
            if (v[i] == el) cnt1++;
        }

        if (cnt1 > (n / 2)) return el;
        return -1;
        
        */

        return el;
    }
};