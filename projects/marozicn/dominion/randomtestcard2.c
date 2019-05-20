#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h>

#define DEBUG 0
#define NOISY_TEST 1



int main () {

  int i, n; 

  int card, coin_bonus, seed, numPlayers, choice1, choice2, choice3, handPos, thisPlayer;

    int score=0; 
    int total=8;
    int otherPlayer; 
    int preHandCount; 
    int postHandCount; 
    int preDeckCount; 
    int postDeckCount; 
    int preDiscardCount; 
    int postDiscardCount; 
    int playerTurnPre; 
    int playerTurnPost; 
    int prePhase; 
    int postPhase; 
    int prePlayedCardCount; 
    int postPlayedCardCount; 
    int preNumBuys; 
    int postNumBuys; 
    int preActions; 
    int postActions; 
    int preEstate; 
    int postEstate; 
    int preDuchy; 
    int postDuchy; 
    int preProvince; 
    int postProvince; 

    int otherDeckPre; 
    int otherDeckPost; 
    int otherDiscardPre; 
    int otherDiscardPost; 
    int totalScore = 800; 
    int accumulatedScore=0; 
    int m; 

  seed=1000;

  srand(time(0));

  int k[10] = {adventurer, council_room, feast, gardens, mine,
               remodel, smithy, village, baron, great_hall};

  struct gameState G;
  struct gameState testG;
  

  printf("----------------- CardTest - Testing Village Card Input with Randomized Tests: ----------------\n\n");

  //SelectStream(2);
  //PutSeed(3);

  for (n = 0; n < 100; n++) {
    //numPlayers = floor(Random() * 3);
    numPlayers = rand()%3+2;
    //numPlayers = numPlayers+2;
    G.whoseTurn = rand()% numPlayers + 1;
    thisPlayer = G.whoseTurn; 

    printf("Num Players: %d\n", numPlayers);
    printf("Whose Turn: %d\n", G.whoseTurn);
    initializeGame(numPlayers, k, seed, &G);

    //choice1= floor(Random() * 3);
    //choice2= floor(Random() * 3);
    //choice3= floor(Random() * 3);
    coin_bonus = 0;
    //handPos = floor(Random() * G.handCount[p]);
    handPos = G.handCount[G.whoseTurn];
    //card = floor(Random() * 10);
    //card= rand()%10;
    card = 7;

    printf("n: %d\n", n);
    printf("handPos: %d\n", handPos);
    //printf("choice1: %d\n", choice1);
    //printf("choice2: %d\n", choice2);
    //printf("choice3: %d\n", choice3);
    //printf("card: %d\n\n\n", card);

  
    /*  copy the game state to a test case */
    memcpy(&testG, &G, sizeof(struct gameState));

    /* Print Player 1 Hand & Details Before Village Function */ 
    printf("Printing Cards BEFORE Village function is called: \n");
    for (m=0; m<testG.handCount[thisPlayer]; m++) {
            printf("(%d)", testG.hand[thisPlayer][m]);}
    printf("\n");
    printf("\n");
    /* call to function */
    printf("Size of card hand pre-function: %d\n", testG.handCount[thisPlayer]);
    printf("\n");
        preHandCount = testG.handCount[thisPlayer];
    printf("Deck Count Pre: %d\n", testG.deckCount[thisPlayer]);
        preDeckCount= testG.deckCount[thisPlayer];
    printf("Discard Count Pre: %d\n", testG.discardCount[thisPlayer]);
        preDiscardCount= testG.discardCount[thisPlayer]; 
    printf("Player Turn: %d\n", testG.whoseTurn+1);
        playerTurnPre= testG.whoseTurn+1; 
    printf("Phase: %d\n", testG.phase);
        prePhase = testG.phase; 
    printf("Played Card Count: %d\n", testG.playedCardCount);
        prePlayedCardCount = testG.playedCardCount; 
    printf("Number of Buys: %d\n", testG.numBuys);
        preNumBuys = testG.numBuys; 
    printf("Number of Actions: %d\n", testG.numActions);
        preActions= testG.numActions; 
    printf("Supply Card Numbers: \n");
    printf("Estate: %d\n", testG.supplyCount[estate]);
        preEstate = testG.supplyCount[estate];
    printf("Duchy: %d\n", testG.supplyCount[duchy]);
        preDuchy = testG.supplyCount[duchy]; 
    printf("Province: %d\n", testG.supplyCount[province]);
        preProvince= testG.supplyCount[province]; 
    printf("\n");

    // Should be HandCount Post + Played Card = preHandCount + 3 

    printf("\n-----------------------------------------------------------------------\n"); 
    printf("Other Player Info Pre Function / Card Effect:\n"); 

    if (testG.whoseTurn==numPlayers-1)
    {
        otherPlayer = 0; 
    }

    else
    {
        otherPlayer = testG.whoseTurn + 1; 
    }

    printf("Deck Count Pre: %d\n", testG.deckCount[otherPlayer]);
    otherDeckPre= testG.deckCount[otherPlayer];
    printf("Discard Count Pre: %d\n", testG.discardCount[otherPlayer]);
    otherDiscardPre = testG.discardCount[otherPlayer]; 

    printf("\n-----------------------------------------------------------------------\n"); 


    /*----------------------- Function Call -----------------------------------------------*/ 

    cardEffect(card, choice1, choice2, choice3, &testG, handPos, coin_bonus);

    /*-------------------------------------------------------------------------------------*/ 

    /* print cards after adventurerCard is played  */
   /* Print Player 1 Hand & Details After adventurer Function */ 
    printf("Printing Cards AFTER village function is called: \n");
    for (m=0; m<testG.handCount[thisPlayer]; m++) {
            printf("(%d)", testG.hand[thisPlayer][m]);}
    printf("\n");
    printf("\n");
    /* call to function */
    printf("Size of card hand post-function: %d\n", testG.handCount[thisPlayer]);
    printf("\n");
        postHandCount = testG.handCount[thisPlayer];
    printf("Deck Count Post: %d\n", testG.deckCount[thisPlayer]);
        postDeckCount= testG.deckCount[thisPlayer];
    printf("Discard Count Post: %d\n", testG.discardCount[thisPlayer]);
        postDiscardCount= testG.discardCount[thisPlayer]; 
    printf("Player Turn: %d\n", testG.whoseTurn+1);
        playerTurnPost= testG.whoseTurn+1; 
    printf("Phase: %d\n", testG.phase);
        postPhase = testG.phase; 
    printf("Played Card Count: %d\n", testG.playedCardCount);
        postPlayedCardCount = testG.playedCardCount; 
    printf("Number of Buys: %d\n", testG.numBuys);
        postNumBuys = testG.numBuys; 
    printf("Number of Actions: %d\n", testG.numActions);
        postActions= testG.numActions; 
    printf("Supply Card Numbers: \n");
    printf("Estate: %d\n", testG.supplyCount[estate]);
        postEstate = testG.supplyCount[estate];
    printf("Duchy: %d\n", testG.supplyCount[duchy]);
        postDuchy = testG.supplyCount[duchy]; 
    printf("Province: %d\n", testG.supplyCount[province]);
        postProvince= testG.supplyCount[province]; 
    printf("\n");

    printf("\n-----------------------------------------------------------------------\n"); 
    printf("Other Player Info Post Function / Card Effect:\n"); 
    printf("Deck Count Post: %d\n", testG.deckCount[otherPlayer]);
    otherDeckPost = testG.deckCount[otherPlayer];
    printf("Discard Count Post: %d\n", testG.discardCount[otherPlayer]);
    otherDiscardPost = testG.discardCount[otherPlayer]; 
    

    /* Test Results */ 

    printf("------------------------------------------ Test Results: ------------------------------------------\n\n"); 
    
    score=0; 


    /* ----------- TEST 1: Checking for Drawing of 1 Card -------------- */
    printf("TEST 1: Checking for Drawing of 1 Cards \n");

    if (postHandCount - preHandCount ==0) // discard one to playedCard so 3 - 1 = 2 
    {
        printf("cardEffect(village): PASS - Hand was 1 Card bigger after the function than before as expected\n");
        score++;
        accumulatedScore++;}
    else
        printf("cardEffect(village): FAIL - Hand was not 1 Card bigger after the function than before as expected\n");

    printf("\n");


     /* ----------- TEST 2: All Cards Accounted For -------------- */
    printf("TEST 2: All Cards Accounted For \n");

    if (preDeckCount+preHandCount+prePlayedCardCount+preDiscardCount == postPlayedCardCount+postDeckCount+postHandCount+postDiscardCount) {
        printf("cardEffect(village): PASS - All Cards Accounted for, no cards lost\n"); 
        score++;
        accumulatedScore++; }
    else
        printf("cardEffect(village): FAIL - Not all Cards Accounted for, cards lost\n"); 


    //printf("need to finish desiging the test\n"); //2 Deck + Pre-Hand - Played Card Count Post = Post Hand - Pass or Fail 

    printf("\n");

    /* ----------- TEST 3: Making Sure Player Turn is not Changed -------------- */
    printf("TEST 3: Making Sure Player Turn is not Changed \n");

    if (playerTurnPre==playerTurnPost) {
        printf("cardEffect(village): PASS - Function did not change the player Turn as expected\n"); 
        score++;
        accumulatedScore++; }
    else 
        { printf("cardEffect(village): FAIL - Function changed the player turn in error\n");}

    printf("\n");

    /* ----------- TEST 4: Affirming Buys are not Changed -------------- */
    printf("TEST 4: Affirming Buys are not Changed \n");

    if (preNumBuys==postNumBuys) {
        printf("cardEffect(village): PASS - Function did not change the player buys count as expected\n"); 
        score++;
        accumulatedScore++;}
    else 
        { printf("cardEffect(village): FAIL - Function changed the player buys count in error\n"); }

    printf("\n");

    /* ----------- TEST 5: Affirming Actions are increased by 2 -------------- */
    printf("TEST 5: Affirming Actions are increased by 2 \n");

    if (preActions+2==postActions) {
        printf("cardEffect(village): PASS - Function increased actions by 2 count as expected\n"); 
        score++;
        accumulatedScore++; }
    else 
        { printf("cardEffect(village): FAIL - Function did not increase action count by 2, error\n"); }

    printf("\n");

    /* ----------- TEST 6: Affirming Supply Card Number Not Changed -------------- */
    printf("TEST 6: Affirming Supply Card Number Not Changed \n");

    if (preProvince==postProvince && preDuchy==postDuchy && preEstate==postEstate) {
        printf("cardEffect(village): PASS - Function did not change the player supply cards count as expected\n"); 
        score++;
        accumulatedScore++; }
    else 
        { printf("cardEffect(village): FAIL - Function changed the player supply cards count in error\n");}

    printf("\n");

    /* ----------- TEST 7: Unphased - Phase Stays the Same -------------- */
    printf("TEST 7: Unphased - Phase Stays the Same \n");

    if (prePhase==postPhase) {
        printf("cardEffect(village): PASS - Function did not change the game phase as expected\n"); 
        score++;
        accumulatedScore++; }
    else 
        { printf("cardEffect(village): FAIL - Function changed the game phase in error\n");}

    printf("\n");


    /* ----------- TEST 8: Affirming Other Player Deck Not Changed -------------- */
    printf("TEST 8: Affirming Other Player Deck Not Changed \n");

    if (otherDeckPre==otherDeckPost && otherDiscardPre==otherDiscardPost) {
        printf("cardEffect(village): PASS - Function did not change the other player's cards as expected\n"); 
        score++;
        accumulatedScore++; }
    else 
        { printf("cardEffect(village): FAIL - Function changed the othe player's cards in error\n"); }

    printf("\n");


    /*---------------------------------- Results ----------------------------------*/ 

    printf("---------------------------------- Results ----------------------------------\n\n");

    printf("%d out of %d tests passed\n", score, total); 

    if ((score/total)==1)
    {
        printf("All tests passed successfully\n"); 
    }

    printf("\n");



}

  printf("---------------------------------- Total Results ----------------------------------\n\n");

    printf("%d out of %d total tests passed\n", accumulatedScore, totalScore); 

    if ((accumulatedScore/totalScore)==1)
    {
        printf("All tests passed successfully\n"); 
    }

    printf("\n");


  return 0;
}

