// shape.h

#ifndef shape_H_
#define shape_H_

typedef struct shape shape;
struct shape {
    int x;
    int y;
};

shape* shape_new(void);
shape* shape_init(int x, int y);
void shape_delete(shape* self);
void shape_print(shape* self);

void shape_moveBy(shape* self, int x, int y);
void shape_moveTo(shape* self, int x, int y);

#endif
