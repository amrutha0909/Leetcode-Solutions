class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int>stk;
        int n=nums.size();
        vector<int>nge(n);
        for(int i=2*n;i>=0;i--){
            int index=i%n;
            while(!stk.empty()&&stk.top()<=nums[index]){
                stk.pop();
            }
            if(stk.empty())nge[index]=-1;
            else nge[index]=stk.top();
            stk.push(nums[index]);
        }
        return nge;
    }
};