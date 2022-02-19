class TrieNode {
    public:
    TrieNode* child[26]={nullptr};
    bool is_end = false;
};
class WordDictionary {
public:
    TrieNode* root;
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* temp = root;
        for(int i=0;i<word.size();i++) {
            if(!temp->child[word[i]-'a']) {
                temp->child[word[i]-'a'] = new TrieNode();
            }
            temp = temp ->child[word[i]-'a'];
            if(i==word.size()-1) temp->is_end = true;
        }
    }
    
    bool search(string word) {
        return helper(word,0,root);
    }
    
    bool helper(string &word, int i,TrieNode* t) {
        if(i==word.size()) {
            return t->is_end;
        }
        bool res = false;
        if(word[i]!='.') {
            if(!t->child[word[i]-'a']) return false;
            return helper(word,i+1,t->child[word[i]-'a']);
        } else {
            for(int j=0;j<26;j++) {
                if(t->child[j]) {
                    res |= helper(word,i+1,t->child[j]);
                }
            }
            return res;
        }
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */