
#include "common.h"
// #include "minesweeper.h"
#include <stdio.h>

void show_map() {

    printf("    ");
    for (int index_x=0;index_x<ROWS;index_x++) {
        printf("%2d ", index_x);
    }
    puts("");

    for(int y=0;y<COLUMNS;y++) {

        printf(" %2d ", y);

        for (int x=0;x<ROWS;x++) {
            if ( map[y][x][1] == 1 ) {
                if ( map[y][x][0] == -1) { 
                    printf( KGRN "%2d " KWHT, -1);
                    continue;
                }
                printf( KWHT "%2d " KWHT , map[y][x][0]);
            } else if ( map[y][x][1] == 2 ) {
                printf( KRED " F " KWHT );
            } else {
                printf( KWHT " - " KWHT );
            }
        }

        puts("");
        
    }
}


void show_map_curr_pos(int curr_x, int curr_y) {

    printf("    ");
    for (int index_x=0;index_x<ROWS;index_x++) {
        printf("%2d ", index_x);
    }
    puts("");

    for(int y=0;y<COLUMNS;y++) {

        printf(" %2d ", y);

        for (int x=0;x<ROWS;x++) {

            if ( x == curr_x && y == curr_y ) {
                printf( KCYN "%2d " KWHT , map[y][x][0]);
            }
            else if ( map[y][x][1] == 1 ) {
                if ( map[y][x][0] == -1) { 
                    printf( KGRN "%2d " KWHT, -1);
                    continue;
                }
                printf( KWHT "%2d " KWHT , map[y][x][0]);
            } else if ( map[y][x][1] == 2 ) {
                printf( KRED " F " KWHT );
            } else {
                printf( KWHT " - " KWHT );
            }
        }

        puts("");
        
    }
}


/*

relative postion:
    -1  0  1
  -1 1  2  3
  0  4     5
  1  6  7  8

curr_pos = (x, y)
*/

int number_of_near_bombs(pos curr) {


    int number = 0, index=0;
    pos pos_arr[8];

    index = near_pos( curr, pos_arr );

    for (int i=0;i<index;i++) {
        pos neighbor = pos_arr[i];
        if ( map[neighbor.y][neighbor.x][0] == -1 )
            number++;
    }
      

    return number;

}

void activate(pos curr) {
    map[curr.y][curr.x][1] = ACTIVATE;
    if ( map[curr.y][curr.x][0] != 0 )
        return;

    pos pos_arr[8];
    int index;

    index = near_pos( curr, pos_arr );

    for (int i = 0;i<index;i++) {
        pos neighbor = pos_arr[i];

        if ( map[neighbor.y][neighbor.x][1] == 0)
            activate( neighbor );
    }
    

    // clear();
    show_map();


    return;

}

void activate_all(  ) {

    for (int y=0;y<COLUMNS;y++) {
        for (int x=0;x<ROWS;x++)
            map[y][x][1] = 1;
    }
    // clear();
    show_map();
}

void flag( pos curr ) {
    map[curr.y][curr.x][1] = 2; // flag mode
    // clear();
    show_map();
}


// the condition of win:  all of not bombs are activated

int check_win( ) {

    for (int y=0;y<COLUMNS;y++) {
        for (int x=0;x<ROWS;x++) {
            if (map[y][x][0] != -1 && map[y][x][1] == 0) { // 0 means not activated
                return 0; // not yet win
            }
        }
    }

    return 1; // win

}


int near_pos( pos curr_pos, pos pos_arr[]) {
    
    pos add_pos;
    int index = 0;

    if ( (curr_pos.y-1) >= 0 ) {
        // 1
        if ( (curr_pos.x-1) >= 0 ) {
            add_pos.x = curr_pos.x - 1;
            add_pos.y = curr_pos.y - 1;
            pos_arr[index] = add_pos;
            index++;
        }
            
        // 2

        add_pos.x = curr_pos.x;
        add_pos.y = curr_pos.y - 1;
        pos_arr[index] = add_pos;
        index++;


            // 3
        if ( (curr_pos.x+1) < ROWS) {

            add_pos.x = curr_pos.x + 1;
            add_pos.y = curr_pos.y - 1;
            pos_arr[index] = add_pos;
            index++;

        }
    }

        // 4
    if ( (curr_pos.x-1) >= 0 ) {

        add_pos.x = curr_pos.x - 1;
        add_pos.y = curr_pos.y;
        pos_arr[index] = add_pos;
        index++;
    }

    // 5
    if ( (curr_pos.x+1) < ROWS ) {

        add_pos.x = curr_pos.x + 1;
        add_pos.y = curr_pos.y;
        pos_arr[index] = add_pos;
        index++;
    }


    if ( (curr_pos.y+1) < COLUMNS ) {
        // 6
        if ( (curr_pos.x-1) >= 0 ) { 
            add_pos.x = curr_pos.x - 1;
            add_pos.y = curr_pos.y + 1;
            pos_arr[index] = add_pos;
            index++;
        }

        // 7

        add_pos.x = curr_pos.x;
        add_pos.y = curr_pos.y + 1;
        pos_arr[index] = add_pos;
        index++;

        // 8
        if ( (curr_pos.x+1) < ROWS) {

            add_pos.x = curr_pos.x + 1;
            add_pos.y = curr_pos.y + 1;
            pos_arr[index] = add_pos;
            index++;
        }
    }

    return index;

}
