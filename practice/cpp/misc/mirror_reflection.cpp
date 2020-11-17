/*
- Problem: https://leetcode.com/problems/mirror-reflection
- Clarify.
  - Is it physisc problem :D
  - The ray meets the corner if it meets the image of the corner in mirror.
- Solution.
  - Check which image of the corner, the ray will be meets.
*/


int gcd(int a, int b)
{
    if (a == 0) return b;
    return gcd(b%a, a);
}

int mirrorReflection(int p, int q)
{
    if (q == 0) return 0;

    int c = gcd(p,q);
    p = p/c;
    q = q/c;

    if (!(p%2)) return 2;
    if (q%2) return 1;
    return 0;
}

void main(void)
{
    cout << mirrorReflection(2,1) << endl;
}
