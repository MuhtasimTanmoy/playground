class Logger {
    unordered_map<string, int> bag;
public:
    Logger() { }
    bool shouldPrintMessage(int timestamp, string message) {
        
        if (!bag.count(message)) {
            bag[message] = timestamp;
            return true;
        }
        
        auto prevTime = bag[message];
        if (timestamp - prevTime >= 10) {
            bag[message] = timestamp;
            return true;
        } 
        
        return false;
    }
};