#include "square.h"
#include <malloc.h>
#include <stdio.h>

square* square_new(void) {
    square* self = malloc(sizeof(square));
    return self;
}

square* square_init(square* self, int x, int y, int length) {
    shape_init(&self->super, x, y);
    self->super.print = (void (*)(shape*)) & square_print;
    self->length = length;
    return self;
}

void square_delete(square* self) {
    free(self);
}

void square_print(square* self) {
    printf("square(x=%d, y=%d, length=%d)\n", self->super.x, self->super.y,
           self->length);
}
