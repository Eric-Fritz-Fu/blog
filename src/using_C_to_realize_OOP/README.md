# 用 C 语言实现面向对象

## 引言

尽管我们通常会说 C 语言是一门面向过程的语言，但这并不意味着没法使用面向对象的思想。本质上，语言只是一种表达方式。而支持面向对象，只是是在设计编程语言时一个特定的功能，使其可以更好地表达面向对象的的程序。通过使用结构体、函数指针，C 语言也可以实现面向对象。

## 实现

面向对象编程的三大特点是封装、继承、多态，三者缺一不可，等会我们将会一一实现它们。

### 封装

首先，我们来尝试创建一个名为 `Shape` 的类来表示图形。

很容易想到，我们可以使用结构体表示对象，用函数来表示方法。

```c
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
```

结构体天生就是标准的对象。在上面的例子里，我们定义了 `x` 和 `y` 两个字段，分别表示形状位置的横、纵坐标。

形如 `类名_方法名` 的函数是方法，你也可以使用你自己喜欢的命名方式。我们定义了 `new`，`init`，`delete`，`print`，`mvoeTo`，`moveBy` 六个方法。其中 `new` 方法是静态方法，没有 `self` 参数。其他方法的第一个参数 `self` 在使用时手动传入，表示调用的对象，相当于大多数语言中 `this` 的值。`init` 方法用来为对象申请内存，`new` 用来初始化对象。

使用时：

```c
shape* test = shape_new();  // 建立 shape 对象
shape_init(test, 5, 5);     // 初始化对象
shape_print(test);          // 打印出 shape(x=5, y=5)
shape_moveBy(test, 1, -2);  // 向右移动 1，向下移动 2
shape_print(test);          // 打印出 shape(x=6, y=3)
shape_moveTo(test, 2, 2);   // 移到 x=2, y=2 的位置
shape_print(test);          // 打印出 shape(x=2, y=2)
shape_delete(test);         // 删除/释放对象
```

### 继承

此时的 `shape` 并没有什么实际作用，下面让我们来实现一个名为 `square` 的类来表示一个正方形。正方形是图形的一种，自然我们就想到了面向对象中的继承。

C 语言中结构体没用继承，但我们可以使用组合来代替继承，并使用指针寻址来实现和继承一样的效果。

```c
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
square* square_init(int x, int y);
void square_delete(shape* self);
void square_print(shape* self);

#endif
```

使用时：

```c
square* test = square_new();        // 建立 square 对象
square_init(test, 5, 5, 10);        // s初始化对象
shape_print((shape*)test);          // 打印出 shape(x=5, y=5)
square_print(test);                 // 打印出 square(x=5, y=5, length=10)
shape_moveBy((shape*)test, 2, -3);  // 向右移动 2，向下移动 3
square_print(test);                 // 打印出 square(x=7, y=2, length=10)
square_delete(test);
```

如果你对 C 语言有一些研究，你应该知道上面的结构体 `square` 在内存中，是按照下图绿色部分存储的。

![内存示意图](./static/pic01.svg)

当我们把 `square *` 当作 `shape *` 访问其中的字段时，就相当于访问 `square.super`，因为从图中可看出 `square`，`square.shape` 的地址是相同的。要达到这种效果，我们必须将 `super` 放在结构体的第一位。

### 多态

如果你运行了上面的代码，你就会发现一个问题。`square` 类和 `shape` 类都有一个 `print` 方法，更糟糕的是当它们对 `test` 调用时，会给出不同的结果。实际上，我们通常会把 `square` 当做 `shape` 传输，在这过程中我们并不知道 `shape` 的类型，自然也无法找到 `print` 方法，没有实现多态。

要实现多态，我们必须将对象的方法当做它的属性传递下去，这样当我们不知道类型时，依旧可以找到对应的函数。此时此刻，你一定想到了我们可以使用函数指针。

我们在 `shape` 定义的前面加上一个函数指针字段，指向 `print` 方法。

```c
// shape.h

struct shape {
    void (*print)(shape* self);
    int x;
    int y;
};
```

在初始化对象时，初始化这个函数指针，使其指向它的 `print` 方法。

我们还可以定义一个 `adprint` 方法用来访问对象的 `print` 方法并执行：

```c
void shape_adprint(shape* self) {
    self->print(self);
}
```

使用时：

```c
square* test = square_new();  // 建立 square 对象
square_init(test, 5, 5, 10);  // 初始化对象
shape_print((shape*)test);    // 打印出 shape(x=5, y=5)
square_print(test);           // 打印出 square(x=5, y=5, length=10)
shape_adprint((shape*)test);  // 打印出 square(x=5, y=5, length=10)

shape* test2 = shape_new();       // 建立 shape 对象
shape_init((shape*)test2, 5, 5);  // 初始化对象
shape_print((shape*)test2);       // 打印出 shape(x=5, y=5)
shape_adprint((shape*)test2);     // 打印出 shape(x=5, y=5)
```

## 小结

C 作为一种灵活的语言，可以通过 `struct` 来模拟面向对象。事实上在 C 标准库中，就用到了这样的方法。例如 `FILE` 结构体和 `fxxx` 函数，就用到了面向对象的思想。
