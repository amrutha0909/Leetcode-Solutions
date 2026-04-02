class Solution {
public:
    int jump(vector<int>& nums) {
        queue<int>q;
        q.push(0);
        int ans=0;
        vector<bool>visited(nums.size(),false);
        while(!q.empty()){
            int len=q.size();
            for(int i=0;i<len;i++){
                int index=q.front();
                q.pop();
                if(index==nums.size()-1)return ans;
                visited[index]=true;
                int steps=nums[index];
                for(int i=index;i<=index+steps;i++){
                    if(i<nums.size()&&!visited[i]){
                        visited[i]=true;
                        q.push(i);
                    }
                }
            }
            ans++;
        }
        return ans;
    }
};