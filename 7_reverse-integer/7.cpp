#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Solution
{
  public:
    int reverse(int x)
    {
        if (x == 0)
            return 0;

        int flag = x > 0 ? 1 : -1;
        int y = 0;
        while (x)
        {
            y = y * 10 + (x % 10);
            x /= 10;
        }
        if (y > ((1 << 31) - 1) || y < (-1 * (1 << 31)))
            return 0;
        return flag * y;
    }
};

int main()
{

    assert(Solution().reverse(123) == 321);
    assert(Solution().reverse(-123) == -321);
    assert(Solution().reverse(120) == 21);
    assert(Solution().reverse(1534236469) == 0);

    return 0;
}