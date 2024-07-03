//
// Created by 51676 on 2024/7/3.
//

// 数组
// 数组作为参数 传递到函数中使用的三种方式
#include <stdio.h>

// 声明普通数据类型参数用于接收实参
void printArray(int a[], int length) {
    for (int i = 0; i < length; ++i) {
        printf("%2d", a[i]);
    }
    printf("\n");
}

// 声明指针用于接收数组地址,
// 这是因为数组作为参数传递时, 传递的就是数组的地址(即数组的首地址)
void printArray2(int *a, int length) {
    for (int i = 0; i < length; ++i) {
        printf("%d", a[i]); // 使用a[i]方式取值
    }
    printf("\n");

    int *p;
    for (int i = 0; i < length; ++i) {
        p = a;
        printf("%d", *(p+i)); // 使用*(p+i)指针方式取值
    }
    printf("\n");
}

int main() {

    int a[] = {1, 2, 3, 4, 5};

    printArray(a, 5);
    printArray2(a, 5);

    return 0;
}