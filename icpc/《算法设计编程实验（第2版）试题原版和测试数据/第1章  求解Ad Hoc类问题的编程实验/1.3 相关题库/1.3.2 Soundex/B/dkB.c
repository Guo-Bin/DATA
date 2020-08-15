#include <stdio.h>

char alph[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char code[27] = "01230120022455012623010202";

main() {
	int ch;
	char last = '0';

	while( (ch=getchar()) != EOF ) {
		if( ch == '\n' ) {
			putchar( '\n' );
			last = '0';
		} else if( code[ch-'A'] != last ) {
			last = code[ch-'A'];
			if( last != '0' ) putchar( last );
		}
	}
}
