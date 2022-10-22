// square.h

#ifndef square_H_
#define square_H_

#include "shape.h"

typedef struct square square;
struct square {
    shape super;
    int length;
};

square* square_new(void);
square* square_init(int x, int y, int length);
void square_delete(square* self);
void square_print(square* self);

#endif
