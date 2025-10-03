class LRUCache {
public:
    int capacity;
    list<pair<int,int>> dll; // key -> val pairs 
    // dll to implement least recenlty used key
    unordered_map<int, list<pair<int,int>>::iterator> cache;
    // key -> iterator pointing to the node in dll
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(cache.find(key)==cache.end()) return -1;
        dll.splice(dll.begin(),dll,cache[key]);

        // ll -> linkedlist
        // ll.splice(ll.begin(),ll,key) 
        // means : take the node -> key in ll to front of the list

        return cache[key]->second;
    }
    
    void put(int key, int value) {
        if(cache.find(key)!=cache.end()){
            cache[key]->second=value;
            dll.splice(dll.begin(),dll,cache[key]);
        }
        else{
            if(dll.size()==capacity){
                int old=dll.back().first;
                dll.pop_back();
                cache.erase(old);
            }
            dll.push_front({key,value});
            cache[key]=dll.begin();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */