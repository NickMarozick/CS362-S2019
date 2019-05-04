#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>


int main() {
    int newCards = 0;
    int discarded = 1;
    int xtraCoins = 0;
    int shuffledCards = 0;
    int card = 16; // greatHall
    int i, j, m;
    int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
    int remove1, remove2;
    int seed = 1000;
    int numPlayers = 2;
    int thisPlayer = 0;
    struct gameState G, testG;
    int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
                        sea_hag, tribute, smithy, council_room};

    // initialize a game state and player cards
    initializeGame(numPlayers, k, seed, &G);


/* Unit Test 4 - greatHall Card */ 

/*
1 Draws correct amount of cards   - Pass or Fail 
2 Deck + Pre-Hand - Played Card Count Post = Post Hand - Pass or Fail 
3 Player Turn Does Not Change - Pass or Fail 
4 Buys & Actions Counts are What They Should be / Same - Pass or Fail 
5 Supply Card Number Remain Unchanged - Pass or Fail 
6 Phase stay the same - Pass or Fail 
7 Player2 Deck & Discard remain the same  */ 

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

    printf("----------------- Unit Test 4 - Testing Refactored GreatHall Function: ----------------\n\n");

  
    /*  copy the game state to a test case */
    memcpy(&testG, &G, sizeof(struct gameState));

    /* Print Player 1 Hand & Details Before Smithy Function */ 
    printf("Printing Cards BEFORE greatHall function is called: \n");
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

    greatHallCard(card, choice1, choice2, choice3, &testG, handpos, &bonus, thisPlayer);

    /*-------------------------------------------------------------------------------------*/ 

    /* print cards after adventurerCard is played  */
   /* Print Player 1 Hand & Details After Smithy Function */ 
    printf("Printing Cards AFTER greatHall function is called: \n");
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
    
    /* ----------- TEST 1: Checking for Drawing of 1 Card -------------- */
    printf("TEST 1: Checking for Drawing of 1 Cards \n");

    if (postHandCount - preHandCount ==0) // discard one to playedCard so 3 - 1 = 2 
    {
        printf("greatHallCard(): PASS - Hand was 1 Card bigger after the function than before as expected\n");
        score++;}
    else
        printf("greatHallCard(): FAIL - Hand was not 1 Card bigger after the function than before as expected\n");

    printf("\n");


     /* ----------- TEST 2: All Cards Accounted For -------------- */
    printf("TEST 2: All Cards Accounted For \n");

    if (preDeckCount+preHandCount+prePlayedCardCount+preDiscardCount == postPlayedCardCount+postDeckCount+postHandCount+postDiscardCount) {
        printf("greatHallCard(): PASS - All Cards Accounted for, no cards lost\n"); 
        score++; }
    else
        printf("greatHallCard(): FAIL - Not all Cards Accounted for, cards lost\n"); 


    //printf("need to finish desiging the test\n"); //2 Deck + Pre-Hand - Played Card Count Post = Post Hand - Pass or Fail 

    printf("\n");

    /* ----------- TEST 3: Making Sure Player Turn is not Changed -------------- */
    printf("TEST 3: Making Sure Player Turn is not Changed \n");

    if (playerTurnPre==playerTurnPost) {
        printf("greatHallCard(): PASS - Function did not change the player Turn as expected\n"); 
        score++; }
    else 
        { printf("greatHallCard(): FAIL - Function changed the player turn in error\n");}

    printf("\n");

    /* ----------- TEST 4: Affirming Buys are not Changed -------------- */
    printf("TEST 4: Affirming Buys are not Changed \n");

    if (preNumBuys==postNumBuys) {
        printf("greatHallCard(): PASS - Function did not change the player buys count as expected\n"); 
        score++;}
    else 
        { printf("greatHallCard(): FAIL - Function changed the player buys count in error\n"); }

    printf("\n");

    /* ----------- TEST 5: Affirming Actions are increased by 2 -------------- */
    printf("TEST 5: Affirming Actions are increased by 1 \n");

    if (preActions+1==postActions) {
        printf("greatHallCard(): PASS - Function increased actions by 1 count as expected\n"); 
        score++;}
    else 
        { printf("greatHallCard(): FAIL - Function did not increase action count by 1, error\n"); }

    printf("\n");

    /* ----------- TEST 6: Affirming Supply Card Number Not Changed -------------- */
    printf("TEST 6: Affirming Supply Card Number Not Changed \n");

    if (preProvince==postProvince && preDuchy==postDuchy && preEstate==postEstate) {
        printf("greatHallCard(): PASS - Function did not change the player supply cards count as expected\n"); 
        score++; }
    else 
        { printf("greatHallCard(): FAIL - Function changed the player supply cards count in error\n");}

    printf("\n");

    /* ----------- TEST 7: Unphased - Phase Stays the Same -------------- */
    printf("TEST 7: Unphased - Phase Stays the Same \n");

    if (prePhase==postPhase) {
        printf("greatHallCard(): PASS - Function did not change the game phase as expected\n"); 
        score++; }
    else 
        { printf("greatHallCard(): FAIL - Function changed the game phase in error\n");}

    printf("\n");


    /* ----------- TEST 8: Affirming Other Player Deck Not Changed -------------- */
    printf("TEST 8: Affirming Other Player Deck Not Changed \n");

    if (otherDeckPre==otherDeckPost && otherDiscardPre==otherDiscardPost) {
        printf("greatHallCard(): PASS - Function did not change the other player's cards as expected\n"); 
        score++; }
    else 
        { printf("greatHallCard(): FAIL - Function changed the othe player's cards in error\n"); }

    printf("\n");


    /*---------------------------------- Results ----------------------------------*/ 

    printf("---------------------------------- Results ----------------------------------\n\n");

    printf("%d out of %d tests passed\n", score, total); 

    if ((score/total)==1)
    {
        printf("All tests passed successfully\n"); 
    }

    printf("\n");


return 0;
}

