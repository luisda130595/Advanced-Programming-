#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    int W; // width of the building.
    int H; // height of the building.
    scanf("%d%d", &W, &H);
    int N; // maximum number of turns before game over.
    scanf("%d", &N);
    int X0;
    int Y0;
    scanf("%d%d", &X0, &Y0);
    
    int x1;
    int y1;
    int x2 = W-1;
    int y2 = H-1;

    // game loop
    while (1) {
        char bombDir[4]; // the direction of the bombs from batman's current location (U, UR, R, DR, D, DL, L or UL)
        scanf("%s", bombDir);
        
        if(strcmp(bombDir,"U")){
            Y0--;
        }else if(strcmp(bombDir, "D")){
            Y0++;
        }else if(strcmp(bombDir, "R")){\
            X0++;
        }else if(strcmp(bombDir, "L")){
            X0--;
        }else if(strcmp(bombDir, "UR")){
            X0++;
            Y0--;
        }else if(strcmp(bombDir, "UL")){
            X0--;
            Y0--;
        }else if(strcmp(bombDir, "DR")){
            X0++;
            Y0++;
        }else if(strcmp(bombDir, "DL")){
            X0--;
            Y0++;
        }
        
        printf("%d %d\n",X0,Y0);
    
        // Write an action using printf(). DON'T FORGET THE TRAILING \n
        // To debug: fprintf(stderr, "Debug messages...\n");


        // the location of the next window Batman should jump to.
        //printf("0 0\n");
    }

    return 0;
}