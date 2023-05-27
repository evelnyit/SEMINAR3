#include <stdio.h>
#include <stdlib.h>
#include "seminar3.h"

int main() {
    printf("SEMINAR 3. Graphs exercise\n");
    int total_players = 11;

    struct OuterPlayer* outplayers;

    outplayers = populatePassNet(total_players);
    find_top_players(outplayers, total_players);

    for (int i = 0; i < total_players; i++) {
        free(outplayers[i].associations);
    }
    free(outplayers);

    return 0;
}
