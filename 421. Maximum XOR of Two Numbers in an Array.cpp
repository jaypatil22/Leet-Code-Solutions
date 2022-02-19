class TrieNode {
    public:
    TrieNode* child[2];
    TrieNode() {
        this->child[0] = nullptr;
        this->child[1] = nullptr;
    }
};
class Solution {
    TrieNode *root;
    void insert(int x) {
        TrieNode* temp = root;
        bitset<32> bs(x);
        
        for(int i=31;i>=0;i--) {
            if(!temp->child[bs[i]]) temp->child[bs[i]] = new TrieNode();
            temp = temp->child[bs[i]];
        }
    }
    
    int xr(int x) {
        bitset<32> bs(x);
        int res = 0;
        TrieNode* temp = root;
        for(int i=31;i>=0;i--) {
            if(temp->child[!bs[i]]) {
                res += (1<<i);
                temp = temp->child[!bs[i]];
            } else {
                temp = temp->child[bs[i]];
            }
        }
        return res;
    }
public:
    int findMaximumXOR(vector<int>& nums) {
        root= new TrieNode();
        for(int &a : nums) {
            insert(a);
        }
        int res = 0;
        for(int &a : nums) {
            // cout << res << " " << a << endl;
            res = max(res,xr(a));
        }
        return res;
    }
};