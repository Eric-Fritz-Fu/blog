// shape.h

#ifndef shape_H_
#define shape_H_

typedef struct shape shape;
struct shape {
    void (*print)(shape* self);
    int x;
    int y;
};

shape* shape_new(void);
shape* shape_init(shape* self, int x, int y);
void shape_delete(shape* self);

void shape_moveBy(shape* self, int x, int y);
void shape_moveTo(shape* self, int x, int y);
void shape_print(shape* self);
void shape_adprint(shape* self);

#endif
