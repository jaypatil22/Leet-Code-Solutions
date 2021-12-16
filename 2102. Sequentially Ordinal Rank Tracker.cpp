class SORTracker {
public:
    int cnt;
    struct greater{
        bool operator () (const pair<int,string>&a,const pair<int,string>&b) {
            if(a.first != b.first) {
                return a.first > b.first;
            } else {
                return a.second < b.second;
            }
        } 
    };
    struct lesser{
        bool operator ()(const pair<int,string>&a,const pair<int,string>&b) {
            if(a.first != b.first) {
                return a.first < b.first;
            } else {
                return a.second > b.second;
            }
        }
    };
    priority_queue<pair<int,string>, vector<pair<int,string>>, lesser> maxHeap;
    priority_queue<pair<int,string>, vector<pair<int,string>>, greater> minHeap;
    SORTracker() {
        cnt = 0;
    }
    
    void add(string name, int score) {
        minHeap.push({score,name});
        while(minHeap.size()>cnt) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    string get() {
        auto a = maxHeap.top();
        minHeap.push(a);
        maxHeap.pop();
        cnt++;
        return a.second;
        
    }
};

/**
 * Your SORTracker object will be instantiated and called as such:
 * SORTracker* obj = new SORTracker();
 * obj->add(name,score);
 * string param_2 = obj->get();
 */