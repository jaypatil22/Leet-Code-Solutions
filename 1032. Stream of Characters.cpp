class StreamChecker {
public:
    struct TrieNode{
        char c = ' ';
        vector<TrieNode*> children;
        bool isEnd = false;
        TrieNode(char val,bool End = false) {
            c = val;
            isEnd = End;
            children = vector<TrieNode*>(26,nullptr);
        }
    };
    TrieNode* trie = new TrieNode(' ');
    vector<TrieNode*> check;
    string queries="";
    int longest_word = 0;
    StreamChecker(vector<string>& words) {
        for(string &word : words) {
            TrieNode* root = trie;
            if(word.size() > longest_word) longest_word = word.size();
            for(int i=word.size()-1;i>=0;i--) {
                if(root->children[word[i]-'a'] == nullptr) {
                    root -> children[word[i]-'a'] = new TrieNode(word[i]);
                }
                root = root ->children[word[i]-'a'];
                if(i==0) root -> isEnd = true;
            }
        }
    }
    
    bool query(char letter) {
        queries.insert(queries.begin(),letter);
        if(queries.size() > longest_word) queries.pop_back();
        TrieNode* cur = trie;
        for(auto it= queries.begin();it!=queries.end();it++) {
            if(cur->isEnd) return true;
            if(cur->children[*it-'a'] == nullptr) return false;
            cur = cur ->children[*it-'a'];
        }
        return cur->isEnd;
    }
};

static const auto speedup = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */