class Solution {
public:
    bool canJump(vector<int>& nums) {
        queue<int>q;
        int n=nums.size();
        vector<bool>visited(n,false);
        q.push(0);
        visited[0]=true;
        while(!q.empty()){
            int s=q.size();
            while(s--){
                auto node=q.front();
                q.pop();
                int steps=nums[node];
                if(node==n-1)return true;
                for(int i=1;i<=steps;i++){
                    if(node+i<n&&!visited[node+i]){
                        visited[node+i]=true;
                        q.push(node+i);
                    }
                }
            }
        }
        return false;
    }   
};