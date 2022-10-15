#include <stdio.h>
#include <math.h>

typedef struct {
    double x;
    double y;
} point;

typedef struct {
    point o;
    double radius;
} circle;

void printPoint(point p) {
    printf("\nx: %lf  y: %lf", p.x, p.y);
}

double dist(point point1, point point2) {
    return sqrt((point1.x - point2.x) * (point1.x - point2.x) + (point1.y - point2.y) * (point1.y - point2.y));
}

point lineSegmentHalfPoint(point point1, point point2) {
    point point3 = {0.5 * (point1.x + point2.x), 0.5 * (point2.y + point1.y)};
    return point3;
}

// returns bool
int isPointInCircle(point p, circle c) {
    return dist(p, c.o) < c.radius;
}

int main() {
    point points[4] = {{0,   0},
                       {1.1, 4.9},
                       {-2,  0.3},
                       {1.9, 10.56}};

    // C can't work with user defined data types.
    point origo, farthestFromOrigo;
    origo.x = points[0].x;
    origo.y = points[0].y;

    farthestFromOrigo.x = points[1].x;
    farthestFromOrigo.y = points[1].y;

    circle circle1 = {points[1], 5};

    for (int i = 2; i < 4; i++) {
        if (dist(origo, points[i]) > dist(origo, farthestFromOrigo)) {
            farthestFromOrigo.x = points[i].x;
            farthestFromOrigo.y = points[i].y;
        }
    }

    if(isPointInCircle(points[2], circle1)) {
        printf("Benne van");
        return 0;
    }
    printf("Nincs benne");
    return 0;
}
