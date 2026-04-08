class Solution {
public:
    void backtrack(int open,int close,int n,vector<string>&res,string s){
        if(open==n && close==n){
            res.push_back(s);
            return;
        }
        if(open<n){
            backtrack(open+1,close,n,res,s+'(');
        }
        if(open>close){
            backtrack(open,close+1,n,res,s+')');
        }
        
    }
    vector<string> generateParenthesis(int n) {
        vector<string>res;
        string s="";
        backtrack(0,0,n,res,s);
        return res;
    }
};