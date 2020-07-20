#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <math.h>

int main(void) {	
	// your code here
    unsigned int n = 0;
    scanf("%u",&n);
    // printf("n= %d\n",n);
    unsigned int v = 0;
    for (int i = 0; i < n; i++) {
        scanf("%u",&v);
    	unsigned int u = (1== v) ? 0 : 1;
        for (int j = 2; j <= sqrt(v); j++) {
            if (v % j == 0)
            {
                if (j == v/j) {
                    u += j;
                } else {
                    u += (j + v/j);
                }
            }
        }
        printf("%u\n",u);
    }
	return 0;
}
