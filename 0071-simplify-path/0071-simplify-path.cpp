class Solution {
public:
    string simplifyPath(string path) {
        vector<string>stack;
        string token;
        stringstream ss(path);
        while(getline(ss,token,'/')){
            if(token==""||token==".")continue;
            if(token==".."){
                if(!stack.empty()){
                    stack.pop_back();
                }
            }
            else{
                stack.push_back(token);
            }
        }
        string ans="";
        for(string dir:stack){
            ans+="/"+dir;
        }
        return ans.empty()?"/":ans;
    }
};