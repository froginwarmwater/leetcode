#include<map>

using namespace std;


class Solution {
public:
    int firstUniqChar(string s) {
        map<char, int> strToCountMap;
        for(int i = 0; i < s.size(); i ++) {
            strToCountMap[s[i]] ++;
        }
        for(int i = 0; i < s.size(); i ++) {
            if (strToCountMap[s[i]] == 1) {
                return i;
            }
        }
        return -1;
    }
};



int main() {
    
}