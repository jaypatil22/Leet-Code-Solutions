class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int res = 0, row=0, col=0,face=0;
        map<int,set<int>> row_map,col_map;
        for(int i=0; i<obstacles.size(); i++) {
            int o_row = obstacles[i][1], o_col=obstacles[i][0];
            row_map[o_row].insert(o_col);
            col_map[o_col].insert(o_row);
        }
        for(int i=0;i<commands.size();i++) {
            if(commands[i]==-1) {
                face += 1;
                face %= 4;
            } else if(commands[i]==-2) {
                face += 3;
                face %= 4;
            } else {
                if(face==0) {
                    // cout << "moving up";
                    int up_obst = INT_MAX;
                    if(!col_map[col].empty()) {
                        auto it = col_map[col].upper_bound(row);
                        if(it != col_map[col].end()) up_obst = *it;
                    }
                    // cout << "up obstacle" << up_obst;
                    row = min(row+commands[i],up_obst-1);
                    res = max(res, (row*row)+(col*col));
                } else if(face==1) {
                    // cout << "moving right";
                    int right_obst = INT_MAX;
                    if(!row_map[row].empty()) {
                        auto it = row_map[row].upper_bound(col);
                        if(it != row_map[row].end()) right_obst = *it;
                    }
                    // cout << "right obstacle" << right_obst;
                    col = min(col+commands[i],right_obst-1);
                    res = max(res, (row*row)+(col*col));
                } else if(face==2) {
                    // cout << "moving down";
                    // for(auto it=col_map[col].begin();it !=col_map[col].end();it++) {
                    //     cout << *it << " ";
                    // }
                    // cout << endl;
                    int down_obst = INT_MIN;
                    if(!col_map[col].empty()){
                        auto it = col_map[col].lower_bound(row);
                        // cout << *col_map[col].end();
                        if(it != col_map[col].begin()) it = prev(it);
                        // cout << *it;
                        // cout << *col_map[col].begin();
                        if(*it < row) down_obst = *it;
                    }
                    // cout << "down obstacle" << down_obst;
                    row = max(row-commands[i],down_obst+1);
                    res = max(res, (row*row)+(col*col));
                } else {
                    // cout << "moving left";
                    int left_obst = INT_MIN;
                    if(!row_map[row].empty()){
                        auto it = row_map[row].lower_bound(col);
                        if(it != row_map[row].begin()) it = prev(it);
                        if(*it < col) left_obst = *it;
                    }
                    // cout << "left obstacle" << left_obst;
                    col = max(col-commands[i],left_obst+1);
                    res = max(res, (row*row)+(col*col));
                }
            }
            // cout << face;
            // cout << col << " " << row << endl;

        }
        return res;
    }
};