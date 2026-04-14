#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

#define ISALPHA(a) (('A' <= (a) && (a) <= 'Z') || ('a' <= (a) && (a) <= 'z'))

class Solution {
public:
    string reverseWords(string s) {
        bool flag = true; // 判断现在是不是读取到空格了
        int i = 0, j = 0;
        // 首先移除多余的空格

        while(j < s.size()) {
            if(flag) {
                if(!ISALPHA(s[j])) j++;
                
            }
            else {
                flag = false;
                s[i++] = s[j++];
            }
        }

        s.resize(i);
        return s;
        // 然后逆序遍历字符串
        // 将每个单词再次反转过来
    }
};

int main(void)
{
    Solution s;
    auto ans = s.reverseWords("    hello          world   ");
    std::cout << ans;
}
