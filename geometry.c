#include <math.h>
#include "geometry.h"
#include <stdio.h>

double condicao_especial = 0.000001;

int x_max;
int x_min;
int y_max;
int y_min;
int ponto_na_reta;
point p2;
point point_x_max;
point point_y_max;
point point_x_min;
point point_y_min;

int define_x_max(point a, point b){
    if(a.x > b.x){
        x_max = a.x;
    } else{
        x_max = b.x;
    }
    return x_max;
}

int define_y_max(point a, point b){
    if(a.y > b.y){
        y_max = a.y;
    } else{
        y_max = b.y;
    }
    return y_max;
}

int define_x_min(point a, point b){
    if(a.x > b.x){
        x_min = b.x;
    } else{
        x_min = a.x;
    }
    return x_min;
}

int define_y_min(point a, point b){
    if(a.y > b.y){
        y_min = b.y;
    } else{
        y_min = a.y;
    }
    return y_min;
}

int vertical(point a, point b){
    if(a.x == b.x){
        return 1;
    }
    return 0;
}

int horizontal(point a, point b){
    if(a.y == b.y){
        return 1;
    }
    return 0;
}

int dentro_linha(point p, point a, point b){
    x_max = define_x_max(a,b);
    y_max = define_y_max(a,b);
    x_min = define_y_min(a,b);
    y_min = define_y_min(a,b);

    if(((p.x >= x_min) && (p.x <= x_max)) && ((p.y >= y_min) && (p.y <= y_max))){
        return 1;
    }
    return 0;
}

int azul(point p, point a, point b){
    x_max = define_x_max(a,b);
    y_max = define_y_max(a,b);
    x_min = define_y_min(a,b);
    y_min = define_y_min(a,b);

    if(p.x > x_max){
        return 0;
    }

    double m, p2x;
    int p2y;

    if (a.x-b.x == 0){
        m = 0;
    } else {
        m = (double)(a.y-b.y)/(a.x-b.x); //tg da linha
    }
    
    if(m*(p.x - a.x) + a.y - p.y == 0){
        ponto_na_reta = 1;
    } else{
        ponto_na_reta = 0;
    }

    double n = a.y-m*a.x; //constante da eq
    p2y = p.y;
    if (m != 0 ){
        p2x = (double)(p.y - n)/m;
    }else{
        p2x = (double) a.x;
    }
    if(a.x > b.x){
        point_x_max = a;
        point_x_min = b;
    } else{
        point_x_max = b;
        point_x_min = a;
    }

    if(a.y > b.y){
        point_y_max = a;
        point_y_min = b;
    } else{
        point_y_max = b;
        point_y_min = a;
    }
    if (p2x< p.x){
        return 0;
    }
    if((p2y == point_y_min.y && p2x - point_y_min.x <= condicao_especial)){
        return 0;
    }else if((p2y == point_y_max.y && p2x - point_y_max.x <= condicao_especial)|| ((p2x < point_x_max.x && p2x > point_x_min.x) && (p2y < point_y_max.y && p2y > point_y_min.y))){
        return 1;
    }
    if(vertical(a,b)){
        if(dentro_linha(p,a,b)){
            return 1;
        }
        return 0;
    } else if(horizontal(a,b)){
        if(dentro_linha(p,a,b)){
            return 1;
        }
        return 0;
    
    }
    
    
    return 0;
}

int preto(point p, point a, point b){
    double m;

    int delta_x = a.x-b.x;

    if (delta_x == 0){
        m = 0;
    } else {
        m = (double)(a.y-b.y)/(delta_x); //tg da linha
    }
    
    if((p.y-a.y) - (m*(p.x-a.x)) == 0){
        ponto_na_reta = 1;
    } else{
        ponto_na_reta = 0;
    }
    if(!(dentro_linha(p,a,b))){
        return 0;
    }
    if(vertical(a,b)){
        if(p.x == a.x && (dentro_linha(p,a,b))){
            return 1;
        }
        return 0;
    } else if(horizontal(a,b)){

        if(((p.y == a.y && p.y == b.y) && !(p.x < a.x && p.x < b.x))){
            return 1;
        }
        return 0;
    }
    if((p.x == a.x && p.y == a.y) ||(p.x == b.x && p.y == b.y) || (ponto_na_reta && ((p.x >= x_min && p.x <= x_max) || (p.y >= y_min && p.y <= y_max)))){
        return 1;
    } 
    return 0;
}

int verify(point p, point a, point b) {
    if(preto(p,a,b)){
        return 2;
    } else if(azul(p,a,b)){
        return 1;
    }
    return 0;
}

int inside(point p, point poly[], int n) {
    int atual, cont;
    for (int i = 0; i < n; i++){
        if(i == n-1){
            atual = verify(p, poly[i], poly[0]);
        } else{
            atual = verify(p, poly[i], poly[i+1]);
            if (atual){
                cont += 1;
            }else if (atual ==2){
                cont += 2;
            }
        }
    }
    if(cont%2!=0){
        return 1;
    }
    return 0;

}