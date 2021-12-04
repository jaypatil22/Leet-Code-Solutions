class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int i=1,j=0;
        vector<string> res;
        while(j<words.size()) {
            int char_count = words[j].size(),space_count = 0;
            while(i<words.size() && char_count+words[i].size()+space_count+1 <= maxWidth) {
                char_count += words[i].size();
                space_count++;
                i++;
            }
            string row = "";
            if(i>=words.size()) {
                while(i!=j) {
                    row += words[j++];
                    row+=' ';
                }
                while(row.size()<maxWidth) {
                    row += ' ';
                }
                row = row.substr(0,maxWidth);
            } else if(space_count) {
                int spaces = (maxWidth-char_count)/space_count;
                int rem = (maxWidth-char_count)%space_count;
                while(i != j) {
                    row += words[j];
                    if(space_count) {
                        string sp(spaces,' ');
                        row+=sp;
                        space_count--;
                        if(rem) {
                            row += " ";
                            rem--;
                        }
                    }
                    
                    j++;
                }
            } else {
                row = words[j];
                string sp(maxWidth-words[j].size(),' ');
                row += sp;
                j++;
            }
            i++;
            res.push_back(row);
        }
        return res;
    }
};