#include <stdio.h>
#include "shape.h"
#include "square.h"

void test_shape() {
    shape* test = shape_init(5, 5);  // 建立 shape 对象
    shape_print(test);               // 打印出 shape(x=5, y=5)
    shape_moveBy(test, 1, -2);       // 向右移动 1，向下移动 2
    shape_print(test);               // 打印出 shape(x=6, y=3)
    shape_moveTo(test, 2, 2);        // 移到 x=2, y=2 的位置
    shape_print(test);               // 打印出 shape(x=2, y=2)
    shape_delete(test);              // 删除/释放对象
}

void test_square() {
    square* test = square_init(5, 5, 10);  // 建立 square 对象
    shape_print((shape*)test);             // 打印出 shape(x=5, y=5)
    square_print(test);                 // 打印出 square(x=5, y=5, length=10)
    shape_moveBy((shape*)test, 2, -3);  // 向右移动 2，向下移动 3
    square_print(test);                 // 打印出 square(x=7, y=2, length=10)
    square_free(test);
}

int main() {
    printf("====== shape test ======\n");
    test_shape();
    printf("====== square test ======\n");
    test_square();
    printf("====== end ======\n");
}
