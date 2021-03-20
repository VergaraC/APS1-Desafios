#include <math.h>
#include "geometry.h"
#include <stdio.h>

double condicao_especial = 0.000001;

<<<<<<< HEAD

int dentro(point p, point big_y, point small_y, point big_x, point small_x){
    if ((p.x<= big_x.x && p.x >= small_x.x) && (p.y<= big_y.y && p.y >= small_x.y)){
        return 1; //ta dentro dos limites
    }
    return 0; //fora dos limites
}
int igual_ao_ponto(point p, point big_y, point small_y, point big_x, point small_x){
    if (p.x == big_y.x && p.y == big_y.y){
        return 1; //igual ao maior Y
    } else if (p.x == small_y.x && p.y == small_y.y){
        return 2; //igual ao menor Y
    }
    return 0; // n eh igual a nenhum
}
int ta_na_linha(point p, point p2, point big_y, point small_y, point big_x, point small_x){
    if ((p2.x == p.x && p2.y == p.y) && (p.y <= big_y.y && p.y >= small_y.y)){
        return 1; // ta na linha
    }
    return 0; // m ta
}
int esquerda(point p, point big_y, point small_y, point big_x, point small_x){
    
    if (p.x < big_x.x){
        return 1;
    }
    return 0;
}

int verify(point p, point a, point b) {
    point p2, big_y, small_y, big_x, small_x;
    point projecao;

    //eq de reta: mx + n
    int m;
    int c = a.x-b.x;
    
    if ((c > condicao_especial) || (c< -condicao_especial)){
        m = (a.y-b.y)/(c); //tg da linha
    } else {
        m = 0;
=======
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
>>>>>>> 65373bd78c5f1e2f54eec1179705f370838af353
    }
    return x_max;
}

<<<<<<< HEAD
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
    }else{
        big_x.x = b.x;
        big_x.y = b.y;
        small_x.x = a.x;
        small_x.x = a.x;
=======
int define_y_max(point a, point b){
    if(a.y > b.y){
        y_max = a.y;
    } else{
        y_max = b.y;
>>>>>>> 65373bd78c5f1e2f54eec1179705f370838af353
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

    if((p.x >= x_min && p.x <= x_max) && (p.y >= y_min && p.y <= y_max)){
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

    double m;

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
    p2.y = p.y;
    if (m != 0 ){
        p2.x = (p2.y - n)/m;
    }else{
        p2.x = a.x;
    }

<<<<<<< HEAD
    projecao.x = p.x;
    projecao.y = m*projecao.x + n;
    if(ta_na_linha (p, p2, big_y, small_y, big_x, small_x) || (igual_ao_ponto(p, big_y, small_y, big_x, small_x)!= 0) && (!(p.y > small_y.y && p.y < big_y.y && p.x == small_x.x))){
        return 2;
    }else if(!(dentro(p2, big_y, small_y, big_x, small_x)) || !(esquerda(p, big_y, small_y, big_x, small_x))){
        return 0;
    }else if( (dentro(p2, big_y, small_y, big_x, small_x)  || igual_ao_ponto(p2, big_y, small_y, big_x, small_x))){
=======
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

    if((p2.y == point_y_max.y && p2.x == point_y_max.x)){
>>>>>>> 65373bd78c5f1e2f54eec1179705f370838af353
        return 1;
    }
    return 0;
}

int preto(point p, point a, point b){
    double m;

<<<<<<< HEAD
    //caso dos quatro lados
    // if(n == 4){
    //     point ponto1 = poly[0];
    //     point ponto2 = poly[1];
    //     point ponto3 = poly[2];
    //     point ponto4 = poly[3];
    //     int x_min = 100000000;
    //     int x_max = 0;
    //     int y_min = 100000000;
    //     int y_max = 0;
    //     for (int j=0; j<n; j++){
    //         if(poly[j].x > x_max){
    //             x_max = poly[j].x;
    //         } else if(poly[j].y > y_max){
    //             y_max = poly[j].y;
    //         }
    //         if(poly[j].x < x_min){
    //             x_min = poly[j].x;
    //         } else if(poly[j].y < y_min){
    //             y_min = poly[j].y;
    //         }
    //     }
    //     //checando de eh quadrado
    //     if((ponto1.x == x_min && ponto1.y == y_min) && (ponto2.x == x_min && ponto2.y == y_max) && (ponto3.x == x_max && ponto3.y == y_max) && (ponto4.x == x_max && ponto4.y == y_min)){
    //         if((p.x <= x_max && p.x >= x_min) && (p.y >= y_min && p.y <= y_max)){
    //             return 1;
    //         } else if((p.x < x_min && p.y < y_min) || (p.x > x_max && p.y > y_max) || (p.x > x_max && p.y < y_min) || (p.x < x_min && p.y > y_max) ||(p.x == x_min && p.y < y_min)||(p.x == x_max && p.y < y_min)||(p.x == x_min && p.y > y_max)||(p.x == x_max && p.y > y_max)||(p.y == y_max && p.x < x_min)||(p.y == y_min && p.x < x_min)||(p.y == y_max && p.x > x_max)||(p.y == y_min && p.x > x_max)||(p.x < x_max && p.x > x_min && p.y < y_min)){
    //             return 0;
    //         }
    //     } else{
    //         if(p.x < x_min && p.y < y_min ||
    //          (p.x == ponto4.x && p.y > y_max) ||
    //          (p.x == ponto1.x && p.x == x_min && p.y == ponto4.y && p.y == y_max) ||
    //          (p.y == ponto4.y && p.y == y_max && p.x < x_min) ||
    //          (p.x == ponto1.x && p.x == x_min && p.y == ponto2.y && p.x < ponto2.x) ||
    //          (p.y == ponto2.y && p.y == y_min && p.x < x_min && p.x < ponto1.x && p.x < ponto2.x)){
    //             return 0;
    //         } else if((p.x == ponto3.x && p.y == ponto3.y) || (p.x == ponto4.x && p.y == ponto4.y) || (p.x > x_min && p.x < x_max && p.y > y_min && p.x < y_max)){
    //             return 1;
    //         }
    //         // printf("%d\n", ponto3.x);
    //         // printf("%d\n", ponto3.y);
    //         // printf("losango\n");
    //     }
    // } else if(n == 3){
    //     point ponto1 = poly[0];
    //     point ponto2 = poly[1];
    //     point ponto3 = poly[2];
    //     int x_min = 100000000;
    //     int x_max = 0;
    //     int y_min = 100000000;
    //     int y_max = 0;
    //     for (int j=0; j<n; j++){
    //         if(poly[j].x > x_max){
    //             x_max = poly[j].x;
    //         } else if(poly[j].y > y_max){
    //             y_max = poly[j].y;
    //         }
    //         if(poly[j].x < x_min){
    //             x_min = poly[j].x;
    //         } else if(poly[j].y < y_min){
    //             y_min = poly[j].y;
    //         }
    //     }
    //     if(
    //         ((p.y > ponto1.y && p.y < ponto2.y && p.x > ponto1.x && p.x < ponto3.x) ||
    //         (p.x == ponto1.x && p.y == ponto1.y) ||
    //         (p.x == ponto2.x && p.y == ponto2.y) ||
    //         (p.x == ponto3.x && p.y == ponto3.y))&&
    //         !(p.x == ponto1.x && p.y == ponto2.y && p.x == x_min && p.y == y_min)
    //     ){
    //         return 1;
    //     }else if( 
    //             (p.x < x_min && p.y < y_min) ||
    //             (p.x > x_max && p.y > y_max) ||
    //             (p.x > x_max && p.y < y_min) ||
    //             (p.x < x_min && p.y > y_max) ||
    //             (p.x == x_min && p.y < y_min)||
    //             (p.x == x_max && p.y < y_min)||
    //             (p.x == x_min && p.y > y_max)||
    //             (p.x == x_max && p.y > y_max)||
    //             (p.y == y_max && p.x < x_min)||
    //             (p.y == y_min && p.x < x_min)||
    //             (p.y == y_max && p.x > x_max)||
    //             (p.y == y_min && p.x > x_max)||
    //             (p.x < x_max && p.x > x_min && p.y < y_min) ||
    //             (p.x > ponto2.x && p.y == ponto2.y) ||
    //             (p.x > x_min && p.y > y_max && p.x < ponto3.x && p.y > ponto3.y) ||
    //             (p.x < x_min && p.y == ponto1.y) ||
    //             (p.x > x_min && p.x < x_max && p.y == y_max)
    //         ){
    //         return 0;
    //     }
    // }
=======
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

    if(vertical(a,b)){
        if(p.x == a.x && (dentro_linha(p,a,b))){
            return 1;
        }
        return 0;
    } else if(horizontal(a,b)){
        if(p.y == a.y && (dentro_linha(p,a,b))){
            return 1;
        }
        return 0;
    }
>>>>>>> 65373bd78c5f1e2f54eec1179705f370838af353

    if((p.x == a.x && p.y == a.y) ||
     (p.x == b.x && p.y == b.y) ||
      (ponto_na_reta && ((p.x >= x_min && p.x <= x_max) || (p.y >= y_min && p.y <= y_max)))){
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