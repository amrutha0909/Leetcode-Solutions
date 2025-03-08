class Solution {
    public:
        vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
            int n1=nums1.size();
            int n2=nums2.size();
            vector<vector<int>>res;
            unordered_map<int,int>idval;
            for(int i=0;i<n1;i++){
                int id=nums1[i][0];
                int nums=nums1[i][1];
                idval[id]+=nums;
            }
            for(int i=0;i<n2;i++){
                int id=nums2[i][0];
                int nums=nums2[i][1];
                idval[id]+=nums;
            }
            for(auto&it:idval){
                res.push_back({it.first,it.second});
            }
            sort(res.begin(),res.end());
            return res;
        }
    };