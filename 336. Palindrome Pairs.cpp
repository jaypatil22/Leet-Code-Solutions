class TrieNode {
    public:
    vector<int> palins;
    int idx;
    vector<TrieNode*> next;
    TrieNode() {
        idx = -1;
        next.resize(26,nullptr);
    }
};
class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> res;
        TrieNode* root = new TrieNode();
        for(int i=0;i<words.size();i++) {
            add(words[i],i,root);
        }
        for(int i=0;i<words.size();i++) {
            search(words[i],i,root,res);
        }
        return res;
    }
    
    void add(string &word,int i, TrieNode* root) {
        TrieNode* node = root;
        for(int j = word.size()-1;j>=0;j--) {
            if(isPalindrome(word,0,j)) {
                node->palins.push_back(i);
            }
            if(!node->next[word[j]-'a']) {
                node->next[word[j]-'a'] = new TrieNode();
            }
            node = node->next[word[j]-'a'];
        }
        node->idx = i;
        node->palins.push_back(i);
    }
    
    void search(string &word,int i,TrieNode* root,vector<vector<int>> &res) {
        TrieNode* node = root;
        int n = word.size();
        for(int j=0;j<n && node;j++) {
            if(node->idx >=0 && node->idx != i && isPalindrome(word,j,n-1)) {
                res.push_back({i,node->idx});
            }
            node = node->next[word[j]-'a'];
        }
        if(node) {
            for(int a : node->palins) {
                if(a !=i) {
                    res.push_back({i,a});
                }
            }
        }
    }
    
    bool isPalindrome(string &word,int l,int r) {
        while(l<r) {
            if(word[l] != word[r]) return false;
            l++,r--;
        }
        return true;
    }
};