class LFUCache {
    int cap, minFreq;
    unordered_map<int, pair<int,int>> keyMap;        // key → {value, freq}
    unordered_map<int, list<int>> freqMap;            // freq → list of keys (front=MRU, back=LRU)
    unordered_map<int, list<int>::iterator> iterMap;  // key → iterator in freqMap list

    void updateFreq(int key) {
        int freq = keyMap[key].second;
        freqMap[freq].erase(iterMap[key]);
        if (freqMap[freq].empty()) {
            freqMap.erase(freq);
            if (minFreq == freq) minFreq++;
        }
        keyMap[key].second++;
        freqMap[freq + 1].push_front(key);
        iterMap[key] = freqMap[freq + 1].begin();
    }

public:
    LFUCache(int capacity) : cap(capacity), minFreq(0) {}

    int get(int key) {
        if (!keyMap.count(key)) return -1;
        updateFreq(key);
        return keyMap[key].first;
    }

    void put(int key, int value) {
        if (cap <= 0) return;
        if (keyMap.count(key)) {
            keyMap[key].first = value;
            updateFreq(key);
            return;
        }
        if ((int)keyMap.size() == cap) {
            int evict = freqMap[minFreq].back();
            freqMap[minFreq].pop_back();
            if (freqMap[minFreq].empty()) freqMap.erase(minFreq);
            keyMap.erase(evict);
            iterMap.erase(evict);
        }
        keyMap[key] = {value, 1};
        freqMap[1].push_front(key);
        iterMap[key] = freqMap[1].begin();
        minFreq = 1;
    }
};