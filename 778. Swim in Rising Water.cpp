class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        set<tuple<int,int,int>> s;
        s.insert({grid[0][0],0,0});
        vector<vector<bool>> visited(grid.size(),vector<bool>(grid[0].size(),false));
        // visited[0][0] = true;
        int res = INT_MIN;
        while(!s.empty()) {
            auto it = *s.begin();
            s.erase(s.begin());
            if(visited[get<1>(it)][get<2>(it)]) continue;
            res = max(res,get<0>(it));
            visited[get<1>(it)][get<2>(it)] = true;
            if(get<1>(it)==grid.size()-1 && get<2>(it)==grid[0].size()-1) return res;
            if(get<1>(it)+1<grid.size()) s.insert({grid[get<1>(it)+1][get<2>(it)],get<1>(it)+1,get<2>(it)});
            if(get<1>(it)-1>=0) s.insert({grid[get<1>(it)-1][get<2>(it)],get<1>(it)-1,get<2>(it)});
            if(get<2>(it)+1<grid[0].size()) s.insert({grid[get<1>(it)][get<2>(it)+1],get<1>(it),get<2>(it)+1});
            if(get<2>(it)-1>=0) s.insert({grid[get<1>(it)][get<2>(it)-1],get<1>(it),get<2>(it)-1});
            
        }
        return res;
    }
};