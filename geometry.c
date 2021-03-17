#include <math.h>
#include "geometry.h"
#include <stdio.h>

int verify(point p, point a, point b) {
    
    //point p2;
    //eq de reta: mx + n
    int m = 0;
    int c = a.x-b.x;
    if (c > 0.000001){
        m = (a.y-b.y)/(c); //tg da linha
    }
    int n = a.y-m*a.x; //constante da eq
    point p2;
    p2.y = p.y;
    if (m != 0 ){
        p2.x = (p2.y - n)/m;
    }else{
        p2.x = a.x;
    }
    point projecao;
    projecao.x = p.x;
    projecao.y = m*projecao.x + n;
   //(projecao.y < p.y) && 
   if ((p2.x == p.x) && !(p.y< a.y && p.y < b.y )){
       return 2;
   }else if(((p2.y <= a.y && p2.y >= b.y) || (p2.y <= b.y && p2.y >= a.y)) && ((p2.x <= a.x && p2.x >= b.x) || (p2.x <= b.x && p2.x >= a.x)) && ((p.x < a.x)|| (p.x < b.x))){
        if ((p2.y == a.y && p2.x == a.x) || (p2.y == b.y && p2.x == b.x) &&((p2.y<a.y) || (p2.y< b.y))){
            return 0;
        }
        return 1;
    }
    return 0;
}

int inside(point p, point poly[], int n) {
    return 0;
}
