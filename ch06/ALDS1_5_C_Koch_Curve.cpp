// 6.3
// コッホ曲線

#include <stdio.h>
#include <math.h>

struct Point
{
    double x,y;
};

void koch(int d, Point a, Point b)
{
    if (d == 0) return;
    Point s, t, u;
    double angle = M_PI * 60 / 180;

    s.x = (2 * a.x + 1 * b.x) / 3;
    s.y = (2 * a.y + 1 * b.y) / 3;
    t.x = (1 * a.x + 2 * b.x) / 3;
    t.y = (1 * a.y + 2 * b.y) / 3;
    u.x = (t.x - s.x) * cos(angle) - (t.y - s.y) * sin(angle) + s.x;
    u.y = (t.x - s.x) * sin(angle) + (t.y - s.y) * cos(angle) + s.y;

    koch(d-1, a, s);
    printf("%.8f %.8f\n", s.x, s.y);
    koch(d-1, s, u);
    printf("%.8f %.8f\n", u.x, u.y);
    koch(d-1, u, t);
    printf("%.8f %.8f\n", t.x, t.y);
    koch(d-1, t, b);
}

int main()
{
    int n;
    Point a, b;
    scanf("%d", &n);

    a.x = 0;
    a.y = 0;
    b.x = 100;
    b.y = 0;

    printf("%.8f %.8f\n", a.x, a.y);
    koch(n, a, b);
    printf("%.8f %.8f\n", b.x, b.y);
    return 0;
}
