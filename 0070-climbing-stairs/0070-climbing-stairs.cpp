class Solution {
public:
    int helper(int i){
        if(i<=1)return 1;
        return helper(i-1)+helper(i-2);
    }
    int climbStairs(int n) {
        return helper(n);
    }
};