class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1)
            return s;
        vector<string> v(numRows,"");
        int pos = 0;
        while(pos < s.size()) {
            for(int i = 0;i<numRows && pos < s.size();i++,pos++) {
                v[i] += s[pos];
            }
            int nr = numRows-2;
            while(nr > 0 && pos < s.size()) {
                v[nr] += s[pos];
                pos++;
                nr--;

            }
        }
        string res;
        for(string a : v) {
            //cout << a << " \n";
            res += a;
        }
        return res;
    }
};
