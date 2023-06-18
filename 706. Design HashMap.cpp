class MyHashMap {
public:
    
    vector<list<pair<int,int>>> hash_map;
    int size=1000;
    
    int hash(int key)
    {
        return key%size;
    }
    
    list<pair<int,int>> :: iterator search( int key)
    {
        int i=hash(key);
        
        list<pair<int,int>>:: iterator it=hash_map[i].begin();
        
        while(it!=hash_map[i].end())
        {
            if(it->first==key) return it;
            it++;
        }
        
        return it;
    }
    
    MyHashMap() {
    
        hash_map.resize(size);
    }
    
    void put(int key, int value) {

        int i=hash(key);
        remove(key);
        hash_map[i].push_back({key,value});
        
    }
    
    int get(int key) {
        
        int i=hash(key);
        list<pair<int,int>>:: iterator it=search(key);
        if(it==hash_map[i].end()) return -1;
        else return it->second;
        
    }
    
    void remove(int key) {
        
        int i=hash(key);
        list<pair<int,int>> :: iterator it=search(key);
        if(it!=hash_map[i].end()) hash_map[i].erase(it);
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */