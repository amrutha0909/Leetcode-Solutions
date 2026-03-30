class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(),products.end());
        int n=searchWord.size();
        vector<vector<string>>res;
        for(int i=1;i<=n;i++){
            string sub=searchWord.substr(0,i);
            vector<string>ans;
            int count=0;
            for(string s:products){
                if(s.starts_with(sub)&&count<3){
                    count++;
                    ans.push_back(s);
                }
            }
            res.push_back(ans);
        }
        return res;
    }
};