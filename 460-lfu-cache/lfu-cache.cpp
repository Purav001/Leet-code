class LFUCache {
public:

    int capacity,time=0;
    list<pair<int,int>> dll;
    unordered_map<int,list<pair<int,int>>::iterator> cache;
    set<tuple<int,int,int>> st;
    unordered_map<int,int> keyfreq;
    unordered_map<int,int> keytime;

    LFUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(cache.find(key)==cache.end()) return -1;
        increase(key);
        return cache[key]->second;
    }

    void increase(int key){
        int old=keyfreq[key],t=keytime[key];
        st.erase({old,t,key});
        time++;
        keyfreq[key]=old+1;
        keytime[key]=time;
        st.insert({old+1,time,key});
    }
    
    void put(int key, int value) {
        if(cache.find(key)!=cache.end()){
            cache[key]->second=value;
            increase(key);
        }
        else{
            if(dll.size()==capacity){
                auto it=*st.begin();
                int ekey=get<2>(it);
                st.erase(it);
                dll.erase(cache[ekey]);
                cache.erase(ekey);
                keytime.erase(ekey);
                keyfreq.erase(ekey);
            }
            dll.push_front({key,value});
            cache[key]=dll.begin();
            time++;
            keyfreq[key]=1;
            keytime[key]=time;
            st.insert({1,time,key});
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */