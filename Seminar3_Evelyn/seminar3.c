
#include "seminar3.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct InnerPlayer* getInnerPlayers(char *names, int *passes, int num_player,char *idx_players, int total_players){
    // create the array of team mates
    struct InnerPlayer* inner_players =
            malloc(num_player * sizeof(struct InnerPlayer));

    // iterate over the team mates' data storing
    // them into the array
    for (int i = 0; i < num_player; i++) {
        inner_players[i].name = names[i];
        inner_players[i].passes = passes[i];
        // look for the index of the current team mate
        for (int j = 0; j < total_players; j++) {
            if (names[i] == idx_players[j]) {
                inner_players[i].idx = j;
                break;
            }
        }
    }
    return inner_players;
}

struct OuterPlayer getOuterPlayer(char name, int num_associations, struct InnerPlayer* inner_players){
    struct OuterPlayer outerplayer;

    outerplayer.name = name;
    outerplayer.num_associations = num_associations;
    outerplayer.associations = malloc(sizeof (struct InnerPlayer) * num_associations);
    memcpy(outerplayer.associations, inner_players, sizeof (struct InnerPlayer) * num_associations);

    return outerplayer;
}

struct OuterPlayer* populatePassNet(int total_players) {
    // array with the list of players' names. it serves
    // to map player's name with an integer index
    char idx_players[11] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I','J', 'K'};

    struct OuterPlayer* outerplayers = malloc(total_players * sizeof(struct OuterPlayer));

    // Populate player A
    char namesA[2] = { 'C', 'J' };
    int passesA[2] = { 20, 5 };
    struct InnerPlayer* inner_PA = getInnerPlayers(namesA, passesA, 2, idx_players, 11);
    outerplayers[0] = getOuterPlayer(idx_players[0], 2, inner_PA);

    // Populate player B
    char namesB[3] = {'E', 'C', 'K'};
    int passesB[3] = {15, 12, 2};
    struct InnerPlayer* inner_PB = getInnerPlayers(namesB, passesB, 3, idx_players, 11);
    outerplayers[1] = getOuterPlayer(idx_players[1], 3, inner_PB);

    // Populate player C
    char namesC[6] = {'D', 'F', 'G', 'J', 'A', 'B'};
    int passesC[6] = {12, 9, 4, 5, 20, 12};
    struct InnerPlayer* inner_PC = getInnerPlayers(namesC, passesC, 6, idx_players, 11);
    outerplayers[2] = getOuterPlayer(idx_players[2], 6, inner_PC);

    // Populate player D
    char namesD[2] = {'C', 'K'};
    int passesD[2] = {12, 20};
    struct InnerPlayer* inner_PD = getInnerPlayers(namesD, passesD, 2, idx_players, 11);
    outerplayers[3] = getOuterPlayer(idx_players[3], 2, inner_PD);

    // Populate player E
    char namesE[3] = {'J', 'K', 'B'};
    int passesE[3] = {20, 10, 15};
    struct InnerPlayer* inner_PE = getInnerPlayers(namesE, passesE, 3, idx_players, 11);
    outerplayers[4] = getOuterPlayer(idx_players[4], 3, inner_PE);

    // Populate player F
    char namesF[2] = {'K', 'C'};
    int passesF[2] = {11, 9};
    struct InnerPlayer* inner_PF = getInnerPlayers(namesF, passesF, 2, idx_players, 11);
    outerplayers[5] = getOuterPlayer(idx_players[5], 2, inner_PF);

    // Populate player G
    char namesG[3] = {'K', 'J', 'C'};
    int passesG[3] = {18, 13, 4};
    struct InnerPlayer* inner_PG = getInnerPlayers(namesG, passesG, 3, idx_players, 11);
    outerplayers[6] = getOuterPlayer(idx_players[6], 3, inner_PG);

    // Populate player H
    char namesH[2] = {'J', 'K'};
    int passesH[2] = {6, 4};
    struct InnerPlayer* inner_PH = getInnerPlayers(namesH, passesH, 2, idx_players, 11);
    outerplayers[7] = getOuterPlayer(idx_players[7], 2, inner_PH);

    // Populate player I
    char namesI[2] = {'J', 'K'};
    int passesI[2] = {9, 4};
    struct InnerPlayer* inner_PI = getInnerPlayers(namesI, passesI, 2, idx_players, 11);
    outerplayers[8] = getOuterPlayer(idx_players[8], 2, inner_PI);

    // Populate player J
    char namesJ[7] = {'K', 'A', 'C', 'E', 'G', 'H', 'I'};
    int passesJ[7] = {25, 5, 5, 20, 13, 6, 9};
    struct InnerPlayer* inner_PJ = getInnerPlayers(namesJ, passesJ, 7, idx_players, 11);
    outerplayers[9] = getOuterPlayer(idx_players[9], 7, inner_PJ);

    // Populate player K
    char namesK[8] = {'B', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    int passesK[8] = {2, 20, 10, 11, 18, 4, 4, 25};
    struct InnerPlayer* inner_PK = getInnerPlayers(namesK, passesK, 8, idx_players, 11);
    outerplayers[10] = getOuterPlayer(idx_players[10], 8, inner_PK);

    return outerplayers;
}

//ToDo: calculate_total_passes()
int calculate_total_passes(struct OuterPlayer* player) {
    //initialize the counter
    int total_passes = 0;

    //loop through all the associations(teammates) of the player
    for (int i = 0; i < player->num_associations; i++) {
        //add the number of passes to the total
        total_passes += player->associations[i].passes;
    }

    return total_passes;
}

//ToDo: swapTopPlayers()
void swapTopPlayers(struct TopPlayer *player_one, struct TopPlayer *player_two) {
    //create a temporary TopPlayer to hold the information of the first player
    struct TopPlayer temp = *player_one;
    //assign the second player's information to the first player
    *player_one = *player_two;
    //assign the stored information of the first player (in temp) to the second player
    *player_two = temp;
}

//ToDo: bubbleSortTopPlayers()
void bubbleSortTopPlayers(struct TopPlayer arr[], int total_players) {
    //loop for each element in the array
    for (int i = 0; i < total_players - 1; i++) {
        //nested loop for each unsorted element
        //last i elements are already in place
        for (int j = 0; j < total_players - i - 1; j++) {
            //if the current element has a lower degree or same degree
            //but fewer passes than the next one, swap them
            if (arr[j].degree < arr[j+1].degree || (arr[j].degree == arr[j+1].degree && arr[j].total_passes < arr[j+1].total_passes)) {
                swapTopPlayers(&arr[j], &arr[j+1]);
            }
        }
    }
}

//ToDo: find_top_players()
void find_top_players(struct OuterPlayer* players, int total_players) {
    //create an array of TopPlayer to store the degree and total passes of each player
    struct TopPlayer top_players[total_players];

    //for each player, fill in the degree and total passes
    for (int i = 0; i < total_players; i++) {
        top_players[i].name = players[i].name;
        top_players[i].degree = players[i].num_associations;
        top_players[i].total_passes = calculate_total_passes(&players[i]);
    }

    //sort the array of TopPlayer
    bubbleSortTopPlayers(top_players, total_players);

    //display the top 3 players
    for (int i = 0; i < 3; i++) {
        printf("Player %c: degree = %d, total passes = %d\n", top_players[i].name, top_players[i].degree, top_players[i].total_passes);
    }
}