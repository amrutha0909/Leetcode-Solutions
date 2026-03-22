class Solution {
public:
    int find(int i,vector<int>&parent){
        if(i==parent[i])return i;
        return parent[i]=find(parent[i],parent);
    }
    void unionFind(int x, int y,vector<int>&parent){
        int xParent=find(x,parent);
        int yParent=find(y,parent);
        if(xParent!=yParent){
            parent[xParent]=yParent;
        }
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        unordered_map<string,int>mpp;
        vector<int>parent(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                string mail=accounts[i][j];
                if(mpp.find(mail)==mpp.end()){
                    mpp[mail]=i;
                }
                else{
                    unionFind(mpp[mail],i,parent);
                }
            }
        }   
        vector<vector<string>>mailMerged(n);
        for(auto&it:mpp){
            string mail=it.first;
            int node=find(it.second,parent);
            mailMerged[node].push_back(mail);
        }
        vector<vector<string>>result;
        for(int i=0;i<n;i++){
            if(mailMerged[i].size()==0)continue;
            sort(mailMerged[i].begin(),mailMerged[i].end());
            vector<string>temp;
            temp.push_back(accounts[i][0]);
            for(auto&it:mailMerged[i]){
                temp.push_back(it);
            }
            result.push_back(temp);
        }
        return result;
    }
};