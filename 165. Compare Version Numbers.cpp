class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> v1,v2;
        int i=0;
        while(i<version1.size()) {
            string n = "";
            while(i<version1.size() &&version1[i]!='.') {
                n += version1[i];
                i++;
            }
            int num = stoi(n);
            v1.push_back(num);
            i++;
        }
        i=0;
        while(i<version2.size()) {
            string n = "";
            while(i<version2.size() &&version2[i]!='.') {
                n += version2[i];
                i++;
            }
            int num = stoi(n);
            v2.push_back(num);
            i++;
        }
        if(v1.size() > v2.size()) {
            while(v2.size()!=v1.size()) {
                v2.push_back(0);
            }
        } else {
            while(v1.size()!=v2.size()) {
                v1.push_back(0);
            }
        }
        if(v1 < v2) return -1;
        else if(v2 < v1) return 1;
        return 0;
    }
};