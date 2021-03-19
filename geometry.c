#include <math.h>
#include "geometry.h"
#include <stdio.h>

double condicao_especial = 0.000001;

int verify(point p, point a, point b) {
    point p2, projecao, pXmin, pXmin2;

    //eq de reta: mx + n
    int m;
    int bigY,smallY, xSmallY,xBigY, bigX, yBigX, smallX, ySmallx;
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
        yBigX = a.y;
        smallX = b.x;
        ySmallx = b.y;
    }else{
        bigX = b.x;
        yBigX = b.y;
        smallX = a.x;
        ySmallx = a.y;

    }
    printf("BigX : %d, xBigY: %d, xSmallY: %d,   \n", bigX, xBigY,xSmallY);
    int n = a.y-m*a.x; //constante da eq
    p2.y = p.y;

    if (m != 0 ){
        p2.x = (p2.y - n)/m;
    }else{
        p2.x = a.x;
    }
    projecao.x = p.x;
    projecao.y = m*projecao.x + n;

    pXmin2.x = smallX;
    pXmin2.y = yBigX;
    pXmin.x = smallX;
    pXmin.x = ySmallx; 


    printf(" Projecao: %d, %d \n", projecao.x, projecao.y);
    printf("p2: %d, %d   P:  %d, %d   A: %d, %d  B: %d, %d \n" , p2.x,p2.y,p.x,p.y, a.x, a.y, b.x, b.y);
    
    if ( (p2.x == p.x) && (p.y <= bigY && p.y >= smallY) && (!(p.y > smallY && p.y < bigY && p.x == smallX))|| (p.x == smallX && p.x == ySmallx)){
        return 2; //(p2.x == xBigY && p2.y == bigY )
    }else if((p.y == a.y && p.y == b.y)){
        return 2;
    }else if ( (p2.y == a.y && p2.x == a.x) || ((p2.y == b.y) && (p2.x == b.x) && (p2.y < bigY)) && ((p.y <= smallY))){
        return 0;
    
    }else if( (p2.y <= bigY && p2.y >= smallY) && ( (p2.x <= bigX && p2.x >= smallX) && (p.x < bigX) ) && !(p.y == smallY && p.y < bigY)){
        //if (m==0 ||verify(p, pXmin, pXmin2)==1){
            return 1;
       // }
        
    } 
    return 0;
}

int inside(point p, point poly[], int n) {

     if(n == 4){
        point ponto1 = poly[0];
        point ponto2 = poly[1];
        point ponto3 = poly[2];
        point ponto4 = poly[3];
        int xMin = 100000000;
        int xMax = 0;
        int yMin = 100000000;
        int yMax = 0;
        for (int j=0; j<n; j++){
            if(poly[j].x > xMax){
                xMax = poly[j].x;
            } else{
                yMax = poly[j].y;
            }
            if(poly[j].x < xMin){
                xMin = poly[j].x;
            } else{
                yMin = poly[j].y;
            }
        }
        printf("xMin: %d, yMin: %d, xMax: %d, yMax: %d \n", xMin, yMin, xMax, yMax);
        if((ponto1.x == xMin && ponto1.y == yMin) && (ponto2.x == xMin && ponto2.y == yMax) && (ponto3.x == xMax && ponto3.y == yMax) && (ponto4.x == xMax && ponto4.y == yMin)){
            printf("quadrado \n");
        }

        if((p.x < xMax && p.x >= xMin) && (p.y >= yMin && p.y <= yMax)){
            return 1;
        }
        
    // } else if(n == 3){
    //     point ponto1 = poly[0];
    //     point ponto2 = poly[1];
    //     point ponto3 = poly[2];
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
