class Solution {
public:
    bool canJump(vector<int>& nums) {
        int farthest=0;
        for(int i=0;i<nums.size();i++){
            if(i>farthest)return false; //this means i have arrived at a position my previous jumps couldn't reach(crossed farthest possible jump). so it means there is no way of reaching last index.
            farthest=max(farthest,i+nums[i]);
        }
        return true;
    }
};