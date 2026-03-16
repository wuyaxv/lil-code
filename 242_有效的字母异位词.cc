/* 242. 有效的字符异位词
 * 解法1：直接使用multiset
 * 解法2：对字符串进行排序然后比较
 * 解法3：构建一个关于字母的Hash表，可以通过记录每个字符出现的次数即可
 */
#include <set>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        std::multiset<char> s1(s.begin(), s.end()), s2(t.begin(), t.end());
        return s1 == s2;
    }
};

int main(void)
{
    auto s = Solution();

    bool result = s.isAnagram("hello", "hello");
    std::cout << result << endl;
}
