class Solution {
public:
    int compress(vector<char>& chars) {
        int c,pos=0;
        char prev;
        for(int i = 0;i<chars.size();i++) {
            if(i == 0) {
                prev = chars[0];
                c = 1;
            } else if (prev == chars[i]) {
                c++;
            } else {
                chars[pos++] = prev;
                if(c!=1) {
                   string cs = to_string(c);
                    for(char csc : cs) {
                        chars[pos++] = csc;
                    }

                }
                prev = chars[i];
                c = 1;
            }
        }
        chars[pos++] = prev;
        if(c!=1) {
            string cs = to_string(c);
            for(char csc : cs) {
                chars[pos++] = csc;
            }
        }
        return pos;
    }
};
