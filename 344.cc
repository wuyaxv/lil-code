/* 344. 反转字符串
 * 难度：简单
 */

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int i = 0, j = s.size()-1;
        int temp = 0;
        while(i < j) {
            temp = s[i];
            s[i] = s[j];
            s[j] = temp;
            i++;
            j--;
        }
    }
};

int main(void)
{
    auto a = Solution();
    vector<char> s{'h','e','l','l','o'};
    a.reverseString(s);
    for(auto c: s) {
        std::cout << c;
    }
}
