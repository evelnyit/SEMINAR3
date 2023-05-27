
#ifndef SEMINAR3_EVELYN_SEMINAR3_H
#define SEMINAR3_EVELYN_SEMINAR3_H

/**
 * Struct to record one
 * part of a player's association
 * */
struct InnerPlayer {
    // name of the player
    char name;
    // index of the player according
    // to mapping defined in idx_players
    int idx;
    // total passes between the player
    // and her/his associated team mate
    int passes;
};

/**
 * Struct to record the other
 * part of a player's association
 * */
struct OuterPlayer {
    // name of the player
    char name;
    // number of player with whom
    // she/he has given/received passes
    int num_associations;
    // array of players with whom
    // she/he has exchanged passes
    struct InnerPlayer *associations;
};

//ToDo: TopPlayer Structure
/**
 * Struct to record the top player
 * */
struct TopPlayer {
    //name of the player
    char name;
    //degree of centrality: number of different
    //players the player has passed to or received a pass from
    int degree;
    //total number of passes the player made or received
    int total_passes;
};


/***
 * Function to create
 * the array of players with
 * whom a certain player has
 * exchanged passes
 *
 * Params:
 * - names (array): list of team mates with
 * whom a certain player has exchanged passes
 * - passes (array): list passes that
 * the player exchanged with her/his team mates
 * - num_player (int): number of players with
 * whom the player has exchanged passes
 * - idx_players (array): list that serves to map a numeric
 * index with the players' names
 * - total_player (int): total number of players
 * in the team
 * */
struct InnerPlayer* getInnerPlayers(char *names, int *passes, int    num_player,char *idx_players, int total_players);

/**
 * Function to create a player
 * and her/his associations; that is,
 * the list of team mates with whom
 * she/he has exchanged passes
 *
 * Params:
 * - name (char): name of the player
 * - num_associations (char): number of theam with whom
 * the player has exchanged passes
 * - inner_players (array): list of the player's
 * team mates
 * */
struct OuterPlayer getOuterPlayer(char name, int num_associations, struct InnerPlayer* inner_players);
/**
 * Function to populate the data structures
 * defined above with data of a given network
 * of passes
 * */
struct OuterPlayer* populatePassNet(int total_players);

//ToDo: Required functions

/**
 * Function to calculate the total passes exchanged
 * by the player with her/his team mates.
 * The function iterates through the player's association list
 * adding the number of passes.
 *
 * Params:
 * - player (array):  a list that contains the player and her/his associations;
 * */
int calculate_total_passes(struct OuterPlayer* player);

/**
 * Function to swap two TopPlayer elements
 *
 * Params:
 * - player_one, player_two (pointers to struct TopPlayer): two elements to be swapped
 */
void swapTopPlayers(struct TopPlayer *player_one, struct TopPlayer *player_two);

/**
 * Function to sort an array of TopPlayer in descending order based on their degree of centrality and total passes
 * The top player is determined first by the degree of centrality
 * (the unique players they've interacted with: passed to or received from).
 * If players have the same degree of centrality, the total number of passes made
 * by the player is then considered.
 * Params:
 * - arr (array of struct TopPlayer): array of players to be sorted
 * - total_players (int): number of elements(players) in the array
 */
void bubbleSortTopPlayers(struct TopPlayer arr[], int total_players);

/**
 * Function to find and print the top 3 players based on their degree of centrality and total passes.
 * This function uses the Bubble Sort algorithm to sort all players in descending order, and then prints the top three.
 *
 * Params:
 * - players (array of struct OuterPlayer): array of players and their associations
 * - total_players (int): number of players in the array
 */
void find_top_players(struct OuterPlayer* players, int total_players);

#endif //SEMINAR3_EVELYN_SEMINAR3_H
