class Solution {
public:
    string makeGood(string s) {
        string res="";
        if(s.size() <= 1)
            return s;
        string temp = s;
        while(temp.size() != 0) {
            string t1 = "";
            for(int i=0;i<temp.size();i++) {
                if(i == temp.size()-1) {
                    t1 += temp[i];
                    continue;
                }
                if(isupper(temp[i])) {
                    char t = tolower(temp[i]);
                    if(t == temp[i+1]) {
                        i++;
                    } else {
                        t1 += temp[i];
                    }
                } else {
                    char t = toupper(temp[i]);
                    if(t == temp[i+1]) {
                        i++;
                    } else {
                        t1 += temp[i];
                    }
                }
            }
            if(t1.size() == temp.size())
                return temp;
            else
                temp = t1;
        }
        return res;
    }
};
