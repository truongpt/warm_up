#include<stdio.h>
#include<stdlib.h>
#include <string.h>

int main(void) {	
	// your code here
    int n = 0;
    scanf("%d",&n);
    // printf("n= %d\n",n);
    int *v = (int*)malloc(sizeof(int)*n);
    int *u = (int*)malloc(sizeof(int)*n);
    memset((void*)u,0x00,sizeof(int)*n);

    for (int i = 0; i < n; i++) {
        scanf("%d",&v[i]);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 1; j < v[i]; j++) {
            if (v[i] % j == 0) u[i] += j;
        }
        printf("%d\n",u[i]);
    }
    free(v);
    free(u);    
	return 0;
}
