#include <stdio.h> // 头文件, printf需要使用该头文件

#define PI1 3+2
#define PI2 (3 + 2)

int main() { // main()入口函数
    int i = 123;
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

//    String s = ""; // 注意: C语言中没有定义字符串型变量的关键字，利用字符数组来存放字符串。
    char s1[] = "abc";
    char s2[] = "abcdef";
    printf("%5s\n", s1); //  abc,右对齐, abc前面有两个空格
    printf("%5s\n", s2); // abcdef, 并没有被截掉为5个字符

    int ii;
    scanf("%d", &ii); // 注意一定要取地址 &ii
    printf("ii=:%d\n", ii);
//    fflush(stdin); // 清空标准输入缓冲区
    char cc;
    scanf("%c", &cc);
    printf("%c\n", cc);

    return 0; // 函数的返回值
}
