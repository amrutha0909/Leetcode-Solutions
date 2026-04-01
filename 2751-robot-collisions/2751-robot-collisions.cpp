class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        unordered_map<int,int>h_mpp;
        unordered_map<int,char>d_mpp;
        for(int i=0;i<positions.size();i++){
            h_mpp[positions[i]]=healths[i];
            d_mpp[positions[i]]=directions[i];
        }
        vector<int>ori=positions;
        //unordered_map<int,int>original;
        // for(int i=0;i<positions.size();i++){
        //     original[positions[i]]=i;
        // }
        sort(positions.begin(),positions.end());
        stack<int>st;
        for(int i=0;i<positions.size();i++){
            if(d_mpp[positions[i]]=='R'){
                st.push(i);
            }
            else{
                while(!st.empty()&&d_mpp[positions[st.top()]]=='R'){
                    if(h_mpp[positions[st.top()]]<h_mpp[positions[i]]){
                        h_mpp[positions[i]]--;
                        //original.erase(positions[st.top()]);
                        h_mpp.erase(positions[st.top()]);
                        st.pop();
                    }
                    else if(h_mpp[positions[st.top()]]>h_mpp[positions[i]]){
                        //original.erase(positions[i]);
                        h_mpp.erase(positions[i]);
                        h_mpp[positions[st.top()]]--;
                        break;
                    }
                    else{
                        h_mpp.erase(positions[st.top()]);
                        h_mpp.erase(positions[i]);
                        //original.erase(positions[st.top()]);
                        //original.erase(positions[i]);
                        st.pop();
                        break;
                    }
                }
            }
        }
        vector<int>ans;
        for(int i=0;i<ori.size();i++){
            if(h_mpp.find(ori[i])!=h_mpp.end()){
                ans.push_back(h_mpp[ori[i]]);
            }
        }     
        return ans;
    }
};