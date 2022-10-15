#include <cstdio>
#include <cmath>

int main(){


    int a, b, c; scanf("%d %d %d\n", &a, &b, &c);
    double first = (-b - sqrt(b * b - 4 * a * c)) / 2 / a;
    double second = (-b + sqrt(b * b - 4 * a * c)) / 2 / a;

    if(b * b == 4 * a * c){printf("%.5lf\n", first);}
    else{printf("%.5lf %.5lf\n", first, second);}

    return 0;
}
