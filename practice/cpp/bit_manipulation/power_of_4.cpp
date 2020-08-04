// problem: https://leetcode.com/problems/power-of-four/

#include <iostream>
using namespace std;

bool isPowerOf4(int num)
{
    return num > 0 && !(num & (num-1)) && (num % 3 ==1);
}

int main (void) {
    for (int i = 0 ; i < 100; i++) {
        std::cout << i << " is power of 4 ? : " << isPowerOf4(i) << endl;
    }
    return 0;
}
