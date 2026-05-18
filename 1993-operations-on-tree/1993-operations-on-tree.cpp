class LockingTree {
public:
    //maintain a map of ancestors and descendents
    //lock the tree->check if node exists in map, it yes return false, else put the node in a map with uid.
    //unlock->check if node exists in map and then delete it if uids match, else return false.
    //lock the current node if unlocked,but first check for all ancestors to make sure they are unlocked and check for all descendents to make sure atleast one is locked=>then unlock it
    unordered_map<int,int>locks;
    unordered_map<int,vector<int>>descendent;
    // unordered_map<int,vector<int>>ancestors;
    //vector<int>descendent(parent.size()+1);
    vector<int>parent;
    LockingTree(vector<int>& parent) {
        for(int i=0;i<parent.size();i++){
            if(parent[i]!=-1)descendent[parent[i]].push_back(i);
        }
        this->parent=parent;
    }
    
    bool lock(int num, int user) {
        if(locks.find(num)==locks.end()){
            locks[num]=user;
            return true;
        }
        return false;
    }
    
    bool unlock(int num, int user) {
        if(locks.find(num)!=locks.end() && locks[num]==user){
            locks.erase(num);
            return true;
        }
        return false;
    }
    bool descendentLocked(int num){
        bool found=false;
        for(auto x:descendent[num]){
            if(locks.find(x)!=locks.end()){
                found=true;
                unlock(x,locks[x]);
            }
            if(descendentLocked(x)){
                found=true;
            }
        }
        return found;
    }
    bool ancestorUnlocked(int num,vector<int>&parent){
        if(parent[num]==-1)return true;
        if(locks.find(parent[num])!=locks.end())return false;
        return ancestorUnlocked(parent[num],parent);
    }
    bool upgrade(int num, int user) {
        if(locks.find(num)!=locks.end())return false;
        if(ancestorUnlocked(num,parent)){
            if(descendentLocked(num)){
                if(lock(num,user))return true;
            }
        }
        
        return false;
    }
};

/**
 * Your LockingTree object will be instantiated and called as such:
 * LockingTree* obj = new LockingTree(parent);
 * bool param_1 = obj->lock(num,user);
 * bool param_2 = obj->unlock(num,user);
 * bool param_3 = obj->upgrade(num,user);
 */