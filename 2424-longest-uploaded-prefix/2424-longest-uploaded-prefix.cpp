class LUPrefix {
public:
    vector<bool>present;
    int biggestPresent = 0;
    LUPrefix(int n) {
        present.assign(n+2, false);
    }
    
    void upload(int video) {
        present[video] = true;

        while(present[biggestPresent + 1]){
            biggestPresent++;
        }
    }
    
    int longest() {
        return biggestPresent;
    }
};

/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */