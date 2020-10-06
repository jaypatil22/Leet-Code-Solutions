class Solution {
public:

    static bool greater( string a,  string b) {
        return a.size() > b.size();
    }

    bool subseq(const string &a, const string &b) {
        int j =0;
        for(int i =0;i<b.size()&&j<a.size();i++) {
            if(a[j] == b[i])
                j++;
        }
        return j == a.size();
    }

    int findLUSlength(vector<string>& strs) {
        sort(strs.begin(),strs.end(),greater);
        int res =-1;
        for(int i=0;i<strs.size();i++) {
            int j = i+1;
            //cout << strs[i].size() << " ";
            for(int j = 0;j<strs.size();j++) {
                if(strs[i].size() > strs[j].size() || i == j)
                    continue;
                if(subseq(strs[i],strs[j]))
                    goto here;
            }
            return strs[i].size();
            here:;

        }

        return res;
    }
};
