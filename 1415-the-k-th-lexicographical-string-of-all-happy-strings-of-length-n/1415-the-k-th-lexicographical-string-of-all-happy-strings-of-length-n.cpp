class Solution {
public:
    vector<char>s={'a','b','c'};
    void backtrack(int n, vector<string>&res, string&curr){
        if(curr.size()==n){
            res.push_back(curr);
            return;
        }
        for(int i=0;i<s.size();i++){
            if(!curr.empty() && curr.back()==s[i])continue;
            curr.push_back(s[i]);
            backtrack(n,res,curr);
            curr.pop_back();
        }

    }
    string getHappyString(int n, int k) {
        vector<string>res;
        string curr="";
        backtrack(n,res,curr);
        if(k>res.size())return "";
        return res[k-1];
    }
};