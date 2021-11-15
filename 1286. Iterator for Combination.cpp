class CombinationIterator {
public:
    string st;
    vector<string> combinations;
    int length;
    int cnt = 0;
    void helper(int i, int length,string s) {
        if(s.size() >= length) return;
        s += st[i];
        if(s.size()==length) combinations.push_back(s);
        for(int j=i+1;j<st.size();j++) {
            helper(j,length,s);
        }
    }
    CombinationIterator(string characters, int combinationLength) {
        st = characters;
        length = combinationLength;
        for(int i=0;i<characters.size();i++) {
            helper(i,length,"");
        }
    }
    
    string next() {
        return combinations[cnt++];
    }
    
    bool hasNext() {
        if(cnt>=combinations.size()) return false;
        else return true;
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */