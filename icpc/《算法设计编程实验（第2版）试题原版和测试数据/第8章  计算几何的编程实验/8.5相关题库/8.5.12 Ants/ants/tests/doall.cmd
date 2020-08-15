@echo off
call dcc32 -cc genrandom
call dcc32 -cc gencircle
copy ??.t ?? >nul
genrandom 10 10 123456 >05
genrandom 20 100 060606 >06
genrandom 100 1000 070707 >07
genrandom 100 10000 080808 >08
genrandom 100 10000 090909 >09
genrandom 100 10000 101010 >10
genrandom 100 10000 111111 >11
gencircle >12