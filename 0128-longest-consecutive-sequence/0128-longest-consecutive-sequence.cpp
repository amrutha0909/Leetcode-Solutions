class Solution {
public:
    void dfs(int i,unordered_map<int,vector<int>>&adj,unordered_set<int>&visited,int&count){
        visited.insert(i);
        count++;
        for(auto&it:adj[i]){
            if(visited.count(it)==0){
                dfs(it,adj,visited,count);
            }
        }
    }
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,vector<int>>adj;
        unordered_set<int>s(nums.begin(),nums.end());
        for(int num:nums){
            if(s.count(num-1)){
                adj[num].push_back(num-1);
            }
            if(s.count(num+1)){
                adj[num].push_back(num+1);
            }
        }
        unordered_set<int>visited;
        int maxCount=0;
        for(int i=0;i<nums.size();i++){
            if(visited.count(nums[i])==0){
                int count=0;
                dfs(nums[i],adj,visited,count);
                maxCount=max(maxCount,count);
            }
        }
        return maxCount;
    }
};