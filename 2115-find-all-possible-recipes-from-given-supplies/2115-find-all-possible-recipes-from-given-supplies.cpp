class Solution {
public:
    void checkRecipe(const string& recipe, vector<vector<string>>& ingredients,
                     unordered_set<string>& visited,
                     unordered_map<string, bool>& canMake,
                     unordered_map<string, int>& recipeIndex){
                        if(canMake.find(recipe)!=canMake.end())return;
                        auto it=recipeIndex.find(recipe);
                        if(it==recipeIndex.end()||visited.count(recipe)){
                            canMake[recipe]=false;
                            return;
                        }
                        visited.insert(recipe);
                        for(const string&ingredient:ingredients[it->second]){
                            checkRecipe(ingredient,ingredients,visited,canMake,recipeIndex);
                            if(!canMake[ingredient]){
                                canMake[recipe]=false;
                                return;
                            }
                        }
                        canMake[recipe]=true;
                     }
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string,int>recipeIndex;
        unordered_set<string>available(supplies.begin(),supplies.end());
        unordered_map<string,bool>canMake; 
        vector<string>ans;
        for(const string&supply:supplies)canMake[supply]=true;
        for(int idx=0;idx<recipes.size();idx++){
            recipeIndex[recipes[idx]]=idx;
        }
        for(const string&recipe:recipes){
            unordered_set<string>visited;
            checkRecipe(recipe,ingredients,visited,canMake,recipeIndex);
            if(canMake[recipe]){
                ans.push_back(recipe);
            }
        }
        return ans;
    }
};