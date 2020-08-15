TARGETS = AnagramManuel AnagramRolf
.c:
	gcc -ansi -pedantic -Wall -o $@ $<

samples:	$(TARGETS)

testset:	anagram.sol

anagram.sol:	AnagramManuel anagram.in
	./AnagramManuel
	mv anagram.out anagram.sol

test:	anagram.sol AnagramRolf
	./AnagramManuel
	diff -w anagram.out anagram.sol
	./AnagramRolf
	diff -w anagram.out anagram.sol
	rm anagram.out

clean:
	rm -f ${TARGETS}
	rm -f *%
	rm -f anagram.out anagram.sol
	

