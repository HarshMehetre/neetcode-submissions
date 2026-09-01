class TimeMap {
public:
    unordered_map<int,pair<string,string>> mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[timestamp]={key,value};
    }
    
    string get(string key, int timestamp) {
        for(int i=timestamp; i>=0; --i){
            if(mp.count(i) && mp[i].first == key){
                return mp[i].second;
            }
        }
        return "";
    }
};

// class TimeMap {
// public:
//     unordered_map<int,pair<string,string>> mp;
//     TimeMap() {
        
//     }
    
//     void set(string key, string value, int timestamp) {
//         mp[timestamp]={key,value};
//     }
    
//     string get(string key, int timestamp) {
        
//         if(mp.find(timestamp)==mp.end()){
//             int l =1;
//             int r =timestamp-1;
//             while(l<r){
//                 int mid=l+(r-l)/2;


//             }
//         }
//         return mp[timestamp].second;
//     }
// };

