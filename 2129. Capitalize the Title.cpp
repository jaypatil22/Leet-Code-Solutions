class Solution {
public:
    string capitalizeTitle(string title) {
        int i = 0;
        while(i<title.size()) {
            if(title[i]==' ') i++;
            int j = i;
            while(j<title.size() && title[j]!=' ') j++;
            if(j-i > 2) {
                title[i] = toupper(title[i]);
                i++;
                while(i!=j) {
                    title[i] = tolower(title[i]);
                    i++;
                }
            } else {
                title[i] = tolower(title[i]);
                i++;
                title[i] = tolower(title[i]);
                i++;
            }
        }
        return title;
    }
};