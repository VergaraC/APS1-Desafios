#include <math.h>
#include "geometry.h"
#include <stdio.h>

double condicao_especial = 0.000001;

int verify(point p, point a, point b) {
    
    //point p2;
    //eq de reta: mx + n
    int m;
    int bigY,smallY, xSmallY,xBigY, bigX, smallX;
    int c = a.x-b.x;
    if ((c > condicao_especial) || (c < -condicao_especial)){
        m = (a.y-b.y)/(c); //tg da linha
    }else{
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
    printf("BigX : %d, xBigY: %d, xSmallY: %d,   \n", bigX, xBigY,xSmallY);
    int n = a.y-m*a.x; //constante da eq
    point p2; //Ponto em ue o raio cruza a reta
    p2.y = p.y;
    if (m != 0 ){
        p2.x = (p2.y - n)/m;
    }else{
        p2.x = a.x;
    }
    point projecao;
    projecao.x = p.x;
    projecao.y = m*projecao.x + n;
    printf(" Projecao: %d, %d \n", projecao.x, projecao.y);
   
   printf("p2: %d, %d   P:  %d, %d   A: %d, %d  B: %d, %d \n" , p2.x,p2.y,p.x,p.y, a.x, a.y, b.x, b.y);
    f ((p2.x == p.x) && ((p.y <= a.y && p.y >= b.y) || (p.y >= a.y && p.y <= b.y))){
        return 2;
    }else if ((p2.y == a.y && p2.x == a.x) || (((p2.y == b.y) && (p2.x == b.x)) &&((p2.y<a.y) || (p2.y< b.y)))){
        return 0;
    }else if(((p2.y <= a.y && p2.y >= b.y) || (p2.y <= b.y && p2.y >= a.y)) && (((p2.x <= a.x && p2.x >= b.x) || (p2.x <= b.x && p2.x >= a.x)) && ((p.x < a.x)|| (p.x < b.x)))){
        return 1;
    } /*
    if ((((p2.y == bigY) && (p2.x == xBigY) && ((p.y <= a.y && p.y >= b.y) || (p.y >= a.y && p.y <= b.y)))||((p.x == a.x && p.y == a.y)||(p.x == b.x && p.y == b.y))) || ((projecao.y == p.y && (projecao.y < bigY && projecao.y > smallY)&& (projecao.x < bigX && projecao.x > smallX))) && (p.y <= bigY && p.y >= smallY)){
            return 2;
    }else if (((p2.y == smallY) && (p2.x == xSmallY))||((p2.y == bigY) && (p2.x == xBigY))){
            return 0;
    }else if((p2.y <= bigY && p2.y >= smallY) && (p2.x <= bigX && p2.x >= smallX) ){
        if (m == 1 || projecao.y == p2.y){
            return 1;
        }
        
        return 0;
    } */
    return 0;
}

int inside(point p, point poly[], int n) {
    return 0;
}
