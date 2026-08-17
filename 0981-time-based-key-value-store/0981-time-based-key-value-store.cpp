class TimeMap {
public:
    unordered_map<string,map<int,string>> mpp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mpp[key][timestamp] = value; 
    }
    
    string get(string key, int timestamp) {
        auto &mp = mpp[key];
        auto it = mp.upper_bound(timestamp);
        
        if(it == mp.begin()) return "";
        
        --it;
        return it->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */