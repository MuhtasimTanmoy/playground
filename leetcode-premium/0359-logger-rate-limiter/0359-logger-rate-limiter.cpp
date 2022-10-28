class Logger {
    const int LIMIT = 10;
    unordered_map<string, int> bag;
public:
    Logger() { }
    bool shouldPrintMessage(int timestamp, string message) {
        
        if (!bag.count(message)) {
            bag[message] = timestamp;
            return true;
        }
        
        auto shouldPrint = [&] {
            auto prevTime = bag[message];
            return timestamp - prevTime >= LIMIT;
        };
        
        if (shouldPrint()) {
            bag[message] = timestamp;
            return true;
        } 
        
        return false;
    }
};