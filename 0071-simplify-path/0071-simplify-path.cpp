class Solution {
public:
    string simplifyPath(string path) {
        vector<string>stk;
        string token;
        stringstream ss(path);
        while(getline(ss,token,'/')){
            if(token==""||token==".")continue;
            if(token==".."){
                if(!stk.empty())stk.pop_back();
            }
            else{
                stk.push_back(token);
            }
        }
        string ans="";
        for(string dir:stk){
            ans+="/"+dir;
        }
        return ans.empty()?"/":ans;
    }
};