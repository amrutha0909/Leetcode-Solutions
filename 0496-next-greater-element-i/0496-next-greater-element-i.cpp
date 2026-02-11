class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>stk;
        unordered_map<int,int>mpp;
        int n=nums2.size();
        stk.push(nums2[n-1]);
        mpp[nums2[n-1]]=-1;
        for(int i=n-2;i>=0;i--){
            while(!stk.empty()&&stk.top()<nums2[i]){
                stk.pop();
            }
            if(stk.empty())mpp[nums2[i]]=-1;
            else mpp[nums2[i]]=stk.top();
            stk.push(nums2[i]);
        }
        for(int i=0;i<nums1.size();i++){
            nums1[i]=mpp[nums1[i]];
        }
        return nums1;
    }
};