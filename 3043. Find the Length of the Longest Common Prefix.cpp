class TrieNode {
public:
    TrieNode* children[10];
    TrieNode() {
        for(int i=0;i<10;i++) {
            children[i] = nullptr;
        }
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void insert(int num) {
        TrieNode* node = root;
        string numStr = to_string(num);
        for(char c : numStr) {
            int idx = c - '0';
            if(node->children[idx]==nullptr) {
                node->children[idx] = new TrieNode();
            }
            node = node->children[idx];
        }
    }

    int findLongestPrefix(int num) {
        TrieNode* node = root;
        int res = 0;
        string numStr = to_string(num);
        for(char c : numStr) {
            int idx = c - '0';
            if(node->children[idx]!=nullptr) {
                res++;
                node = node->children[idx];
            } else {
                break;
            }
        }
        return res;
    }
};

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        Trie trie;

        for(int i : arr1) {
            trie.insert(i);
        }
        int res = 0;
        for(int i : arr2) {
            int lpre = trie.findLongestPrefix(i);
            res = max(res, lpre);
        }
        return res;
    }
};