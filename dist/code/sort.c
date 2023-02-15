#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <time.h>
#define N 4
#define TIMES 10000000
int a[N];
int b[N];

void bubble_sort(int *a, int n) {
  int flag = 1;
  while (flag) {
    flag = 0;
    for (int i = 0; i < n-1; ++i) {
      if (a[i] > a[i + 1]) {
        flag = 1;
        int t = a[i];
        a[i] = a[i + 1];
        a[i + 1] = t;
      }
    }
  }
}

int cmp(const void *a,const void *b){
    return (*(int*)a-*(int*)b);
}

int main(){
    srand(time(NULL));
    int times=0;
    while(times++<TIMES){
        for(int i=0;i<N;i++){
            a[i]=rand();
            b[i]=a[i];
        }
        qsort(a,N,sizeof(int),cmp);
        bubble_sort(b,N);
        assert(memcmp(a,b,sizeof(a))==0);
    }
    return 0;
}
