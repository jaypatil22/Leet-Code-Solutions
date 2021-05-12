class WordFilter {
public:
    WordFilter(vector<string>& words) {
        prefixTrie = new Trie();
        suffixTrie = new Trie();
        for(int i=0;i< words.size();i++) {
            insert(i,prefixTrie,words[i]);
            reverse(words[i].begin(),words[i].end());
            insert(i,suffixTrie,words[i]);
        }
    }
    
    int f(string prefix, string suffix) {
        Trie *pT= prefixTrie;
        Trie *sT = suffixTrie;
        
        for(char c : prefix) {
            pT = (pT->children[c-'a']);
            if(!pT)
                return -1;
        }
        reverse(suffix.begin(),suffix.end());
        for(char c : suffix) {
            sT = (sT->children[c-'a']);
            if(!sT)
                return -1;
        }
        
        int i=pT->words.size()-1;
        int j=sT->words.size()-1;
        
        while(i>=0&&j>=0) {
            if((pT->words)[i]==sT->words[j]) {
                return pT->words[i];
            } else if(pT->words[i]>sT->words[j]) {
                i--;
            } else {
                j--;
            }
        }
        return -1;
    }
private:
    struct Trie {
        vector<int> words;
        vector<Trie*> children;

        Trie() {
            children = vector<Trie*> (26,nullptr);
        }
    };
    
    void insert(int i,Trie* head,string word) {
        (head->words).push_back(i);
        for(char c : word) {
            if(!(head->children)[c-'a']) {
                (head->children)[c-'a'] = new Trie();
            }
            head = (head->children)[c-'a'];
            (head->words).push_back(i);
        }
    }
    Trie *suffixTrie,*prefixTrie;
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */