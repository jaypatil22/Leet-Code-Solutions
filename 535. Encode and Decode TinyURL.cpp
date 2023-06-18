class Solution {
public:
    unordered_map<string,string> code2url,url2code;
    vector<char> ch;
    Solution() {
        for(char i='0';i<='9';i++) ch.push_back(i);
        for(char i = 'a';i<='z';i++) ch.push_back(i);
        for(char i = 'A';i<='Z';i++) ch.push_back(i);
    }
    
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        int sz = ch.size();
        while(url2code.find(longUrl)==url2code.end()) {
            string code = "";
            for(int i=0;i<6;i++) {
                int ind = rand()%sz;
                code += ch[ind];
            }
            // cout << code << endl;
            if(code2url.find(code)==code2url.end()) {
                code2url[code] = longUrl;
                url2code[longUrl] = code;
            }
        }
        return "http://tinyurl.com/" + url2code[longUrl];
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        string code = "";
        for(int i=0;i<shortUrl.size();i++) {
            code += shortUrl[i];
            if(shortUrl[i]=='/') {
                code = "";
            }
        }
        return code2url[code];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));