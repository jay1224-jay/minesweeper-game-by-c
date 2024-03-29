/*
 * today is 2022/6/9
 * raw and column
 *   raw1, raw2, raw3
 * c1
 * c2
 * c3
 * 
 * -1 means bomb
 * 
*/


#ifndef MINESWEEPERH
#define MINESWEEPERH

#define ROWS    9
#define COLUMNS 9

#define clear() system("clear")

// color
#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"



#define ACTIVATE 1
#define FLAG     2
#define NOT      0

// number
// [3, 0]
//     activate , flag, or not
//        1        2        0
//



struct position {
    int x;
    int y;
} ;


typedef struct position pos;
typedef int map_type[COLUMNS][ROWS][2];


int map[COLUMNS][ROWS][2];

void show_map();
int number_of_near_bombs(pos curr);
void activate(pos curr);
void activate_all();
int check_win();
int near_pos( pos curr_pos , pos pos_arr[]);
void flag( pos curr);

/*
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




relative postion:
    -1  0  1
  -1 1  2  3
  0  4     5
  1  6  7  8

curr_pos = (x, y)


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
    return;

}

void activate_all(  ) {

    for (int y=0;y<COLUMNS;y++) {
        for (int x=0;x<ROWS;x++)
            map[y][x][1] = 1;
    }
}

void flag( pos curr ) {
    map[curr.y][curr.x][1] = 2; // flag mode
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

*/


#endif
