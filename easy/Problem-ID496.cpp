class Solution {
    public:
        vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
            int n1=nums1.size();
            int n2=nums2.size();
            vector<int>ans(n1);
            int index=0;
            for(int i=0;i<n1;i++){
                for(int j=0;j<n2;j++){
                    if(nums1[i]==nums2[j]){
                        index=j;
                    }
                    for(int k=index;k<n2;k++){
                        if(nums2[k]>nums1[i]){
                            ans[i]=nums2[k];
                            break;
                        }
                        else{
                            ans[i]=-1;
                        }
                    }
                }
            }
            return ans;
        }
    };