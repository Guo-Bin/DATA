#include <stdio.h>
#include <math.h>

int main(int arg,char*argv[]){
    FILE* fout=fopen("output","rt");
    FILE* fsol=fopen(argv[1],"rt");
	double f1,f2;
	while (fscanf(fout,"%lf",&f1)!=-1){
		if (fscanf(fsol,"%lf",&f2)==-1){
			printf("Too Few Lines!\n");
			return -1;
		}
		if (fabs(f1-f2)>0.0015){
			printf("Wrong Answer!\n");
			return -1;
		}
	}
	if (fscanf(fsol,"%lf",&f2)!=-1){
		printf("Too Many Lines!\n");
		return -1;
	}
	printf("Accepted!\n");
	return 0;
}
