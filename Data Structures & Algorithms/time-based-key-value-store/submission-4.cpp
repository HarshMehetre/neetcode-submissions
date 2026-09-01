// class TimeMap {
// public:
//     unordered_map<int,pair<string,string>> mp;
//     TimeMap() {
        
//     }
    
//     void set(string key, string value, int timestamp) {
//         mp[timestamp]={key,value};
//     }
    
//     string get(string key, int timestamp) {
//         for(int i=timestamp; i>=0; --i){
//             if(mp.count(i) && mp[i].first == key){
//                 return mp[i].second;
//             }
//         }
//         return "";
//     }
// };

class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> mp;

public:
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if (mp.find(key) == mp.end()) return "";
        
        const auto& store = mp[key];
        int l = 0, r = store.size() - 1;
        string res = "";
        
        while (l <= r) {
            int mid = l + (r - l) / 2;
            
            if (store[mid].first <= timestamp) {
                res = store[mid].second;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        
        return res;
    }
};
