class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        const int SEARCHING = 1;
        const int AVAILABLE = 2;
        vector<string> res;
        map<string, vector<string>*> adj;
        map<string, int> book;
    
        for(int i=0; i<recipes.size(); i++){
            adj[recipes[i]] = &(ingredients[i]);
        }
        for(int i=0; i<supplies.size(); i++){
            adj[supplies[i]];
        }

        function<bool(string)> cycle = [&](string supply){
            if(adj.find(supply) == end(adj))
                return true;
            if(!adj[supply])
                return false;
            if(book[supply] == SEARCHING)
                return true;
            if(book[supply] == AVAILABLE)
                return false;
            
            book[supply] = SEARCHING;
            for(auto ingredient: *adj[supply])
                if(cycle(ingredient)) return true;
            book[supply] = AVAILABLE;
            if(find(begin(recipes), end(recipes), supply) != end(recipes)) res.push_back(supply);
            return false;
        };
        for(auto recipe: recipes){
            cycle(recipe);
        }
        return res;
    }
};