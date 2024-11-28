#include<string>
#include<stack>
#include<iostream>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<int> digitsStack;
        int length = num.size();
        int count = 0;
        int i = 0;
        for(; i < length; i ++) {
            char temp = num[i];
            int number = temp - '0';
            while(!digitsStack.empty() && count < k && digitsStack.top() > number) {
                digitsStack.pop();
                count ++;
            }
            digitsStack.push(number);
        }
        string ans = "";
        while(!digitsStack.empty()) {
            char tempNumber = char(digitsStack.top() + '0');
            ans += tempNumber;
            digitsStack.pop();
            cout << tempNumber << endl;
        }
        ans.reserve();
        return ans;
    }
};

int main() {
    Solution solution;
    solution.removeKdigits("12434234");
}