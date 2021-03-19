#include <math.h>
#include "geometry.h"
#include <stdio.h>

double condicao_especial = 0.000001;

int verify(point p, point a, point b) {
    point p2;
    point projecao;

    //eq de reta: mx + n
    int m;
    int bigY,smallY, xSmallY,xBigY, bigX, smallX;
    int c = a.x-b.x;
    
    if ((c > condicao_especial) || (c< -condicao_especial)){
        m = (a.y-b.y)/(c); //tg da linha
    } else {
        m = 0;
    }

    if (a.y >= b.y){
        bigY = a.y;
        xBigY = a.x;
        smallY = b.y;
        xSmallY = b.x;
    }else{
        bigY = b.y;
        xBigY =b.x;
        smallY = a.y;
        xSmallY = a.x;
    }
    if (a.x >= b.x){
        bigX = a.x;
        smallX = b.x;
    }else{
        bigX = b.x;
        smallX = a.x;
    }

    int n = a.y-m*a.x; //constante da eq
    p2.y = p.y;

    if (m != 0 ){
        p2.x = (p2.y - n)/m;
    }else{
        p2.x = a.x;
    }

    projecao.x = p.x;
    projecao.y = m*projecao.x + n;

    if ( (p2.x == p.x) && (p.y <= bigY && p.y >= smallY) && (!(p.y > smallY && p.y < bigY && p.x == smallX))){
        return 2;
    }else if ( (p2.y == a.y && p2.x == a.x) || ((p2.y == b.y) && (p2.x == b.x) && (p2.y < bigY)) && ((p.y <= smallY))){
        return 0;
    }else if( (p2.y <= bigY && p2.y >= smallY) && ( (p2.x <= bigX && p2.x >= smallX) && (p.x < bigX) ) && !(p.y == smallY && p.y < bigY)){
        return 1;
    } 
    return 0;
}

int inside(point p, point poly[], int n) {

    int atual, cont;
    for (int i = 0; i < n; i++){
        atual = verify(p, poly[i], poly[i+1]);
        if (atual){
            cont += 1;
        }else if (atual ==2){
            cont += 2;

        }
    }
    if(cont%2!=0){
        return 1;
    }
    return 0;

}
