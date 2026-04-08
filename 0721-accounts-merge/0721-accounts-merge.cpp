class Solution {
public:
    int find(int a, vector<int>&parent){
        if(a==parent[a])return a;
        return parent[a]=find(parent[a],parent);
    }
    void unionF(int x,int y,vector<int>&parent){
        int parentX=find(x,parent);
        int parentY=find(y,parent);
        if(parentX!=parentY){
            parent[parentX]=parentY;
        }
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        vector<int>parent(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        unordered_map<string,int>mpp;
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                string mail=accounts[i][j];
                if(mpp.find(mail)==mpp.end()){
                    mpp[mail]=i;
                }
                else{
                    unionF(mpp[mail],i,parent);
                }
            }
        }
        vector<vector<string>>mailMerged(n);
        for(auto it:mpp){
            string mail=it.first;
            int node=find(it.second,parent);
            mailMerged[node].push_back(mail);
        }
        vector<vector<string>>result;
        for(int i=0;i<n;i++){
            if(mailMerged[i].size()==0)continue;
            sort(mailMerged[i].begin(),mailMerged[i].end());
            string name=accounts[i][0];
            vector<string>temp;
            temp.push_back(name);
            for(auto x:mailMerged[i]){
                temp.push_back(x);
            }
            result.push_back(temp);
        }
        return result;
    }
};