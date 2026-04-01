class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        
        unordered_map<int,int> h_mpp;   // position -> health
        unordered_map<int,char> d_mpp;  // position -> direction
        
        int n = positions.size();
        
        for(int i = 0; i < n; i++){
            h_mpp[positions[i]] = healths[i];
            d_mpp[positions[i]] = directions[i];
        }

        vector<int> ori = positions;

        unordered_map<int,int> original; // track alive
        for(int i = 0; i < n; i++){
            original[positions[i]] = i;
        }

        sort(positions.begin(), positions.end());

        stack<int> st; // stores indices of sorted positions

        for(int i = 0; i < n; i++){
            
            int currPos = positions[i];

            // ✅ only push RIGHT moving robots
            if(d_mpp[currPos] == 'R'){
                st.push(i);
            }
            else{ // 'L'
                
                // ✅ handle multiple collisions
                while(!st.empty() && d_mpp[positions[st.top()]] == 'R'){
                    
                    int topPos = positions[st.top()];

                    if(h_mpp[topPos] < h_mpp[currPos]){
                        // top robot dies
                        h_mpp[currPos]--;
                        original.erase(topPos);
                        h_mpp.erase(topPos);
                        st.pop();
                    }
                    else if(h_mpp[topPos] > h_mpp[currPos]){
                        // current robot dies
                        h_mpp[topPos]--;
                        original.erase(currPos);
                        h_mpp.erase(currPos);
                        break;
                    }
                    else{
                        // both die
                        original.erase(topPos);
                        original.erase(currPos);
                        h_mpp.erase(topPos);
                        h_mpp.erase(currPos);
                        st.pop();
                        break;
                    }
                }
            }
        }

        vector<int> ans;

        for(int i = 0; i < ori.size(); i++){
            if(original.find(ori[i]) != original.end()){
                ans.push_back(h_mpp[ori[i]]);
            }
        }

        return ans;
    }
};