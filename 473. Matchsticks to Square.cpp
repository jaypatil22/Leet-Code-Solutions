class Solution {
public:
    bool dfs(vector<int> &matchsticks,int index,vector<int> sides,long long target) {
        if(index==matchsticks.size()) {
            if(sides[0]==sides[2] && sides[2]==sides[1] && sides[1]==sides[3]) return true;
            return false;
        }
        for(int j=0;j<4;j++) {
            if(sides[j]+matchsticks[index] > target) continue;
            
            int i = j;
            while(--i >= 0) {
                if(sides[i]==sides[j]) break;
            }
            if(i!=-1) continue;
            sides[j]+=matchsticks[index];
            if(dfs(matchsticks,index+1,sides,target)) return true;
            sides[j]-=matchsticks[index];
        }
        return false;
    }
    bool makesquare(vector<int>& matchsticks) {
        vector<int> sides(4,0);
        long long sum = 0;
        for(int i=0;i<matchsticks.size();i++) {
            sum += matchsticks[i];
        }
        if(sum%4) return false;
        sum/=4;
        sort(matchsticks.rbegin(),matchsticks.rend());
        if(matchsticks[0] > sum) return false;
        return dfs(matchsticks,0,sides,sum);
    }
};