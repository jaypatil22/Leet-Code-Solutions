class Solution {
public:
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
    
    TrieNode* getRoot() {
        return root;
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
    void helper(vector<vector<char>> &board,TrieNode *root, unordered_set<string> &res,int i,int j,string &cur) {
        if(i<0 || j<0 || i>=board.size() || j>=board[0].size()) return;
        if(board[i][j]=='0') return;
        if(root->next[board[i][j]-'a'] != nullptr) {
            
            char r = board[i][j];
            cur.push_back(board[i][j]);
            board[i][j] = '0';
            root = root->next[r-'a'];
            if(root->is_end) res.insert(cur);
            helper(board,root,res,i-1,j,cur);
            helper(board,root,res,i,j-1,cur);
            helper(board,root,res,i+1,j,cur);
            helper(board,root,res,i,j+1,cur);
            cur.pop_back();
            board[i][j] = r;
        }
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie trie = Trie();
        for(string &s :words) {
            trie.insert(s);
        }
        TrieNode* root = trie.getRoot();
        unordered_set<string> res;
        for(int i=0;i<board.size();i++) {
            for(int j=0;j<board[0].size();j++) {
                string cur = "";
                helper(board,root,res,i,j,cur);
            }
        }
        vector<string> ret(res.begin(),res.end());
        return ret;
    }
};