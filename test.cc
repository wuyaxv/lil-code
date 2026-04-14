#include <string>
#include <algorithm>
#include <iostream>

using namespace std;
int main(void)
{
    string s = "abcdefg";
    swap(s[0], s[3]);
    std::cout << s;
    return 0;
}
