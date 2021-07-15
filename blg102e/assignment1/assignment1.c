#include <stdio.h> /* scanf and printf functions are used */ 

int main()
{
    /* points of players */
    int player1 = 0;
    int player2 = 0;

    /* scores of players */
    int score_player1 = 0;
    int score_player2 = 0;

    int choice = -1;
    while (1)
    {
        /* find the score of players */
        score_player1 = player1 * 15;
        score_player2 = player2 * 15;

        if (score_player1 > 40)
            score_player1 = 40;
        if (score_player2 > 40)
            score_player2 = 40;

        /* control whether players win the game */
        if (player1 >= 4 && player1 - player2 >= 2)
        {
            printf("GAME: PLAYER 1\n");
            return 0;
        }
        else if (player2 >= 4 && player2 - player1 >= 2)
        {
            printf("GAME: PLAYER 2\n");
            return 0;
        }

        /* if none of players won, control whether state is deuce or advantage. 
           if both score are under 40, print score table */
        if (score_player1 >= 40 && score_player2 >= 40)
        {
            if (player1 == player2)
                printf("DEUCE\n");
            else
                printf("ADVANTAGE: PLAYER %d\n", choice);
        }
        else
        {
            printf("%d-%d\n", score_player1, score_player2);
        }

        /* get input from user */
        printf("Point: ");
        scanf("%d", &choice);

        /* increase player's point by one depending on choice */
        switch (choice)
        {
        case 1:
            player1++;
            break;
        case 2:
            player2++;
            break;
        default:
            break;
        }
    }
}
