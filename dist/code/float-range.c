#include<stdio.h>
#include<limits.h>
#define update() printf("\033[H\033[J")
int range[400];
float range_delimiter[10]={0.5, 1, 5, 10, 100, 1000, 1e4, 1e5, 1e6, 1e40};

union iaf {
	int i32;
	float f32;
};

int main(){
	union	iaf num;
	for(num.i32 = 0; num.i32 < INT_MAX; num.i32++){
	  for(int i=0;i < 10;i++){
			if(num.f32 <= range_delimiter[i]){
				range[i]++;
				break;
			}
		}
		if(num.i32%10000000==0){

			update();
    	for(int i=0;i < 10;i++){
    		printf("%E\t",range_delimiter[i]);
    	}
			printf("\n");
    	for(int i=0;i<10;i++){
    		printf("%f%%\t",range[i]/(float)INT_MAX*100);
    	}
			printf("\n");
		}
	
	}	
	return 0;
}
