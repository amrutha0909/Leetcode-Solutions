class RandomizedSet {
public:
    unordered_map<int,int>st;
    vector<int>v;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(st.find(val)==st.end()){
            v.push_back(val);
            st[val]=v.size()-1;
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if(st.find(val)==st.end())return false;
        auto it=st.find(val);
        v[it->second]=v.back();
        v.pop_back();
        st[v[it->second]]=it->second;
        st.erase(val);
        return true;
    }
    
    int getRandom() {
        return v[rand()%v.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */