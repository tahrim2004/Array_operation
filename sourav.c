#include <stdio.h>

char board[9] = {'1','2','3','4','5','6','7','8','9'};


void printBoard() {
    printf("\nCurrent Board:\n");
    printf(" %c | %c | %c\n", board[0], board[1], board[2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c\n", board[3], board[4], board[5]);
    printf("---|---|---\n");
    printf(" %c | %c | %c\n\n", board[6], board[7], board[8]);
}


int isWinner(char m) {
    return (board[0]==m && board[1]==m && board[2]==m) ||
           (board[3]==m && board[4]==m && board[5]==m) ||
           (board[6]==m && board[7]==m && board[8]==m) ||
           (board[0]==m && board[3]==m && board[6]==m) ||
           (board[1]==m && board[4]==m && board[7]==m) ||
           (board[2]==m && board[5]==m && board[8]==m) ||
           (board[0]==m && board[4]==m && board[8]==m) ||
           (board[2]==m && board[4]==m && board[6]==m);
}

int main() {
    int move, turn = 0;
    char mark;

    printf("WELCOME TO TIC-TAC-TOE!\n");
    printf("Player 1: X\tPlayer 2: O\n");
    printf("Choose positions from 1 to 9 as shown below:\n");
    printf(" 1 | 2 | 3\n");
    printf("---|---|---\n");
    printf(" 4 | 5 | 6\n");
    printf("---|---|---\n");
    printf(" 7 | 8 | 9\n");

    while (turn < 9) {
        printBoard();


        mark = (turn % 2 == 0) ? 'X' : 'O';
        printf("Player %d (%c), enter position (1-9): ", (turn % 2) + 1, mark);
        scanf("%d", &move);
        move -= 1;


        if (move < 0 || move > 8 || board[move] == 'X' || board[move] == 'O') {
            printf("Invalid move. Try again.\n");
            continue;
        }

        board[move] = mark;

        if (isWinner(mark)) {
            printBoard();
            printf("🎉 CONGRATULATIONS! PLAYER %d WINS!\n", (turn % 2) + 1);
            return 0;
        }

        turn++;
    }

    printBoard();
    printf("🤝 It's a DRAW!\n");
    return 0;
}
