#include <stdio.h>
   
void display(char game[3][3]) {
    printf(" %c | %c | %c\n---|---|---\n %c | %c | %c\n---|---|---\n %c | %c | %c\n",game[0][0], game[0][1], game[0][2],
	game[1][0], game[1][1], game[1][2],
	game[2][0], game[2][1], game[2][2]);
}

char win(char game[3][3]) {
	int y;
	
    for (y = 0; y < 3; y++) {
        if (game[y][0] == game[y][1] && game[y][1] == game[y][2] && game[y][0] != '-') {
            return game[y][0];
        }
        if (game[0][y] == game[1][y] && game[1][y] == game[2][y] && game[0][y] != '-') {
            return game[0][y];
        }
    }

    if (game[0][0] == game[1][1] && game[1][1] == game[2][2] && game[0][0] != '-') {
        return game[0][0];
    }
    if (game[0][2] == game[1][1] && game[1][1] == game[2][0] && game[0][2] != '-') {
        return game[0][2];
    }
    return 't'; 
}


void play(char game[3][3]) {
    int turn[2];
    int z;
    char currentPlayer;
    
    for (z = 0; z < 9;z++){

     if (z % 2 == 0) {
       currentPlayer = 'X';
     } 
     else {
       currentPlayer = 'O';
     }

        printf("Player %c, enter your move (row and column, 0-2):\n", currentPlayer);
        
        while (1) {
            printf("Row: ");
            scanf("%d", &turn[0]);
            printf("Column: ");
            scanf("%d", &turn[1]);

            if (turn[0] >= 0 && turn[0] < 3 && turn[1] >= 0 && turn[1] < 3 && game[turn[0]][turn[1]] == '-') {
                break; 
            }
            printf("Invalid move. Please try again.\n");
        }

        game[turn[0]][turn[1]] = currentPlayer;
        display(game);
//        printf("%d\n",z);

        char result = win(game);
        if (result != 't') {
            printf("Player %c wins!\n", result);
            return;
        }
    }

    printf("It's a tie!\n");
}

int main() {
    char game[3][3] = {{'-', '-', '-'}, {'-', '-', '-'}, {'-', '-', '-'}};

    printf("Welcome to tic tac toe!\n");
    display(game);
    play(game);

    return 0;
}

