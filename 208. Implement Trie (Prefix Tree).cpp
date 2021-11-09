class TrieNode {
    public:
    TrieNode *next[26];
    bool is_end;
    TrieNode(bool b= false) {
        is_end = b;
        memset(next,0,sizeof(next));
    }
};
class Trie {
public:
    TrieNode *root;
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode *temp = root;
        for(int i=0;i<word.size();i++) {
            if(temp->next[word[i]-'a'] == nullptr) {
                temp->next[word[i]-'a'] = new TrieNode();
            }
            temp = temp->next[word[i]-'a'];
        }
        temp->is_end = true;
    }
    
    bool search(string word) {
        TrieNode* res = find(word);
        return res != nullptr && res->is_end;
    }
    
    bool startsWith(string prefix) {
        return find(prefix) != nullptr;
    }
    private:
    TrieNode* find(string key) {
        TrieNode* temp = root;
        for(int i=0;i<key.size();i++) {
            if(temp->next[key[i]-'a'] == nullptr) return nullptr;
            temp = temp->next[key[i]-'a'];
        }
        return temp;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */