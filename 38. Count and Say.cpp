class Solution {
public:

    string countAndSay(int n) {
        if(n == 1)
            return "1";
        int count = 1;
        string res = "1";
        while(count != n) {
            int c = 1;
            char prev = res[0];
            string temp = "";
            for(int i = 0;i<res.size();i++) {
                if(i == 0) {
                    prev = res[0];
                    c=1;
                } else if(res[i] == prev) {
                    c++;
                } else {
                    temp += to_string(c) + prev;
                    prev = res[i];
                    c = 1;
                }
            }
            temp += to_string(c)+prev;
            res = temp;
            count++;
        }
        return res;
    }
};
