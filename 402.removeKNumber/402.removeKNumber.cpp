#include<string>
#include<stack>
#include<iostream>
#include <algorithm>
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
        }
        if(ans.size() == 0) {
            return "0";
        }
        reverse(ans.begin(), ans.end());
        int start = 0;
        while(i < ans.size() && ans[i] == '0') {
            i ++;
        }
        ans = ans.substr(i)
        return ans;
    }
};

int main() {
    Solution solution;
    solution.removeKdigits("12434234", 3);
}