// Example
#ifndef RECTANGLE_H
#define RECTANGLE_H
#include <stdio.h>

struct My_rectangle {
    int x;
    int y;
    int w;
    int h;
};


void print_rectangle(struct My_rectangle* rect);

#endif 