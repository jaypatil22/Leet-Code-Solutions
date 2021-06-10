class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(),products.end());
        int a = 0,b=products.size()-1;
        vector<vector<string>> res(searchWord.size());
        for(int i=0;i<searchWord.size() && a<=b;i++) {
            while(a<=b && (products[a].size()<=i || products[a][i]!=searchWord[i])) {
                a++;
            }
            
            while(a<=b && (products[b].size()<=i || products[b][i]!=searchWord[i])) {
                b--;
            }
            
            for(int j=a;j<=b && j<a+3;j++) {
                res[i].push_back(products[j]);
            }
        }
        return res;
    }
};