/* 131. 分割回文串
 * 难度：中等
 */

#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    vector<vector<string>> ans;
    vector<string> path;
    bool isPalindrome(string s) {
        vector<char> stack;       
        if(s.size() == 1) return true;

        for(auto c: s) {
            if(stack.size()) {
                if(stack.back() == c) stack.pop_back();
                else stack.push_back(c);
            } else {
                stack.push_back(c);
            }
        }

        if(stack.size()) return false;
        else return true;
    }

    void backtracking()
public:
    vector<vector<string>> partition(string s) {
        
    }
};
