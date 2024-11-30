#include<string>
#include<map>
#include<stack>
#include <algorithm>
using namespace std;
class Solution {
public:
    string removeDuplicateLetters(string s) {
        string ans;
        stack<char> myStack; 
        map<char, int> letterCountMap;
        for(int i = 0; i < s.size(); i ++) {
            letterCountMap[s[i]] ++;
        }
        for(int i = 0; i < s.size(); i ++) {
            
            // 如果top > current 
            // 并且top 个数不唯一
            // pop
            while(!myStack.empty() && int(myStack.top()) > int(s[i]) && letterCountMap[myStack.top()] > 1) {
                letterCountMap[myStack.top()] --;
                myStack.pop();
            }
            myStack.push(s[i]);
        }
        while(!myStack.empty()) {
            char topChar = myStack.top();
            if (letterCountMap[topChar] > 1) {
                myStack.pop();
                letterCountMap[topChar] --;
                continue;
            }
            ans += topChar;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    string str= "bcabc";
    Solution solution;
    solution.removeDuplicateLetters(str);
    return 0;
}