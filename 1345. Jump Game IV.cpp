class Solution {
public:
    int minJumps(vector<int>& arr) {
        unordered_map<int,vector<int>>jump;
        for(int i=0;i<arr.size();i++){
            jump[arr[i]].push_back(i);
        }
        queue<int>bfs;
        bfs.push(0);
        int step=0;
        vector<bool>seen(arr.size()+1,false);
        seen[0]=true;
        while(!bfs.empty()){
            int bfsSize=bfs.size();

            while(bfsSize--){
                auto pos=bfs.front();
                bfs.pop();
                
                if(pos==(arr.size()-1))return step;
                if(pos-1>=0&&!seen[pos-1]){
                    bfs.push(pos-1);
                    seen[pos-1]=true;
                }
                if(pos+1<arr.size()&&!seen[pos+1]){
                    bfs.push(pos+1);
                    seen[pos+1]=true;
                }
//                 for(int sameNum:jump[arr[pos]]){
//                     if(!seen[sameNum]){
//                         bfs.push(sameNum);
//                         seen[sameNum]=true;
//                     }

//                 }
                
                auto it = jump.find(arr[pos]);
                if (it == jump.end()) continue;
                for (int nxt : it->second)
                  if (!seen[nxt]){
                      bfs.push(nxt);
                      seen[nxt]=true;
                  } 
                jump.erase(it); // no longer needed.
                
            }
            step++;
        }
        return step;
    }
};