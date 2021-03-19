#include <math.h>
#include "geometry.h"
#include <stdio.h>

double condicao_especial = 0.000001;

int verify(point p, point a, point b) {
    
    point p2, projecao, p_x_min,big_x, big_y, small_x, small_y;
    //eq de reta: mx + n
    int m;
    int c = a.x-b.x;
    
    if ((c > condicao_especial) || (c< -condicao_especial)){
        m = (a.y-b.y)/(c); //tg da linha
    } else {
        m = 0;
    }
    if (a.y >= b.y){
        big_y.y = a.y;
        big_y.x = a.x;
        small_y.y = b.y;
        small_y.x = b.x;
    }else{
        big_y.y = b.y;
        big_y.x =b.x;
        small_y.y = a.y;
        small_y.x = a.x;
    }
    if (a.x >= b.x){
        big_x.x = a.x;
        big_x.y = a.y;
        small_x.x = b.x;
        small_x.y = b.y;
    }else{
        big_x.x = b.x;
        big_x.y = b.y;
        small_x.x = a.x;
        small_x.y = a.y;

    }
    printf("Big_x.x : %d, big_y.x: %d, small_y.x: %d,   \n", big_x.x, big_y.x,small_y.x);
    int n = a.y-m*a.x; //constante da eq
    p2.y = p.y;

    if (m != 0 ){
        p2.x = (p2.y - n)/m;
    }else{
        p2.x = a.x;
    }
    projecao.x = p.x;
    projecao.y = m*projecao.x + n;

    p_x_min.x = small_x.x;
    p_x_min.y = big_x.y;
   

    printf(" Projecao: %d, %d \n", projecao.x, projecao.y);
    printf("p2: %d, %d   P:  %d, %d   A: %d, %d  B: %d, %d \n" , p2.x,p2.y,p.x,p.y, a.x, a.y, b.x, b.y);
    
    if ( (((p2.x == p.x) && (p.y <= big_y.y && p.y >= small_y.y)) && (!(p.y > small_y.y && p.y < big_y.y && p.x == small_x.x)))|| (p.x == small_x.x && p.x == small_x.y)){
        return 2; //(p2.x == big_y.x && p2.y == big_y.y )
    }else if((p.y == a.y && p.y == b.y)){
        return 2;
    }else if ( (p2.y == a.y && p2.x == a.x) || (((p2.y == b.y) && (p2.x == b.x) && (p2.y < big_y.y)) && ((p.y <= small_y.y)))){
        return 0;
    }else if( (p2.y <= big_y.y && p2.y >= small_y.y) && ( (p2.x <= big_x.x && p2.x >= small_x.x) && (p.x < big_x.x) ) && !(p.y == small_y.y && p.y < big_y.y)){
        //if (m==0 ||verify(p, small_x, p_x_min)==1){ -Recursiva para os de cruza
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
        int x_min = 100000000;
        int x_max = 0;
        int y_min = 100000000;
        int y_max = 0;
        for (int j=0; j<n; j++){
            if(poly[j].x > x_max){
                x_max = poly[j].x;
            } else{
                y_max = poly[j].y;
            }
            if(poly[j].x < x_min){
                x_min = poly[j].x;
            } else{
                y_min = poly[j].y;
            }
        }
        printf("x_min: %d, y_min: %d, x_max: %d, y_max: %d \n", x_min, y_min, x_max, y_max);
        if((ponto1.x == x_min && ponto1.y == y_min) && (ponto2.x == x_min && ponto2.y == y_max) && (ponto3.x == x_max && ponto3.y == y_max) && (ponto4.x == x_max && ponto4.y == y_min)){
            printf("quadrado \n");
        }

        if((p.x < x_max && p.x >= x_min) && (p.y >= y_min && p.y <= y_max)){
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