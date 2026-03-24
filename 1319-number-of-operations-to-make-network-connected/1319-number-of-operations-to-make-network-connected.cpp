class Solution {
public:
    int find(int i,vector<int>&parent){
        if(i==parent[i])return parent[i];
        return parent[i]=find(parent[i],parent);
    }
    void unionF(int x, int y, vector<int>&parent){
        int xParent=find(x,parent);
        int yParent=find(y,parent);
        if(xParent!=yParent){
            parent[xParent]=yParent;
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int m=connections.size(); //number of edges
        vector<int>parent(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        for(auto&edge:connections){
            int u=edge[0];
            int v=edge[1];
            if(find(u,parent)!=find(v,parent)){
                unionF(u,v,parent);
            }
        }
        unordered_set<int>st;
        for(int i=0;i<n;i++){
            st.insert(find(i,parent));
        }
        //we know that to make a graph connected, we needed n-1 edges;
        int nc=st.size();
        int extra=m-(n-nc); //extra edges left after using n-nc edges out of m available edges
        if(extra>=nc-1)return nc-1;
        return -1;
    }
};