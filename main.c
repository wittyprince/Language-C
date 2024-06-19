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

/**
 * 闰年
 */
void leap() {
    int year = 0;
    scanf("%d", &year);
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
        printf("%s", "yes");
    } else {
        printf("%s", "no");
    }
}

/**
 * 判断一个数是否是对称数
 * 输入一个整型数，判断是否是对称数，如果是，输出yes，否则输出no，不用考虑这个整型数过大，int类型存不下，不用考虑负值；
 * 例如 12321是对称数，输出yes，124421是对称数，输出yes，1231不是对称数，输出no
 */
void symmetry() {
    int a = 0, b = 0;
    scanf("%d", &a);
    int copyOfA = a;
    while (copyOfA) {
        b = b * 10 + copyOfA % 10;
        copyOfA = copyOfA / 10;
    }
    if (b == a) {
        printf("yes");
    } else {
        printf("no");
    }
}

/**
 * 阶乘
 */
void factorial() {
    int a = 0;
    scanf("%d", &a);
    int result = 1;
    while (a) {
        result = result * a;
        a = a -1;
    }
    printf("%d", result);
}

/**
 * 某人想将手中的一张面值100元的人民币换成10元、5元、2元和1元面值的票子。要求换正好40张，且每种票子至少一张。问：有几种换法？
 */
void exchangeSomeChange() {
    int sum = 100 - 10 - 5 - 2 - 1; // 剩余面值82
    int total = 36; // 剩余张数
    int total10 = 0; // 10元
    int total5 = 0; // 5元
    int total2 = 0; // 2元
    int total1 = 0; // 1元

    int sum10 = 0;
    int sum5 = 0;
    int sum2 = 0;
    int sum1 = 0;
    int exchange = 0;
    for (total10 = 0; total10 < 100 / 10; ++total10) {
        sum10 = total10 * 10;
        for (total5 = 0; total5 < 100 / 5; ++total5) {
            sum5 = total5 * 5;
            for (total2 = 0; total2 < 100 / 2; ++total2) {
                sum2 = total2 * 2;

                for (total1 = 0; total1 < 100; ++total1) {
                    sum1 = total1 * 1;

                    if(sum10 + sum5 + sum2 + sum1 == 82 && total10 + total5 + total2 + total1 == 36) {
//                        printf("total10=%d\n", total10 + 1);
//                        printf("total5=%d\n", total5 + 1);
//                        printf("total2=%d\n", total2 + 1);
//                        printf("total1=%d\n", total1 + 1);
                        exchange++;
//                        printf("exchange:%d\n", exchange);
//                        printf("===================\n");
                        break;
                    }

                }
//                if(sum10 + sum5 + sum2 + sum1 == 82 && total10 + total5 + total2 + total1 == 36) {
//                    break;
//                }
            }
//            if(sum10 + sum5 + sum2 + sum1 == 82 && total10 + total5 + total2 + total1 == 36) {
//                break;
//            }
        }
//        if(sum10 + sum5 + sum2 + sum1 == 82 && total10 + total5 + total2 + total1 == 36) {
//            break;
//        }
    }

//    printf("total10=%d\n", total10 + 1);
//    printf("total5=%d\n", total5 + 1);
//    printf("total2=%d\n", total2 + 1);
//    printf("total1=%d\n", total1 + 1);
    printf("%d\n", exchange);
}