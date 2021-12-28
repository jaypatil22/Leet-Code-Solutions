class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        if(rows==1) return encodedText;
        string res = "";
        int cols = encodedText.size()/rows;
        for(int i=0;i<cols;i++) {
            for(int j=i;j<encodedText.size();j+=(cols+1)) {
                res += encodedText[j];
            }
        }
        // cout << encodedText.size() << " " << rows << endl;
        while(res.back()==' ') {
            res.pop_back();
        }
        return res;
    }
};