struct Packet{
        int source;
        int destination;
        int timestamp;

    bool operator<(const Packet& other) const{
       return source < other.source || 
        (source == other.source && destination < other.destination ) || 
        (source == other.source && destination == other.destination && timestamp < other.timestamp);
    }
};

class Router {
public:
    Router(int memoryLimit): memoryLimit(memoryLimit) {
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        const Packet packet{source, destination, timestamp};
        if(uniquePackets.find(packet) != uniquePackets.end()){
            return false;
        }
        if(uniquePackets.size() ==  memoryLimit){
            forwardPacket();
        }
        uniquePackets.insert(packet);
        packetQueue.push(packet);
        destToTimestamp[destination].push_back(timestamp);
        return true;
    }
    
    vector<int> forwardPacket() {
        if(packetQueue.empty()){
            return {};
        }
        const Packet nextPacket = packetQueue.front();
        packetQueue.pop();
        uniquePackets.erase(nextPacket);
        ++destProcessedIndex[nextPacket.destination];
        return {nextPacket.source, nextPacket.destination, nextPacket.timestamp};
    }
    
    int getCount(int destination, int startTime, int endTime) {
        if(destToTimestamp.find(destination) == destToTimestamp.end()){
            return 0;
        }

        const vector<int>& timestamps = destToTimestamp[destination];
        int start = destProcessedIndex[destination];

        const auto lowerBound = lower_bound(timestamps.begin() + start, timestamps.end(), startTime);

        const auto upperBound = upper_bound(timestamps.begin() + start, timestamps.end(), endTime);

        return upperBound - lowerBound;
    }
private:
    const int memoryLimit;
    set<Packet> uniquePackets;
    queue<Packet> packetQueue;
    map<int,vector<int>> destToTimestamp;
    map<int,int> destProcessedIndex;

};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */