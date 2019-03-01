#include <iostream>
#include <cassert>
#include <memory>

class Solution {
public:
    int climbStairs(int n) {
        if(n == 2) {
            return 2;
        }
        else if(n == 1){
            return 1;
        }
        else {
            //return climbStairs(n -  1 ) + climbStairs(n - 2 );
            int n_2 = 1, n_1 = 2;
            int sum = 0;
            for(int i=3; i <= n; ++i)
            {
                sum = n_2 + n_1;                
                n_2 = n_1;
                n_1 = sum;
            }
            return sum;
        } 
    }
};


int main()
{
    std::shared_ptr<Solution> sol = std::make_shared<Solution>();

    assert(sol->climbStairs(2) ==  2);
    assert(sol->climbStairs(4) ==  5);
    assert(sol->climbStairs(5) ==  8);

    std::cout<<sol->climbStairs(42)<<std::endl;

    return 0; 
}

