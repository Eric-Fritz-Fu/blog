// shape.h

#ifndef shape_H_
#define shape_H_

typedef struct shape shape;
struct shape {
    int x;
    int y;
};

shape* shape_new(void);
shape* shape_new(int x, int y);

int shape_moveBy(int x, int y);
int shape_moveTo(int x, int y);
void shape_print(void);

#endif