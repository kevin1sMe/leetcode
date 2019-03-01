#include <iostream>
#include <cassert>
#include <cmath>

class Solution {
public:
    //使用简单的递归，肯定让堆栈溢出
    //double myPow(double x, int n) {
        //if(n == 0 ) return 1;

        //if(n < 0) return 1/myPow(x, -n);

        //return x * myPow(x, n - 1);
    //}
    
    //使用分治, x^n = x^(n//2) * x^(n/2)
    double myPow(double x, int n) {
        return myPower(x, n);//因为试题中n为-2111xxxx时，转为正数会溢出，故这里调用别个long long函数;
    }

    double myPower(double x, long long n) {
        if(n == 0) return 1;

        if(n < 0) return 1/myPower(x, -n);

        if(n%2 == 0) {
            double y = myPower(x, n >>1);
            return y * y;
        }
        else {
            double y = myPower(x, n >> 1);
            return x * y * y;
        }
    }

};


int main()
{
    Solution *sol = new Solution();
    assert(fabs(sol->myPow(2.0000, 10) -1024.00) < 1e-6);
    assert(fabs(sol->myPow(2.1000, 3) - 9.261) < 1e-6);
    assert(fabs(sol->myPow(2.0000, -2) - 0.25) < 1e-6);

    std::cout<<sol->myPow(0.00001, 2147483647); //stack overflow
    std::cout<<sol->myPow(0.00001, -2147483648); //-n 

    delete sol;
    return 0;
}
