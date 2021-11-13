#include "sgi.h"
#include <math.h>

int main(int argc, char *args[]) {
    int i, j;
    RGBA col;
    float r,g,b;
    if (init_sgi(800, 600, "第二章") == false) {
        return 0;
    };
    for (j = 0; j < sgi.h; j++) {
        for (i = 0; i < sgi.w; i++) {
            r=0.5 + 0.5 * cosf(.2+ (float)i/(float)sgi.w + (1.0 - (float)j/(float)sgi.h )+0.0);
            g=0.5 + 0.5 * cosf(.3+ (float)i/(float)sgi.w + (1.0 - (float)j/(float)sgi.h )+2.0);
            b=0.5 + 0.5 * cosf(.4+ (float)i/(float)sgi.w + (1.0 - (float)j/(float)sgi.h )+4.0);
            col.r = roundf(r*255);
            col.g = roundf(g*255);
            col.b = roundf(b*255);
            col.a = 255;
            sgi_Point(i, j, col);
        }
    };
    sgi_Line(0, 0, 500, 500, RGB_Magenta);
    sgi_Circle(400, 300, 100, RGB_Purple);
    sgi_Disk(400, 300, 50, RGB_Green);
    sgi_Rect(50,50,300,200,RGB_Teal);
    sgi_Mode_Blend();
	col.r = 128;
	col.g = 255;
	col.b = 100;
	col.a = 88;
    sgi_FillRect(250,250,300,200,col);
    sgi_update();
    while (!sgi_done(true))
        ;
    fini_sgi();
    return 0;
}
