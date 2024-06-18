#include <stdio.h> // 头文件, printf需要使用该头文件

#define PI1 3+2
#define PI2 (3 + 2)

int main() { // main()入口函数
    int i = 13;
    printf("Hello, World!\n"); // 函数内的代码内容

    printf("%d\n", PI1 * 2); // 7, not 10, 注意这里的结果
    printf("%d\n", PI2 * 2); // 10

    printf("%llu\n", sizeof(i));

    float f = 1.1f;
    printf("%llu\n", sizeof(f));

    float f2 = 1e1;

//    char c1 = ''; // 编译不通过
    char c2 = ' '; // 编译通过

    char c3 = 'a';
    printf("%c\n", c3); // a
    printf("%d\n", c3); // 97
    char c4 = 97;
    printf("%c\n", c4); // a
    printf("%d\n", c4); // 97


    return 0; // 函数的返回值
}
