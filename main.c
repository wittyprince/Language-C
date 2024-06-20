#include <stdio.h> // 头文件, printf需要使用该头文件
#include "string.h"
#include "stdlib.h"

#define PI1 3+2
#define PI2 (3 + 2)

/**
 * 数组传递的是数组的地址(即数组的首地址)
 * 所以在该函数中对数组进行修改会影响原数组
 * 另外，数组的长度是传递不过去的，需要另行定义变量来传递，如 int len
 */
void print(int a[], int len) {
    for (int j = 0; j < len; ++j) {
        printf("%d\n", a[j]);
    }
    a[3] = 30;
    printf("\n");
}

/**
 * 打印字符数组
 */
void printCharArray(char c[]) {
    int i = 0;
    while (c[i]) {
        printf("%c", c[i]);
        i++;
    }
    printf("\n");
}

void change(int j) {
    j = 6;
}

void changeWithPointer(int *k) {
    *k = 7;
}

void referenceOrValueTransfer() {
    int i = 5;
    printf("%d\n", i);
    // C 语言中，函数的调用是值传递，实参赋值给形参。即把i赋值给j。所以对j进行改变是不会影响i的。
    change(i);
    printf("%d\n", i);
    changeWithPointer(&i); // 此时仍然是值传递，只不过这里的值是地址值
    printf("%d\n", i);


    // 上面调用change()与下面更改b的值原理类似
    int a = 10;
    int b = a;
    printf("before a =%d\n", a);
    b = 5;
    printf("after a = %d\n", a);
}

// 数组名作为实参传递给子函数时，是弱化为指针的
void traverseArray(char *d) {
    *d = 'H'; // 指针法,
    d[1] = 'E'; // 下标法
    *(d + 2) = 'L';
}

char* print_stack() {
    // 该方式分配的空间在stack中，print_stack()方法调用完后，stack中的空间可能会被其他函数使用，造成数据污染
    char c[] = "how are you ?"; // 该方式 在main函数中的值打印时会乱码 0鷦a?
//    char *c = "how old are you ?"; // 该方式不会乱码，为什么？
    puts(c);
    char *p = c;
    return p;
}

char* print_malloc() {
    char *p;
    // 该方式分配的空间在heap中, heap空间中的空间如果不手动free, 其会伴随进程一直存在
    p = (char *)malloc(100);
    strcpy(p, "are you ok?");
    puts(p);
    return p;
}

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

/**
 * 数组初始化(赋值)
 */
void arrayAssign() {
    int a[10] = {1, 2, 3, 4, 5};

    int b[10]={0};
//    b[10] = {1, 2, 3}; // 不能先定义数组变量，再对数据变量进行赋值，此句编译报错
    b[1] = 1; // 其实是可以使用该种方式对数组中的每一个位置进行赋值
}

/**
 * 数组越界
 */
void riskOfIndexOutOfBound() {
    int a[5] = {1, 3, 5, 7, 9};
    int j = 20;
    int i = 10;
    int k = 30;
    a[5] = 6; // 越界访问
    a[6] = 11; // 越界访问，会造成数据异常，这是因为会覆盖内存地址造成的
    printf("i=%d\n", i); // i=11
    printf("k=%d\n", k); // k=6
    printf("a[5]=%d\n", a[5]); // a[5]=6
    printf("a[6]=%d\n", a[6]); // a[6]=11
}

/**
 * 字符串翻转
 * // how are you boy and girl
 */
void charReverse() {
    char c[1000];
    gets(c);
    char d[1000] = {'\0'}; // 这里赋初始值是为了防止在启动程序时C语言中的随机分配值造成的数据污染
    int i = 0;
    int j = strlen(c);
    for (; i < strlen(c); ++i, j--) {
        d[j - 1] = c[i];
    }
//    puts(d);
    int result = strcmp(c, d);
    if (result < 0) {
        printf("%d\n", -1);
    } else if (result > 0) {
        printf("%d\n", 1);
    } else {
        printf("%d\n", 0);
    }
}

/**
 * & 取地址, 又叫引用
 * * 取值, 又叫解引用
 */
void getReferenceAndGetValue() {
    int i = 10;
    printf("%d\n", i); // 10, 取变量i的值           直接访问
    printf("%d\n", &i); // 6422028, 取变量i的地址
    int *int_pointer = &i;
    printf("%d\n", *int_pointer); // 10,          间接访问

    int *i_p; // 定义一个指针类型的变量
    i_p = &i; // 把变量i的地址赋值给i_p
    printf("%d\n", *i_p); // 10, *i_p *取值运算符, 取i_p地址对应的值
    printf("%d", &*i_p); // 6422028, 相当于取地址
}

/**
* 使用指针来遍历数组
*/
void traverseArrayByPointer() {
    int a[5] = {1, 2, 3, 4, 5}; // 初始化一个整型数组
    for (int i = 0; i < 5; ++i) { // 遍历打印
        printf("%3d", a[i]);
    }
    printf("\n================\n");

    int *p; // 声明一个指针
    p = a; // 把整型数组a赋值给p, 这是因为 数组变量a中存放的是该数组的起始地址。所以可以把地址赋值给指针型变量p
    p + 1; // 是p的地址+sizeof(int) (即0x616df0 + 4), 而不是p的地址+1(即0x616df0+1)
    for (int i = 0; i < 5; ++i) {
        printf("%3d", *(p+i));
    }
    printf("\n================\n");

    p = &a[4]; // p 指向最后一个元素，进行逆序输出
    for (int i = 0; i < 5; ++i) {
        printf("%3d", *(p - i));
    }
}

/**
 * malloc
 * free
 */
void mallocAndFree() {
    int size;
    char *p; // void * 类型的指针不能偏移，所以不会定义无类型指针。
    scanf("%d", &size); // 输入要申请的空间的大小
    // malloc返回的void*代表无类型指针。
    p = (char *)malloc(size); // 使用malloc动态申请堆空间
    strcpy(p, "how are you ?");
    puts(p);
    // 1. free时必须使用malloc申请时返回的指针值，不能进行任何偏移，即不能使用free(p+1) 或 free(p-1)等等。
    // 2. 使用malloc申请的空间，使用完毕后，必须手动free
    free(p);
    printf("free success");
}

void mallocForString() {
    int i  = 0;
    scanf("%d", &i);
    char *p = (char *)malloc(i);
    char c;
    scanf("%c",&c); // 注意在scanf和gets中间使用scanf("%c",&c)去除换行
    gets(p); // 如果不通过上面的scanf去除掉\n换行符, 那么gets不会被卡住
//    fgets(p, i, stdin);
    puts(p);
}