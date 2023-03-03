

#include <stdio.h>


#ifndef COMMON_H
#define COMMON_H


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


extern int map[COLUMNS][ROWS][2];

void show_map();
void show_map_curr_pos(int , int);
int number_of_near_bombs(pos curr);
void activate(pos curr);
void activate_all();
int check_win();
int near_pos( pos curr_pos , pos pos_arr[]);
void flag( pos curr);

void ai();


#endif
