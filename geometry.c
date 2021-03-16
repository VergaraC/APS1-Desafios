#include <math.h>

#include "geometry.h"
#include <stdio.h>



int verify(point p, point a, point b) {
    
    //point p2;
    //eq de reta: mx + n
    int g =2;
    printf("Esse e o : %d ", g);

    int m = (a.y-b.y)/(a.x-b.x); //tg da linha
    printf("Esse e o M %d: ", m);
    int n = a.y-m*a.x; //constante da eq
    int p2y = p.y;
    int p2x = (p2y - n)/m;
    if (((p2x<a.x && p2x>b.x)||(p2x>a.x && p2x<b.x))&&((p2y<a.y && p2y>b.y)||(p2y>a.y && p2y<b.y))){
        printf("Esta entre os pontos");
        return 1;
    }
    else{
        return 0;
    }
    
}

int inside(point p, point poly[], int n) {
    return 0;
}
