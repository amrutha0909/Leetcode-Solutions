class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        queue<pair<int,int>>q;
        q.push({0,0});
        vector<bool>visited(n,false);
        visited[0]=true;
        while(!q.empty()){
            int s=q.size();
            while(s--){
                auto it=q.front();
                q.pop();
                int node=it.first;
                int count=it.second;
                int steps=nums[node];
                if(node==n-1)return count;
                for(int i=1;i<=steps;i++){
                    int neigh=node+i;
                    if(neigh<n&&!visited[neigh]){
                        visited[neigh]=true;
                        q.push({neigh,count+1});
                    }
                }
            }
        }
        return -1;
    }
};