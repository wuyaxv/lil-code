/* 455. 分发饼干
 */

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int count = 0;
        size_t cookie_ptr = 0, kid_ptr = 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        while(cookie_ptr < s.size() && kid_ptr < g.size()) {
            if(s[cookie_ptr] >= g[kid_ptr]) {
                count++;
                kid_ptr++;
            }
            cookie_ptr++;
        }
        return count;
    }
};

int main(void)
{
    auto solu = Solution();
    vector<int> g{1,2,4,7,8}, s{1,2,3,9};
    auto result = solu.findContentChildren(g, s);
    std::cout << result << endl;
}
