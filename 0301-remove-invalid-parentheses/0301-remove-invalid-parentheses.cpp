class Solution {
public:
    bool isValid(string&sub){
        stack<char>stk;
        for(char c:sub){
            if(c=='(')stk.push(c);
            else if(c==')'){
                if(stk.empty())return false;
                stk.pop();
            }
        }
        return stk.empty();
    }
    vector<string> removeInvalidParentheses(string s) {
       unordered_set<string>seen;
       queue<string>q;
       vector<string>result;
       q.push(s);
       bool found=false;
       while(!q.empty()){
        string curr=q.front();
        q.pop();
        if(isValid(curr)){
            result.push_back(curr);
            found=true;
        }
        if(found)continue;
        for(int i=0;i<curr.size();i++){
            if(curr[i]!='(' && curr[i]!=')')continue;
            string sub=curr.substr(0,i)+curr.substr(i+1);
            if(seen.find(sub)==seen.end()){
                seen.insert(sub);
                q.push(sub);
            }
        }
       }
       return result;
    }
};