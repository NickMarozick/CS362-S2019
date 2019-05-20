CFLAGS= -Wall -fpic -coverage -lm -std=c99
  
rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)
#To run playdom you need to entere: ./playdom <any integer number> like ./playdom 10*/
testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc  -o testDrawCard -g testDrawCard.c dominion.o rngs.o $(CFLAGS)

badTestDrawCard: badTestDrawCard.c dominion.o rngs.o
	gcc -o badTestDrawCard -g badTestDrawCard.c dominion.o rngs.o $(CFLAGS)

testBuyCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g testDrawCard.c dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g $(CFLAGS)

rtest1: randomtestcard1.c dominion.o rngs.o
	gcc randomtestcard1.c dominion.c rngs.c -o randomtest1 $(CFLAGS)

rtest2: randomtestcard2.c dominion.o rngs.o
	gcc randomtestcard2.c dominion.c rngs.c -o randomtest2 $(CFLAGS)

rtestadventurer: randomtestadventurer.c dominion.o rngs.o
	gcc randomtestadventurer.c dominion.c rngs.c -o randomtestadventurer $(CFLAGS)

randomtestresults: randomtestcard1.c randomtestcard2.c unittest3.c dominion.o rngs.o
	./randomtest1 &> randomtestresults.out
	./randomtest2 >> randomtestresults.out
	./randomtestadventurer >> randomtestresults.out
	gcov dominion.c >> randomtestresults.out
	cat dominion.c.gcov >> randomtestresults.out

runtests: testDrawCard.c
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out

player: player.c interface.o
	gcc -o player player.c -g dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player rtest1 rtest2 rtestadventurer randomtestresults

clean:
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe
