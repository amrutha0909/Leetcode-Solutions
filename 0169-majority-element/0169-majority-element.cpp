class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=0;
        int major;
        for(int i=0;i<nums.size();i++){
            if(count==0){
                major=nums[i];
            }
            if(nums[i]==major)count++;
            else{
                count--;
            }
        }
        return major;
    }
};