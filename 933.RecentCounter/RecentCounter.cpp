#include<vector>
using namespace std;
class RecentCounter {
public:
    vector<int> channel;
    int point1 = 0;
    int point2 = 0;
    RecentCounter() {
    }
    
    int ping(int t) {
        channel.push_back(t);
        point2 ++;
        while(channel[point2] - channel[point1] > 3000) {
            point1 ++;
        }
        return point2 - point1;
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */