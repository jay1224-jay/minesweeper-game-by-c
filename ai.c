// ai.c

#include <stdio.h>
#include <stdio.h>
#include <unistd.h>

#include "common.h"
// #include "minesweeper.h"
//


void ai() 
{

    // first step:
    pos _p;
    _p.x = 0;
    _p.y = 0;
    activate(_p);



    for ( int y = 0 ; y < COLUMNS ; ++y ) {
        
        for ( int x = 0 ; x < ROWS ; ++x ) {

            clear();
            show_map_curr_pos(x, y);
            printf("current position:  %d   %d\n", x, y);
            usleep(300000);

            if ( map[y][x][0] == -1 || map[y][x][1] == NOT )
                continue;
            
            int block_number = map[y][x][0],    // number of near bombs
                flag_number = 0,                    // number of near flags
                not_number = 0;                     // number of not activated blocks 
            
            pos curr, pos_arr[8];

            curr.x = x;
            curr.y = y;

            int index = near_pos(curr, pos_arr);

            for ( int i = 0 ; i < index ; ++i ) {

                pos neighbor = pos_arr[i];

                switch ( map[neighbor.y][neighbor.x][1] ) {
                
                    case FLAG:
                        ++flag_number;
                        break;
                    case NOT:
                        ++not_number;
                        break;

                    default:
                        ; // null experssion

                }
                
            }


            /*
             
            for ( int i = 0 ; i < index ; ++i ) {
                pos p = pos_arr[i];
            }
             
              */
            // algorithm:  

            if ( block_number == flag_number && not_number > 0) {

                // the rest of the un-activated blocks are not bombs
                // so activate all

                for ( int i = 0 ; i < index ; ++i ) {
                    // sleep(1);
                    pos p = pos_arr[i];
                    if ( map[p.y][p.x][1] == NOT ) {
                        activate(p);
                    }
                }

            }
            else if ( block_number - flag_number == not_number ) {

                // the rest of the un-activated blocks are bombs
                // so flag all

                for ( int i = 0 ; i < index ; ++i ) {
                    // sleep(1);
                    pos p = pos_arr[i];
                    if ( map[p.y][p.x][1] == NOT ) {
                        flag(p);
                    }
                }

            }
            else {
                printf("no operation. Skip\n");
            }
        }
    }

}



