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

    //caso dos quatro lados
    if(n == 4){
        point ponto1 = poly[0];
        point ponto2 = poly[1];
        point ponto3 = poly[2];
        point ponto4 = poly[3];
        int x_min = 100000000;
        int x_max = 0;
        int y_min = 100000000;
        int y_max = 0;
        for (int j=0; j<n; j++){
            if(poly[j].x > x_max){
                x_max = poly[j].x;
            } else if(poly[j].y > y_max){
                y_max = poly[j].y;
            }
            if(poly[j].x < x_min){
                x_min = poly[j].x;
            } else if(poly[j].y < y_min){
                y_min = poly[j].y;
            }
        }
        //checando de eh quadrado
        if((ponto1.x == x_min && ponto1.y == y_min) && (ponto2.x == x_min && ponto2.y == y_max) && (ponto3.x == x_max && ponto3.y == y_max) && (ponto4.x == x_max && ponto4.y == y_min)){
            if((p.x <= x_max && p.x >= x_min) && (p.y >= y_min && p.y <= y_max)){
                return 1;
            } else if((p.x < x_min && p.y < y_min) || (p.x > x_max && p.y > y_max) || (p.x > x_max && p.y < y_min) || (p.x < x_min && p.y > y_max) ||(p.x == x_min && p.y < y_min)||(p.x == x_max && p.y < y_min)||(p.x == x_min && p.y > y_max)||(p.x == x_max && p.y > y_max)||(p.y == y_max && p.x < x_min)||(p.y == y_min && p.x < x_min)||(p.y == y_max && p.x > x_max)||(p.y == y_min && p.x > x_max)||(p.x < x_max && p.x > x_min && p.y < y_min)){
                return 0;
            }
        } else{
            if(p.x < x_min && p.y < y_min ||
             (p.x == ponto4.x && p.y > y_max) ||
             (p.x == ponto1.x && p.x == x_min && p.y == ponto4.y && p.y == y_max) ||
             (p.y == ponto4.y && p.y == y_max && p.x < x_min) ||
             (p.x == ponto1.x && p.x == x_min && p.y == ponto2.y && p.x < ponto2.x) ||
             (p.y == ponto2.y && p.y == y_min && p.x < x_min && p.x < ponto1.x && p.x < ponto2.x)){
                return 0;
            } else if((p.x == ponto3.x && p.y == ponto3.y) || (p.x == ponto4.x && p.y == ponto4.y) || (p.x > x_min && p.x < x_max && p.y > y_min && p.x < y_max)){
                return 1;
            }
            // printf("%d\n", ponto3.x);
            // printf("%d\n", ponto3.y);
            // printf("losango\n");
        }
    } else if(n == 3){
        point ponto1 = poly[0];
        point ponto2 = poly[1];
        point ponto3 = poly[2];
        int x_min = 100000000;
        int x_max = 0;
        int y_min = 100000000;
        int y_max = 0;
        for (int j=0; j<n; j++){
            if(poly[j].x > x_max){
                x_max = poly[j].x;
            } else if(poly[j].y > y_max){
                y_max = poly[j].y;
            }
            if(poly[j].x < x_min){
                x_min = poly[j].x;
            } else if(poly[j].y < y_min){
                y_min = poly[j].y;
            }
        }
        if(
            ((p.y > ponto1.y && p.y < ponto2.y && p.x > ponto1.x && p.x < ponto3.x) ||
            (p.x == ponto1.x && p.y == ponto1.y) ||
            (p.x == ponto2.x && p.y == ponto2.y) ||
            (p.x == ponto3.x && p.y == ponto3.y))&&
            !(p.x == ponto1.x && p.y == ponto2.y && p.x == x_min && p.y == y_min)
        ){
            return 1;
        }else if( 
                (p.x < x_min && p.y < y_min) ||
                (p.x > x_max && p.y > y_max) ||
                (p.x > x_max && p.y < y_min) ||
                (p.x < x_min && p.y > y_max) ||
                (p.x == x_min && p.y < y_min)||
                (p.x == x_max && p.y < y_min)||
                (p.x == x_min && p.y > y_max)||
                (p.x == x_max && p.y > y_max)||
                (p.y == y_max && p.x < x_min)||
                (p.y == y_min && p.x < x_min)||
                (p.y == y_max && p.x > x_max)||
                (p.y == y_min && p.x > x_max)||
                (p.x < x_max && p.x > x_min && p.y < y_min) ||
                (p.x > ponto2.x && p.y == ponto2.y) ||
                (p.x > x_min && p.y > y_max && p.x < ponto3.x && p.y > ponto3.y) ||
                (p.x < x_min && p.y == ponto1.y) ||
                (p.x > x_min && p.x < x_max && p.y == y_max)
            ){
            return 0;
        }
    }

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