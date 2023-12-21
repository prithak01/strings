#include <stdio.h>
#include <stdlib.h>
typedef struct Point
{
    double  x,y;
}Point;

typedef struct Point Point;
int main (int argc, char *argv[])
{
    Point p;
    p.x = 0.24;
    p.y = 0.78;
    printf("%lf and %lf", p.x, p.y);

    return 0;
}