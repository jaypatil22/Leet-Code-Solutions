class Solution {
public:
    string reorderSpaces(string text) {
        if(text.size() <= 1)
            return text;
        int spaces=0,wc = 0;
        vector<string> words;
        for(auto a : text) {
            if(a == ' ')
                spaces++;
        }
        for(int i =0;i<text.size();i++) {
            if(text[i]!= ' ') {
                words.push_back("");
                while(text[i] != ' '&&i<text.size()) {
                    words[wc] += text[i];
                    i++;
                }
                wc++;
            }
        }
        string res;
        int ns =0;
        if(words.size() > 1 )
           ns = spaces/(words.size()-1);
        spaces -= ns*(words.size()-1);

        for(auto i=0;i< words.size();i++) {
            res += words[i];
            if(i == words.size()-1)
                continue;
            for(int i =0;i<ns;i++)
                res+=' ';
        }
        here : ;
        for(int  i=0;i<spaces;i++)
            res+=' ';
        return res;
    }
};
