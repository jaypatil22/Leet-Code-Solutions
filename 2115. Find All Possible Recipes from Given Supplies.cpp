class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_set<string> sup;
        for(string s : supplies) sup.insert(s);
        unordered_map<string,vector<string>> graph;
        unordered_map<string,int> indeg;
        for(int i=0;i<ingredients.size();i++) {
            for(int j=0;j<ingredients[i].size();j++) {
                if(sup.find(ingredients[i][j])==sup.end()) {
                    graph[ingredients[i][j]].push_back(recipes[i]);
                    indeg[recipes[i]]++;
                }
            }
        }
        queue<string> q;
        vector<string> res;
        for(int i=0;i<recipes.size();i++) {
            if(indeg[recipes[i]]==0) {
                q.push(recipes[i]);
                res.push_back(recipes[i]);
            }
        }
        while(!q.empty()) {
            int c = q.size();
            while(c) {
                string s = q.front();q.pop();
                for(string a : graph[s]) {
                    indeg[a]--;
                    if(indeg[a]==0) {
                        q.push(a);
                        res.push_back(a);
                    }
                }
                c--;
            }
        }
        return res;
    }
};