#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    string reverseStr(string s, int k) {
        int stride = s.size() / (2*k);
        int remain = s.size() % (2*k);
        int i = 0;

        for(i = 0; i < stride; ++i) {
            for(auto l = i*(2*k), r = l + k - 1; l < (i*2*k) + (k/2); ++l, --r) {
                swap(s[l], s[r]);
            }
        }

        if(remain >= k) {
            for(auto l = i*(2*k), r = l + k - 1; l < (i*2*k) + (k/2); ++l, --r) {
                swap(s[l], s[r]);
            }
        }
        else {
            for(auto l = i*(2*k), r = l + remain - 1; l < (i*2*k)+remain/2; ++l, --r) {
                swap(s[l], s[r]);
            }
        }

        return s;
    }
};

int main() {
    auto s = Solution();
    string m = "abcdefg";
    auto result = s.reverseStr(m, 8);

    std::cout << result << endl;
}
