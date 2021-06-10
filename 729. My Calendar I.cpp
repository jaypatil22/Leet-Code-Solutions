class MyCalendar {
public:
    map<int,int> m;
    MyCalendar() {
        m.clear();
    }
    
    bool book(int start, int end) {
        auto a = m.lower_bound(start);
        if(a!=m.end() && (end > a->first)) return false;
        if(a!=m.begin() && (start < (--a)->second)) return false;
        m.insert({start,end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */