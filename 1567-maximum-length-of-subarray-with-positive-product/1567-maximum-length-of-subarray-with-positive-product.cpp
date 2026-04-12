class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int ans=0;
        int pos=0,neg=0;
        if(nums[0]>0)pos=1;
        if(nums[0]<0)neg=1;
        ans=pos;
        for(int i=1;i<nums.size();i++){
            if(nums[i]>0){
                pos=1+pos;
                neg=(neg>0)?neg+1:0;
            }
            else if(nums[i]<0){
                int newPos = (neg > 0) ? neg + 1 : 0;
                int newNeg = pos + 1;
                pos = newPos;
                neg = newNeg;
            }
            else{
                pos=0;
                neg=0;
            }
            ans=max(ans,pos);
        }
        return ans;
    }
};