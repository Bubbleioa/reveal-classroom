#include <stdio.h>
#include <stdlib.h>
#define POSX(x,y,z) ( (n-y-1)*2 + 4*x )
#define POSY(x,y,z) ( (n-y-1)*2 + 3*z )
#define MAX(a,b) (((a)>(b))?(a):(b))
char cube[8][8] = {
"..+---+",
"./   /|",
"+---+ |",
"|   | +",
"|   |/.",
"+---+..",
};
int n,m;

int height[51][51];
int ans[5001][5001];
int maxX=0, maxY=0;

void place(int x,int y){
	for(int i=0;i<=5;i++)
		for(int j=0;j<=6;j++){
			if(cube[i][j]=='.')continue;
			ans[y+5-i][j+x]=cube[i][j];
		}	
	maxX = MAX(maxX, x+6);
	maxY = MAX(maxY, y+5);
}

int main() {
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)for(int j=0;j<m;j++)scanf("%d",&height[i][j]);
	for(int y=0;y<n;y++)
		for(int x=0;x<m;x++)
			for(int z=0;z<height[y][x];z++)
				place(POSX(x,y,z), POSY(x,y,z));
	for(int i=maxY;i>=0;i--){
		for(int j=0;j<=maxX;j++)
			printf("%c",ans[i][j]=='\0'?'.':ans[i][j]);
		printf("\n");
	}
		
	return 0;
}
