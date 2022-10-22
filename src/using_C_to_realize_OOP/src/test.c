#include "shape.h"

int main() {
    shape* test = shape_init(5, 5);  // 建立对象
    shape_print(test);               // 打印出 shape(x=5, y=5)
    shape_moveBy(test, 1, -2);       // 向右移动 1，向下移动 2
    shape_print(test);               // 打印出 shape(x=6, y=3)
    shape_moveTo(test, 2, 2);        // 移到 x=2, y=2 的位置
    shape_print(test);               // 打印出 shape(x=2, y=2)
    shape_delete(test);              // 删除/释放对象
}
