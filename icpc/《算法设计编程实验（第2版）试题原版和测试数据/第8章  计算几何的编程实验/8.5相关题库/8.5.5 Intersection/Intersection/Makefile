TARGETS = IntersectionManuel
.c:
	gcc -ansi -pedantic -Wall -o $@ $<

samples:	$(TARGETS)

testset:	intersection.sol

intersection.sol:	IntersectionManuel intersection.in
	./IntersectionManuel
	mv intersection.out intersection.sol

clean:
	rm -f ${TARGETS}
	rm -f *%
	rm -f intersection.out intersection.sol
	

