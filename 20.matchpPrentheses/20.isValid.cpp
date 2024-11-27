#include<string>
#include<stack>
#include<map>
#include<iostream>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        stack<int> myStack;
        map<char, int> symbolMap = {{'{', 1}, {'}', -1}, {'[', 2}, {']', -2}, {'(', 3}, {')', -3}};
        for(int i = 0; i < s.size(); i ++) {
            int tempStackContent = symbolMap[s[i]];
            char tempChar = s[i];
            if (symbolMap[s[i]] < 0) {
                if (myStack.empty()) {
                    return false;
                }
                int top = myStack.top();
                myStack.pop();
                if (top + tempStackContent != 0) {
                    return false;
                }
            } else {
                myStack.push(tempStackContent);
            }
        }

        return myStack.empty();
    }
};

int main() {
    Solution solution;
    solution.isValid("")
}