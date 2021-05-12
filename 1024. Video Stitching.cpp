class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        sort(begin(clips),end(clips));
        int res=0;
        for(int i=0,st=0,end=0;end<T;res++,st=end) {
            for(;i<clips.size() && st >= clips[i][0];i++) {
                end = max(end,clips[i][1]);
            }
            if(st==end) return -1;
        }
        return res;
    }
};