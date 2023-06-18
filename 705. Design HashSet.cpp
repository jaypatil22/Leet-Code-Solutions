class MyHashSet {
public:
    vector<list<int>> arr;//list of key and value
    int siz=1100;
    
    MyHashSet() {
          arr.resize(siz);
    }
    
      list<int>::iterator search(int key,list<int> &x)
    {
        list<int>::iterator it;
        for(it=x.begin();it!=x.end();it++)
        {
            if(*it==key)
                return it;
        }
        return it;
    }
    
    void add(int key) {
        int i=key%siz;
        list<int>::iterator it;
        it=search(key,arr[i]);
        if(it!=arr[i].end())
        {
            *it=key;
        }
        else
        {
            arr[i].push_back(key);
        }
    }
    
    void remove(int key) {
        int i=key%siz;
        list<int>::iterator it;
        it=search(key,arr[i]);
        if(it!=arr[i].end())
        {
           arr[i].erase(it);
        }
    }
    
    bool contains(int key) {
        int i=key%siz;
        list<int>::iterator it;
        it=search(key,arr[i]);
        if(it!=arr[i].end())
        {
            return true;
        }
        else
        {
            return false;}
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */