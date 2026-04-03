class Solution {
public:
    // Approach : Collect the initial of each word and the word itself in a set.
    // also for each initial collect the positions, so as to dfs only those locations
    // use set.lower_bound() inside dfs to find if curr string exist in the set,
    // if yes then push into ans,
    // backtrack when curr.size()>=largest string size starting with current intial 
    // use a viisited array to keep track of visited posistions 
    // during the dfs to rule out possibility of repeated words.
    // also keep the ans into a set so that two positions with same
    // initial letters donot give the same word.

    int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
    void dfs(vector<vector<char>>& b,set<string>&st,int r,int c,string&curr,set<string>&ans,int lsz,vector<vector<int>>&vis){
        auto it=st.lower_bound(curr);
        if (it!=st.end()&&*it==curr)ans.insert(curr);
        if((int)curr.size()==lsz)return;
        vis[r][c] = 1;
        for (int k = 0; k < 4; k++){
            int nr = r + dir[k][0];
            int nc = c + dir[k][1];
            if (nr>=0&&nc>=0&&nr<b.size()&&nc<b[0].size()&&!vis[nr][nc]){
                curr.push_back(b[nr][nc]);
                dfs(b,st,nr,nc,curr,ans,lsz,vis);
                curr.pop_back();
            }
        }
        vis[r][c] = 0; // backtrack
    }

    vector<string> findWords(vector<vector<char>>& b, vector<string>& words) {        
        int l=b.size();
        int k=b[0].size();
        unordered_map<char,set<string>>mpp;
        for(auto w:words)mpp[w[0]].insert(w);
        // for(auto [w,st]:mpp){
        //     for(auto i:st)cout<<i<<" ";
        //     cout<<endl;
        // }
        unordered_map<char,vector<pair<int,int>>>pos;
        for(int i = 0;i < b.size();i++){
            for(int j = 0;j < b[0].size();j++){
                char ch = b[i][j];
                pos[ch].push_back({i,j});
            }
        }
        set<string>ans;
        for(auto m:mpp){
            char start = m.first;
            set<string>&st = m.second;
            int lsz = 0; // find longest word length for this starting char
            for (auto &w : st) lsz = max(lsz, (int)w.size());
            // cout<<lsz;
            for(auto p:pos[start]){
                int i = p.first;
                int j = p.second;
                vector<vector<int>>vis(l,vector<int>(k,0));
                string curr(1, b[i][j]);
                // cout<<curr<<endl;
                dfs(b,st,i,j,curr,ans,lsz,vis);
            }
        }
        vector<string>v(ans.begin(),ans.end());
        return v;
    }
};