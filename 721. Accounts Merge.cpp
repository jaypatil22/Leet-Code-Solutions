class Solution {
public:
    unordered_set<string> visited;
    unordered_map<string, vector<string>> adjacent;
    
    void dfs(vector<string> &merged,string email) {
        visited.insert(email);
        merged.push_back(email);
        
        for(string neighbour : adjacent[email]) {
            if(visited.find(neighbour) == visited.end()) {
                dfs(merged,neighbour);
            }
        }
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        
        for(vector<string>& account : accounts) {
            int m = account.size();
            
            string firstEmail = account[1];
            for(int i=2;i<m;i++) {
                adjacent[firstEmail].push_back(account[i]);
                adjacent[account[i]].push_back(firstEmail);
            }
        }
        vector<vector<string>> res;
        for(vector<string> &account : accounts) {
            string accountName = account[0];
            string firstEmail = account[1];
            
            if(visited.find(firstEmail) == visited.end()) {
                vector<string> merged;
                
                merged.push_back(accountName);
                dfs(merged,firstEmail);
                
                sort(merged.begin()+1,merged.end());
                res.push_back(merged);
            }
        }
        return res;
    }
};