#include <stdio.h>
#include <string.h>

int move[5][2]={{-1,0},{0,-1},{0,1},{1,0},{0,0}};
char symbol[5]={'U','L','R','D','S'};
char block[40][40][2];
char block2[40][40][2];
char str[100];
int q[2000][3],q1,q2;

void main() {
	FILE *fp;
	int x,y;
	int a,b;
	int min,mina,minb;
	int mint,a1,b1,a2,b2;
	int i,j,k;
	char s;

	fp=fopen("block.in","r");
	for(int ca=1;;ca++) {
		if (fscanf(fp,"%d%d",&x,&y)!=2) break;
		if (!x&&!y) break;
		memset(block,0,sizeof(block));
		for(i=1;i<=x;i++) {
			for(j=1;j<=y;j++) {
				fscanf(fp,"%s",str);
				block[i][j][0]=str[0];
				for(k=0;k<5;k++) {
					if (str[1]==symbol[k]) {
						block[i][j][1]=k;
						break;
					}
				}
			}
		}

		for(;;) {
			mint=4;
			for(i=1;i<=x;i++) {
				for(j=1;j<=y;j++) {
					if (block[i][j][0]==0) continue;
					memcpy(block2,block,sizeof(block));
					s=block[i][j][0];
					q[0][0]=i;
					q[0][1]=j;
					q[0][2]=0;
					q1=0;
					q2=1;
					min=mint;
					mina=-1;
					minb=-1;
					while (q1<q2) {
						if (q[q1][2]>=min || q[q1][2]>=3) break;
						for(k=0;k<4;k++) {
							a=q[q1][0];
							b=q[q1][1];
							for(;;) {
								a+=move[k][0];
								b+=move[k][1];
								if (a<0||a>x+1||b<0||b>y+1) break;
								if (block2[a][b][0]==0) {
									block2[a][b][0]=1;
									q[q2][0]=a;
									q[q2][1]=b;
									q[q2][2]=q[q1][2]+1;
									q2++;
								} else {
									if (block2[a][b][0]!=1) {
										if (block2[a][b][0]==s&&(a!=i||b!=j)) {
											if (q[q1][2]+1<min||
												q[q1][2]+1==min&&a<mina||
												q[q1][2]+1==min&&a==mina&&b<minb) {
												min=q[q1][2]+1;
												mina=a;
												minb=b;
											}
										}
										break;
									}
								}
							}
						}
						q1++;
					}
					if (min<mint) {
						mint=min;
						a1=i;
						b1=j;
						a2=mina;
						b2=minb;
						if (mint==1) goto finish;
					}
				}
			}
finish:
			if (mint==4) break;

			block[a1][b1][0]=0;
			block[a1][b1][1]=0;
			block[a2][b2][0]=0;
			block[a2][b2][1]=0;

			int flag;
			do {
				flag=0;
				memset(block2,0,sizeof(block2));
				for(i=1;i<=x;i++) {
					for(j=1;j<=y;j++) {
						if (block[i][j][0]) {
							a=i+move[block[i][j][1]][0];
							b=j+move[block[i][j][1]][1];
							if (a<1||a>x||b<1||b>y) {
								a=i;
								b=j;
							}
							if (block[a][b][0]!=0||block2[a][b][0]!=0) {
								a=i;
								b=j;
							}
							block2[a][b][0]=block[i][j][0];
							block2[a][b][1]=block[i][j][1];
							block[i][j][0]=0;
							block[i][j][1]=0;
							if (a!=i||b!=j) {
								flag=1;
							}
						}
					}
				}
				memcpy(block,block2,sizeof(block));
			} while (flag);
		}
		printf("Case %d\n",ca);
		for(i=1;i<=x;i++) {
			for(j=1;j<=y;j++) {
				if (block[i][j][0]==0) {
					printf(".");
				} else {
					printf("%c",block[i][j][0]);
				}
			}
			printf("\n");
		}
	}
}