#include <vector>
#include <iostream>
#include <math.h>
using namespace std;

bool is_prime(unsigned int num)
{
    if (num == 1) return false;
    for (unsigned int i = 2; i <= sqrt(num); i++)
    {
        if (0 == num % i) return false;
    }
    return true;
}

int main(void)
{
    unsigned int t;
    cin >> t;
    std::vector<unsigned int> mv;
    std::vector<unsigned int> nv;
    unsigned int m,n;
    for (int i = 0; i < t; i++) {
        cin >> m;
        cin >> n;
        mv.push_back(m);
        nv.push_back(n);
    }
    for (int i = 0; i < t; i++) {
        m = mv.at(i);
        n = nv.at(i);
        for (unsigned int j = m; j <= n; j++) {
            if (is_prime(j)) {
                cout << j << endl;
            }
        }
        cout << endl;
    }
}
