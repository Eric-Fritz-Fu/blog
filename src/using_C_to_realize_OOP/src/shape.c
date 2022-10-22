#include "shape.h"
#include <malloc.h>
#include <stdio.h>

shape* shape_new(void) {
    shape* self = malloc(sizeof(shape));
    return self;
}

shape* shape_init(int x, int y) {
    shape* self = shape_new();
    self->x = x;
    self->y = y;
    return self;
}

void shape_delete(shape* self) {
    free(self);
}

void shape_moveBy(shape* self, int x, int y) {
    self->x += x;
    self->y += y;
}

void shape_moveTo(shape* self, int x, int y) {
    self->x = x;
    self->y = y;
}

void shape_print(shape* self) {
    printf("shape(x=%d, y=%d)\n", self->x, self->y);
}
