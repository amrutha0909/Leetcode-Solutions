class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>neg;
        vector<int>pos;
        for(int num:nums){
            if(num<0)neg.push_back(num);
            else pos.push_back(num);
        }
        vector<int>ans;
        int i=0;
        int j=0;
        while(i<pos.size()&&j<neg.size()){
            ans.push_back(pos[i]);
            ans.push_back(neg[j]);
            i++;
            j++;
        }
        return ans;
    }
};