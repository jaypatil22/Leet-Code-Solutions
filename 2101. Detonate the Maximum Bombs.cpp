class Solution {
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        unordered_map<int,vector<int>> m;
        for(int i=0;i<bombs.size();i++) {
            for(int j=0;j<bombs.size();j++) {
                if(i==j) continue;
                float xs = abs(bombs[i][0]-bombs[j][0]);
                xs *= xs;
                float ys = abs(bombs[i][1]-bombs[j][1]);
                ys *= ys;
                float dist = sqrt(xs+ys);
                if(dist <= bombs[i][2]) m[i].push_back(j);
            }
        }
        int res = 0, cur;
        for(int i=0;i<bombs.size();i++) {
            cur = 0;
            vector<int> deton;
            vector<int> visited(bombs.size(),0);
            deton.push_back(i);
            while(!deton.empty()) {
                vector<int>nd;
                for(int a : deton) {
                    if(!visited[a]) {
                        visited[a] = 1;
                        cur++;
                        for(int b : m[a]) nd.push_back(b);
                    }
                }
                deton = nd;
            }
            if(cur > res) res = cur;
            
        }
        return res;
    }
};