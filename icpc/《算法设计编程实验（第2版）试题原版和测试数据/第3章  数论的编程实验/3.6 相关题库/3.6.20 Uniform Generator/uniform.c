#include <stdio.h>

void main(void)
{	FILE *inp, *outp;
  long  i, seed, step, mod;

	inp=fopen("uniform.in","r");
	outp=fopen("uniform.out","w");

	while (!feof(inp))
	{ fscanf(inp, "%ld %ld", &step, &mod);
		fscanf(inp, "\n");
		seed=0;
		for (i=0; i<(mod-1); i++)
		{ seed=(seed+step)%mod;
			if (!seed)
			{ break; }
		}
		if (i==(mod-1))
		{ fprintf(outp,"%10ld%10ld Good Choice\n\n",step,mod); }
		else
		{ fprintf(outp,"%10ld%10ld Bad Choice\n\n",step,mod); }
	}
	fclose(inp);
	fclose(outp);
}