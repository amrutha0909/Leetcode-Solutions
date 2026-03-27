class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>stk;
        int n=asteroids.size();
        for(int i=0;i<n;i++){
            if(asteroids[i]>0)stk.push(asteroids[i]);
            else{
                while(!stk.empty()&&stk.top()>0&&abs(asteroids[i])>stk.top()){
                    stk.pop();
                }
                if(!stk.empty()&&abs(asteroids[i])==stk.top()){
                    stk.pop();
                }
                else if(stk.empty()||stk.top()<0){
                    stk.push(asteroids[i]);
                }
            }
        }
        vector<int>ans;
        while(!stk.empty()){
            ans.push_back(stk.top());
            stk.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};