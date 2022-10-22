# 用 C 语言实现面向对象

## 引言

尽管我们通常会说 C 语言是一门面向过程的语言，
但这并不意味着没法使用面向对象的思想。
本质上，语言只是一种表达方式。
而支持面向对象，只是是在设计编程语言时一个特定的功能，使其可以更好地表达面向对象的的程序。
通过使用结构体、函数指针，C 语言也可以实现面向对象思想。

## 实现

面向对象编程的三大特点是封装、继承、多态，三者缺一不可，等会我们将会实现它们。

这里，我们将尝试创建一个名为 `Shape` 的类来表示图形。

### 封装

封装就是把数据和方法封装到一起。
很容易想到，我们可以使用结构体表示对象，用函数来表示方法。

每个结构体有用多个字段，代表了对象的属性。
在下面的例子里，我们定义了 `x` 和 `y` 两个字段，分别表示形状位置的横、纵坐标。

方法函数的第一个参数在使用时手动传入，相当于方法中 `this` 的值。
这里我们定义了 `new`，`init`，`delete`，`print`，`mvoeTo`，`moveBy` 六个方法。
其中 `init` 和 `new` 方法是静态方法。
`init` 方法调用 `new` 方法来建立对象，然后再初始化。
我通常使用 `类名_方法名` 的形式来命名方法，你也可以使用你自己喜欢的命名方式。

所以，头文件应该长这样：

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

实现请移步：[shape 类源码链接](./src/shape.c)

客户端代码：

```c
shape* test = shape_init(5, 5);  // 建立对象
shape_print(test);               // 打印出 shape(x=5, y=5)
shape_moveBy(test, 1, -2);       // 向右移动 1，向下移动 2
shape_print(test);               // 打印出 shape(x=6, y=3)
shape_moveTo(test, 2, 2);        // 移到 x=2, y=2 的位置
shape_print(test);               // 打印出 shape(x=2, y=2)
shape_delete(test);              // 删除/释放对象
```

### 继承

此时的 `shape` 并没有什么实际意义，让我们来实现一个正方形。
正方形是图形的一种，自然我们就想到了面向对象中的继承。

这里我先给出源码，看看你能不能自己想明白为什么。
