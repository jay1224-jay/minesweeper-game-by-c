/*
 *  to-do list
 *  1. auto pand
 *
 *
 * */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "common.h"
// #include "minesweeper.h"

int map[COLUMNS][ROWS][2];

int main() {

    printf(KWHT);

    clear();

    printf("This is a minesweeper game by jay(or wuj).\n \
how to play:\n\
    1. type how many bombs you want\n\
    2. type the x-coordinate, y-coordinate, and mode ( \"a\" for activate and \"f\" forflag ) \n\
    example: if you want the position of (2, 3) and to activate it, type \"2 3 a\" and press Enter\n\
                                          x, y \n\
    3. if you want to exit, please press ctrl-c.\n\
    4. ENJOY!!\n\n\
");

    



    int number_bombs;
    
    printf("how many bombs do you want: ");
    scanf("%d", &number_bombs);

    if (number_bombs > COLUMNS * ROWS) {
        printf("too large number! must be smaller than %d * %d!\n", COLUMNS, ROWS);
        return 0;
    }

    clear();
    
    // plant bombs
    int b=0;
    srand(time(0));
    while ( b < number_bombs ) {
        int rand_x = rand() % ROWS; // 0~8

        int rand_y = rand() % COLUMNS;

        if ( map[rand_y][rand_x][0] == 0 ) {
            map[rand_y][rand_x][0] = -1;
            b++;
        }
    }
    // plant bombs

    // === set number ===
    // printf("\n%d\n", number_of_near_bombs(pos, map));


    for (int y=0;y<COLUMNS;y++) {
        for (int x=0;x<ROWS;x++) {
            if ( map[y][x][0] == 0  ) {
                pos curr;
                curr.x = x;
                curr.y = y;
                map[y][x][0] = number_of_near_bombs(curr);
            }
        }
    }

    // === set number ===
    
    /*

    pos p;
    p.x = 0;
    p.y = 1;

    pos arr[8];
    int number = near_pos(p, arr);

    for (int i=0;i<number;i++) {
        printf("(%d, %d)\n", arr[i].x, arr[i].y);
    }

    puts("finish near pos");

    int a;
    scanf("%d", &a);
    */

    
    // game loop
    /*
    activate_all(ptr_map);
    show_map(map);

    puts("");

    for (int y=0;y<COLUMNS;y++) {
        for (int x=0;x<ROWS;x++)
            *ptr_map[y][x][1] = 0;
    } */

    int times = 0;


    while (1) {
        ai();
        if ( check_win(map) ) {
            activate_all();
            puts("");
            show_map();
            puts("\n ===== AI ===== ");
            puts("");
            printf(" ======== you win ========\n");
            break;
            // return 0;
        }

        if ( ++times > 10 ) {
            printf("\n=============================================\n sorry, impossible to solve without guessing\n=============================================\n\n");
            break;
        }

    }


    /*
    while (1) {

        

        show_map();

        pos user_p;
        char mode;  // 'a' for activate and 'f' for flag

        printf("where and mode: ");
        scanf("%d %d %c", &(user_p.x), &(user_p.y), &mode);

        switch ( mode ) {

            case 'a':
        
                if ( map[user_p.y][user_p.x][0] == -1) { // current posion is bomb
                    clear();
                    printf("you just activate a bomb!\n");

                    // activate all

                    activate_all(  );
                    show_map();
                    
                    return 0; // end this game

                }

                activate(user_p);
                break; // stop case 'a'

            case 'f':
                flag(user_p);
                break;

            default:
                printf("%c is wrong input \n", mode);
                return 0;
        
        }

        if ( check_win(map) ) {
            activate_all();
            puts("");
            show_map();
            puts("");
            printf(" ======== you win ========\n");
            return 0;
        }

        clear();

    }
    */


    return 1;
}

