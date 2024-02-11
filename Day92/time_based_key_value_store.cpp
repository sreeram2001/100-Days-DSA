class TimeMap {
public:

    //store in the format e.g. = { foo : [{"bar", 1}, {"bar2", 3}]}
    map<string, vector< pair<string, int>> > maps;

    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        
        if(maps.count(key) > 0)
        {
            maps[key].push_back({value, timestamp});
        }
        else
        {   
            vector<pair<string, int>> timest;
            timest.push_back({value, timestamp});
            maps.insert({key, timest});
        }
    }
    
    string get(string key, int timestamp) {
        if(maps.count(key) > 0)
        {
            int low = 0;
            int high = maps[key].size()-1;

            while(low <= high)
            {
                int mid = (low+high)/2;

                if(maps[key][mid].second == timestamp)
                {
                    return maps[key][mid].first;
                }
                else if(maps[key][mid].second > timestamp)
                {
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }
            }

            if(high >= 0)
            {
                return maps[key][high].first;
            }
        }
        
        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
