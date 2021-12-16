class Solution {
public:
    int countPoints(string rings) {
        vector<vector<int>> v(10,vector<int>(3,0));
        for(int i=0;i<rings.size();i+=2) {
            int color;
            if(rings[i]=='R') color = 0;
            else if(rings[i]=='G') color = 1;
            else color = 2;
            int col = rings[i+1]-'0';
            v[col][color] = 1;
        }
        int res = 0;
        for(int i=0;i<10;i++) {
            int cnt = 0;
            for(int j=0;j<3;j++) {
                if(v[i][j]) cnt++;
            }
            if(cnt==3) res++;
        }
        return res;
    }
};