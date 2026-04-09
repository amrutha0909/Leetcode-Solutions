class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(),products.end());
        int n=searchWord.size();
        vector<vector<string>>res;
        int l=0,r=products.size()-1;
        for(int i=0;i<n;i++){
            char c=searchWord[i];
            while(l<=r && (products[l].size()<=i||products[l][i]!=c)){
                l++;
            }
            while(l<=r && (products[r].size()<=i|| products[r][i]!=c)){
                r--;
            }
            vector<string>ans;
            for(int j=0;j<min(3,r-l+1);j++){
                ans.push_back(products[l+j]);
            }
            res.push_back(ans);
        }
        return res;
    }
};