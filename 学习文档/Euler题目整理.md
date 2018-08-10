# Euler题目整理

## Euler1

## **3的倍数和5的倍数**

如果我们列出10以内所有3或5的倍数，我们将得到3、5、6和9，这些数的和是23。

求1000以内所有3或5的倍数的和。

由题意可知，虽然可以使用暴力方法求出１０００以内所有三和五的倍数后减去１５的倍数

但是可以采用等差数列求和公式进行优化

```CQL
/*************************************************************************
	> File Name: oula1.c
	> Author: 
	> Mail: 
	> Created Time: 2018年08月03日 星期五 10时58分43秒
 ************************************************************************/

#include<stdio.h>
int main() {
    int sum1 , sum2, sum ;
    sum1 = (3 + 999) * (999 / 3) / 2;
    sum2 = (5 + 995) * (999 / 5) / 2;
    sum = (15 + 999 / 15 * 15) * (999 / 15) / 2;
    printf("%d\n", sum1 + sum2 - sum);
    return 0;
}
```

## Euler2

## **偶斐波那契数**

斐波那契数列中的每一项都是前两项的和。由1和2开始生成的斐波那契数列前10项为：

1, 2, 3, 5, 8, 13, 21, 34, 55, 89, …

考虑该斐波那契数列中不超过四百万的项，求其中为偶数的项之和。

模拟：

```c
/*************************************************************************
	> File Name: oula2.c
	> Author: 
	> Mail: 
	> Created Time: 2018年08月03日 星期五 11时02分49秒
 ************************************************************************/

#include<stdio.h>
int main() {
    int a = 0, b = 1, sum = 0;
    while(sum < 4000000) {
        b = a + b;
        a = b - a;
        if(b % 2 == 0) sum += b;
    }
    printf("%d\n", sum);
    return 0;
}
```

## Euler3最大质因数

13195的所有质因数为5、7、13和29。

600851475143最大的质因数是多少？

 ```c
/*************************************************************************
	> File Name: oula3.c
	> Author: 
	> Mail: 
	> Created Time: 2018年08月03日 星期五 11时08分39秒
 ************************************************************************/
#include<stdio.h>
#include<inttypes.h>
#define MAX_N 600851475143 
int main() {
    int64_t ans = 0, num = MAX_N;
    for(int i = 2; i * i < num; i++) {
        if(num % i == 0) ans = i;
        while(num % i == 0) num /= i;//除干净质因子
    }
    if(num != 1) ans = num;
    printf("%"PRId64"\n", ans);
    return 0;
}
 ```

## Euler4回文数

回文数就是从前往后和从后往前读都一样的数。由两个2位数相乘得到的最大回文乘积是 9009 = 91 × 99。

找出由两个3位数相乘得到的最大回文乘积。

由题意可知，我们需要验证一个数是否为回文数

```cassandra
/*************************************************************************
	> File Name: oula4.c
	> Author: 
	> Mail: 
	> Created Time: 2018年08月03日 星期五 11时19分42秒
 ************************************************************************/

#include<stdio.h>
int huiwen(int x) {
    int cmp = x,  sum = 0;
    while(x) {
        sum = sum * 10 + x % 10;
        x /= 10;
    }
    return cmp == sum;
}
int main() {
    int ans = 0, tmep = 0;
    for(int i = 100; i < 1000; i++) {
        for(int j = 100; j < 1000; j++) {
            if(huiwen(i * j) && i * j > ans) {
                ans = i * j;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
```

## Euler6平方和

## **平方的和与和的平方之差**

前十个自然数的平方的和是

12 + 22 + … + 102 = 385

前十个自然数的和的平方是

(1 + 2 + … + 10)2 = 552 = 3025

因此前十个自然数的平方的和与和的平方之差是 3025 − 385 = 2640。

求前一百个自然数的平方的和与和的平方之差。

```c
/*************************************************************************
	> File Name: oula6.c
	> Author: 
	> Mail: 
	> Created Time: 2018年08月03日 星期五 12时02分26秒
 ************************************************************************/

#include<stdio.h>
int main() {
    int sum1 = 100 * 100 * 100;
    int sum2 = 3 * (1 + 100) * 100 / 2;
    int sum = sum1 - 1 + sum2 - 100;
    int sum3 = 5050;
    printf("%d\n", sum3 * sum3 - sum / 3);
    return 0;
}
```

## Euler28螺旋矩阵

**螺旋数阵对角线**

从1开始，按顺时针顺序向右铺开的5 × 5螺旋数阵如下所示：

**21** 22 23 24 **25**
20  **7**  8  **9** 10
19  6  **1**  2 11
18  **5**  4  **3** 12
**17** 16 15 14 **13**

可以验证，该数阵对角线上的数之和是101。

以同样方式构成的1001 × 1001螺旋数阵对角线上的数之和是多少？

每一圈右上角值为n * n,上个对角线值为n * n - n + 1,每一圈的增量为4 * n * n - 6 * n + 6

```c
/*************************************************************************
	> File Name: oula28.c
	> Author: 
	> Mail: 
	> Created Time: 2018年08月03日 星期五 12时14分57秒
 ************************************************************************/

#include<stdio.h>
int main() {
    int ans = 1;
    for(int i = 3; i <= 1001; i += 2) {
        ans += 4 * i * i - 6 * i + 6;
    }
    printf("%d\n", ans);
}
```

## Euler30分解整数上界估算

**各位数字的五次幂**

令人惊讶的是，只有三个数可以写成它们各位数字的四次幂之和：

> 1634 = 14 + 64 + 34 + 44
> 8208 = 84 + 24 + 04 + 84
> 9474 = 94 + 44 + 74 + 44

由于1 = 14不是一个和，所以这里并没有把它包括进去。

这些数的和是1634 + 8208 + 9474 = 19316。

找出所有可以写成它们各位数字的五次幂之和的数，并求这些数的和。

上界估算n(x) <= 9(5) * x,估算得max = 9 ^5 *7 = 413343

```c
/*************************************************************************
	> File Name: oula30.c
	> Author: 
	> Mail: 
	> Created Time: 2018年08月03日 星期五 12时36分11秒
 ************************************************************************/

#include<stdio.h>
#include<inttypes.h>
#include<math.h>
#define MAX_N 413343
int judg(int x) {
    int cmp = x, sum = 0;
    while(x) {
        sum += pow(x % 10, 5);
        x /= 10;
    }
    return sum == cmp;
}
int main() {
    int64_t ans = 0;
    for(int i = 2; i < MAX_N; i++) {
        if(judg(i)) ans += i;
    }
    printf("%"PRId64"\n", ans);
}
```

## Euler34上界估算

145是个有趣的数，因为1! + 4! + 5! = 1 + 24 + 120 = 145。

找出所有各位数字的阶乘和等于其本身的数，并求它们的和。

注意：因为1! = 1和2! = 2不是和的形式，所以它们并不在讨论范围内。

```c
/*************************************************************************
	> File Name: oula32.c
	> Author: 
	> Mail: 
	> Created Time: 2018年08月03日 星期五 12时36分11秒
 ************************************************************************/

#include<stdio.h>
#include<inttypes.h>
#include<math.h>
#define MAX_N 2903040
int jiecheng[10] = {1};
void init() {
    for(int i = 1; i < 10; i++) jiecheng[i] = jiecheng[i - 1] * i;
}//初始化阶乘
int judg(int x) {
    int cmp = x, sum = 0;
    while(x) {
        sum += jiecheng[x % 10];
        x /= 10;
    }
    return sum == cmp;
}
int main() {
    init();
    int64_t ans = 0;
    for(int i = 3; i < MAX_N; i++) {
        if(judg(i)) ans += i;
    }
    printf("%"PRId64"\n", ans);
}
```

## Euler36十转任意进制

**双进制回文数**

十进制数585 = 10010010012（二进制表示），因此它在这两种进制下都是回文数。

找出所有小于一百万，且在十进制和二进制下均回文的数，并求它们的和。

（请注意，无论在哪种进制下，回文数均不考虑前导零。）

```c
/*************************************************************************
	> File Name: oula36.c
	> Author: 
	> Mail: 
	> Created Time: 2018年08月03日 星期五 12时52分32秒
 ************************************************************************/

#include<stdio.h>
#include<inttypes.h>
#define MAX_N 1000000
int judg(int x, int y) {
    int cmp = x, sum = 0;
    while(x) {
        sum = sum * y + x % y;//十进制转任意进制
        x /= y;
    }
    return cmp == sum;//系统自动比较
}
int main() {
    int ans = 0;
    for(int i = 1; i < MAX_N; i++) {
        if(judg(i, 2) && judg(i, 10)) ans += i;
    }
    printf("%"PRId64"\n", ans);
    return 0;
}
```

## Euler5gcd

2520是最小的能够被1到10整除的数。

最小的能够被1到20整除的正数是多少？

首先看该数是否已在ans中如果不在求最大公约数后，i× ans/gcd(i,ans)

```c
/*************************************************************************
	> File Name: oula5.c
	> Author: 
	> Mail: 
	> Created Time: 2018年08月03日 星期五 13时08分50秒
 ************************************************************************/

#include<stdio.h>
int gcd(int a, int b) {
    if(b > a) return gcd (b, a);
    return b == 0 ? a : gcd(b, a % b);
}
int main() {
    int ans = 1;
    for(int i = 1; i < 21; i++) {
        if(ans % i == 0) continue;
        ans = i * ans / gcd(ans,i);
    }
    printf("%d\n", ans);
    return 0;
}
```

## Euler7线性筛

```c
/*************************************************************************
	> File Name: oula7.c
	> Author: 
	> Mail: 
	> Created Time: 2018年08月03日 星期五 13时27分27秒
 ************************************************************************/

#include<stdio.h>
#define MAX_N 200000
int prime[MAX_N] = {0};
void init() {
    for(int i = 2; i < MAX_N; i++) {
        if(!prime[i]) prime[++prime[0]] = i;
        for(int j = 1; j <= prime[0] && prime[j] * i < MAX_N; j++) {
            prime[i * prime[j]] = 1;
            if(i % prime[j] == 0) break;
        }
    }
}
int main() {
    init();
    printf("%d\n", prime[10001]);
    return 0;
}
```

## Euler8滑动窗口

## **连续数字最大乘积**

在下面这个1000位正整数中，连续4个数字的最大乘积是 9 × 9 × 8 × 9 = 5832。

73167176531330624919225119674426574742355349194934
96983520312774506326239578318016984801869478851843
85861560789112949495459501737958331952853208805511
12540698747158523863050715693290963295227443043557
66896648950445244523161731856403098711121722383113
62229893423380308135336276614282806444486645238749
30358907296290491560440772390713810515859307960866
70172427121883998797908792274921901699720888093776
65727333001053367881220235421809751254540594752243
52584907711670556013604839586446706324415722155397
53697817977846174064955149290862569321978468622482
83972241375657056057490261407972968652414535100474
82166370484403199890008895243450658541227588666881
16427171479924442928230863465674813919123162824586
17866458359124566529476545682848912883142607690042
24219022671055626321111109370544217506941658960408
07198403850962455444362981230987879927244284909188
84580156166097919133875499200524063689912560717606
05886116467109405077541002256983155200055935729725
71636269561882670428252483600823257530420752963450

找出这个1000位正整数中乘积最大的连续13个数字。它们的乘积是多少？

```c
/*************************************************************************
	> File Name: oula8.c
	> Author: 
	> Mail: 
	> Created Time: 2018年08月03日 星期五 14时49分49秒
 ************************************************************************/

#include<stdio.h>
#include<inttypes.h>
#include<string.h>
int main() {
    char a[1005] = {0};
    char temp[1000] = {0};
    while(scanf("%s", temp) != EOF) {
        strcat(a, temp);
    }//数据录入
    int64_t ans = 1, sum = 0, zero = 0;
    for(int i = 0; i < 1000; i++) {
        if(a[i] == '0') {
            zero++;
        } else {
            ans *= a[i] - '0';
        }
        if(i >= 13) {
            if(a[i - 13] == '0') {
                zero -= 1;
            } else {
                ans /= a[i - 13] - '0';
            }
        }
        if(zero == 0 && ans > sum) sum = ans;
    }
    printf("%"PRId64"\n", sum);
    return 0;
}
```

## Euler9勾股数性质

根据素勾股数第二和第四性质

```c
/*************************************************************************
	> File Name: oula9.c
	> Author: 
	> Mail: 
	> Created Time: 2018年08月05日 星期日 14时06分24秒
 ************************************************************************/

#include<stdio.h>
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}
int main() {
    for(int i = 1; i < 40; i++) {
        for(int j = i + 1; j < 40; j++) {
            if(gcd(j, i) != 1) continue;
            int a = 2 * i * j;
            int b = j * j - i * i;
            int c = j * j + i * i;
            if(1000 % (a + b + c) == 0) {
                int n = 1000 / (a + b + c);
                printf("%d\n", a * b * c * n * n * n);
                break;
            }
        }
    }
    return 0;
}
```



## Euler10线性筛

## **素数的和**

所有小于10的素数的和是2 + 3 + 5 + 7 = 17。

求所有小于两百万的素数的和。

```c
/*************************************************************************
	> File Name: oula10.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年08月03日 星期五 14时15分45秒
 ************************************************************************/

#include<iostream>
#include<inttypes.h>
#include<cstdio>
#define MAX_N 2000000
int prime[MAX_N] = {0};
void init() {
    for(int i = 2; i < MAX_N; i++) {
        if(!prime[i]) prime[++prime[0]] = i;
        for(int j = 1; j <= prime[0] && prime[j] * i < MAX_N; j++) {
            prime[i * prime[j]] = 1;
            if(i % prime[j] == 0) break;
        }
    }
}
int main() {
    init();
    int64_t ans = 0;
    for(int i = 1; i < MAX_N; i++) {
        if(prime[i] < MAX_N) ans += prime[i];
    }
    printf("%"PRId64"\n", ans);
    return 0;
}

```

## Euler11方向数组

## 08 02 22 97 38 15 00 40 00 75 04 05 07 78 52 12 50 77 91 08

49 49 99 40 17 81 18 57 60 87 17 40 98 43 69 48 04 56 62 00
81 49 31 73 55 79 14 29 93 71 40 67 53 88 30 03 49 13 36 65
52 70 95 23 04 60 11 42 69 24 68 56 01 32 56 71 37 02 36 91
22 31 16 71 51 67 63 89 41 92 36 54 22 40 40 28 66 33 13 80
24 47 32 60 99 03 45 02 44 75 33 53 78 36 84 20 35 17 12 50
32 98 81 28 64 23 67 10 **26** 38 40 67 59 54 70 66 18 38 64 70
67 26 20 68 02 62 12 20 95 **63** 94 39 63 08 40 91 66 49 94 21
24 55 58 05 66 73 99 26 97 17 **78** 78 96 83 14 88 34 89 63 72
21 36 23 09 75 00 76 44 20 45 35 **14** 00 61 33 97 34 31 33 95
78 17 53 28 22 75 31 67 15 94 03 80 04 62 16 14 09 53 56 92
16 39 05 42 96 35 31 47 55 58 88 24 00 17 54 24 36 29 85 57
86 56 00 48 35 71 89 07 05 44 44 37 44 60 21 58 51 54 17 58
19 80 81 68 05 94 47 69 28 73 92 13 86 52 17 77 04 89 55 40
04 52 08 83 97 35 99 16 07 97 57 32 16 26 26 79 33 27 98 66
88 36 68 87 57 62 20 72 03 46 33 67 46 55 12 32 63 93 53 69
04 42 16 73 38 25 39 11 24 94 72 18 08 46 29 32 40 62 76 36
20 69 36 41 72 30 23 88 34 62 99 69 82 67 59 85 74 04 36 16
20 73 35 29 78 31 90 01 74 31 49 71 48 86 81 16 23 57 05 54
01 70 54 71 83 51 54 69 16 92 33 48 61 43 52 01 89 19 67 48

这四个数的乘积是26 × 63 × 78 × 14 = 1788696。

在这个20×20方阵中，四个在同一方向（从下至上、从上至下、从右至左、从左至右或者对角线）上相邻的数的乘积最大是多少？

 ```c
/*************************************************************************
	> File Name: oula11.c
	> Author: 
	> Mail: 
	> Created Time: 2018年08月03日 星期五 15时03分11秒
 ************************************************************************/

#include<stdio.h>
#include<inttypes.h>
int vector[4][2] = {0, 1, 1, 1, 1, 0, 1, -1};//方向数组
int main() {
    int a[35][35] = {0};
    for(int i = 5; i < 25; i++) {
        for(int j = 5; j < 25; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    int64_t ans = 0;
    for(int i = 5; i < 25; i++) {
        for(int j = 5; j < 25; j++) {
            for(int k = 0; k < 4; k++) {
                int64_t p = 1;
                for(int l = 0; l < 4; l++) {
                    int x = i + l * vector[k][0];
                    int y = j + l * vector[k][1];
                    p *= a[x][y];
                }
            if(p > ans) ans = p;
            }
        }
    }
    printf("%"PRId64"\n", ans);
}
 ```

## 约数个数模板

```c
/*************************************************************************
	> File Name: oula12.c
	> Author: 
	> Mail: 
	> Created Time: 2018年08月05日 星期日 14时24分00秒
 ************************************************************************/

#include<stdio.h>
#define MAX_N 1000000
int prime[MAX_N] = {0};
int dnum[MAX_N] = {0};
int sanjiao(int x) {
    return x * (x + 1) / 2;
}
void init() {
    for(int i = 2; i * 2< MAX_N; i++) {
        if(!prime[i]) {
            prime[++prime[0]] = i;
            dnum[i] = 2;
        }
        for(int j = 1; j <= prime[0] && i * prime[j] < MAX_N; j++) {
            prime[i *prime[j]] = 1;
            if(i % prime[j] == 0) {
                int bj = 0, temp_i = i:;
                while(temp_i % prime[j] == 0) bj += 1, temp_i /= prime[j];
                dnum[i * prime[j]] = dnum[i] / (bj + 1) * (bj + 2);
                break;
            } else {
                dnum[i * prime[j]] = dnum[i] * dnum[prime[j]];
            }
        }
    }
}
int main() {
    init();
    int n = 1;
    for(int i = 2; i < 100; i++) {
        printf("%d %d\n", i ,dnum[i]);
    }
    return 0;
}
```



## Euler12约数个数

## **高度可约的三角形数**

三角形数数列是通过逐个加上自然数来生成的。例如，第7个三角形数是 1 + 2 + 3 + 4 + 5 + 6 + 7 = 28。三角形数数列的前十项分别是：

1, 3, 6, 10, 15, 21, 28, 36, 45, 55, …

让我们列举出前七个三角形数的所有约数：

 **1**: 1
 **3**: 1,3
 **6**: 1,2,3,6
**10**: 1,2,5,10
**15**: 1,3,5,15
**21**: 1,3,7,21
**28**: 1,2,4,7,14,28

我们可以看出，28是第一个拥有超过5个约数的三角形数。

第一个拥有超过500个约数的三角形数是多少？

```c

#include <stdio.h>

#define MAX_N 100000

int dnum[MAX_N + 5] = {0};
int mnum[MAX_N + 5] = {0};
int prime[MAX_N + 5] = {0};

void init() {
    for (int i = 2; i * 2 <= MAX_N; i++) {
        if (!prime[i]) {
            prime[++prime[0]] = i;
            dnum[i] = 2;
            mnum[i] = 1;
        }
        for (int j = 1; j <= prime[0]; j++) {
            if (i * prime[j] > MAX_N) break;
            prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) {
                mnum[i * prime[j]] = mnum[i] + 1;
                dnum[i * prime[j]] = dnum[i] / (mnum[i] + 1) * (mnum[i] + 2);
                break;
            } else {
                mnum[i * prime[j]] = 1;
                dnum[i * prime[j]] = dnum[i] * dnum[prime[j]];
            }
        }
    }
    return ;
}

int factor_nums(int n) {
    if (n & 1) {
        return dnum[n] * dnum[(n + 1) / 2];
    }
    return dnum[n / 2] * dnum[n + 1];
}

int main() {
    init();
    int n = 1;
    while (factor_nums(n) < 500) ++n;
    printf("%d\n", n * (n + 1) / 2);
    return 0;
}
```

暴力

```c
/*************************************************************************
	> File Name: 12.c
	> Author: 
	> Mail: 
	> Created Time: 2018年07月29日 星期日 10时20分37秒
 ************************************************************************/

#include <stdio.h>

int factor_num(int x) {
    int cut = 0;
    for (int i = 1; i * i <= x; i++) {
        if (x % i == 0) cut += 2;
    }
    return cut;
}

int main() {
    int n = 1;
    while (factor_num(n * (n + 1) / 2) < 500) ++n;
    printf("%d\n", n * (n + 1) / 2);
    return 0;
}
```



## Euler13

```c

```

## Euler14记忆化，考拉资

```c
/*************************************************************************
	> File Name: oula14.c
	> Author: 
	> Mail: 
	> Created Time: 2018年07月31日 星期二 16时22分48秒
 ************************************************************************/

#include<stdio.h>
#include <inttypes.h>
#define MAX_N 1000000
#define range 5000000
int memory[range + 5] = {0};
int64_t Collatz(int64_t x) {
    if(x == 1) return 1;
    if(memory[x] && memory[x] <= range) return memory[x];
    int64_t temp = 0;
    if(x % 2 == 0) temp = Collatz(x / 2) + 1;
    if(x % 2) temp = Collatz(3 * x + 1) + 1;
    if(temp <= range) memory[x] = temp;
    return temp;
}
int main() {
    int ans = 0;
    for(int i = 1; i <= MAX_N; i++) {
        if(Collatz(i) > ans) 
            ans = i;
    }
    printf("%"PRId64"\n",Collatz(ans));
    return 0;
}
```

## Euler15网格路径

```c
int main() {
    int64_t ans = 1, n = 21, m = 2;
    while(n <= 40 || m <= 20) {
        if(ans % m != 0) {
            ans *= n;
            n++;
        }
        if(ans % m == 0 && m <= 20){
            ans /= m;
            m++;
        }
    }
    printf("%"PRId64"\n",ans);
    return 0;
}
```

## Euler16大数

标准大数

```c
/*************************************************************************
	> File Name: oula16.c
	> Author: 
	> Mail: 
	> Created Time: 2018年08月05日 星期日 15时27分05秒
 ************************************************************************/

#include<stdio.h>
#define MAX_N 500
int a[MAX_N] = {1,1};
int dashu(int b, int c) {
    for(int i = 0 ; i < c; i++) {
        for(int j = 1; j <= a[0]; j++) {
            a[j] *= b;
        }
        for(int k = 1; k <= a[0]; k++) {
            if(a[k] < 10) continue;
            a[k + 1] += a[k] / 10;
            a[k] = a[k] % 10;
            if(k == a[0]) a[0]++;
        }
    }
}
int main() {
    dashu(2,1000);
    int ans = 0;
    for(int i = 1; i <= a[0]; i++) {
        ans += a[i];
    }
    printf("%d\n", ans);
    return 0;
}
```

## Euler17英文数词转化

```c
/*************************************************************************
	> File Name: oula17zhen.c
	> Author: 
	> Mail: 
	> Created Time: 2018年07月25日 星期三 08时51分51秒
 ************************************************************************/

#include<stdio.h>
int length20[20] = {
    0, 3, 3, 5, 4, 4, 3, 5, 5, 4, 3,
    6, 6, 8, 8, 7, 7, 9, 8, 8 };
int length10_bit[10] = {
    0, 0, 6, 6, 5, 5, 5, 7, 6, 6};
int exchenge_length(int x) {
    if(x < 20) {
        return length20[x];
    } else if(x < 100) {
        return length10_bit[x / 10] + length20[x % 10];
    } else if(x < 1000) {
        if(exchenge_length(x % 100)) {
            return exchenge_length(x % 100) + 3 + length20[x / 100] + 7;
        } else {
            return  exchenge_length(x % 100) + length20[x / 100] + 7;
        }
    } else {
        return 11;
    }
}
int main() {
    int ans = 0;
    for(int i = 1; i <= 1000; i++) {
        ans +=  exchenge_length(i);
    }
    printf("%d\n",ans);
    return 0;
}
```

## Euler18

## EUler19日期计算

```c
/*************************************************************************
	> File Name: oula19.c
	> Author: 
	> Mail: 
	> Created Time: 2018年08月05日 星期日 11时36分49秒
 ************************************************************************/

#include<stdio.h>
int day(int d, int m, int y) {
    int ans = 0;
    if(m == 1 || m == 2) {
        y -= 1;
        m += 12;
    }
    ans = (d + 2 * m + 3 * (m + 1) / 5 + y + y / 4 - y / 100 + y / 400) % 7;
    return ans + 1;
}
int main() {
    int ans = 0;
    for(int i = 1901; i <= 2000; i++) {
        for(int j = 1; j < 13; j++) {
            if(day(1,j,i) == 7) ans++;
        }
    }
    printf("%d\n", ans);
}
```

## EUler20大数（阶乘和）

```c
/*************************************************************************
	> File Name: oula20.c
	> Author: 
	> Mail: 
	> Created Time: 2018年08月05日 星期日 15时47分11秒
 ************************************************************************/

#include<stdio.h>
#define MAX_N 500
int a[MAX_N] = {1,1};
int dashu(int b, int c) {
    for(int i = b; i > 0; i--) {
        for(int j = 1; j <= a[0]; j++) {
            a[j] *= i;
        }
        for(int k = 1; k <= a[0]; k++) {
            if(a[k] < 10) continue;
            a[k + 1] += a[k] / 10;
            a[k] = a[k] % 10;
            if(k == a[0]) a[0]++;
        }
    }
}
int main() {
    dashu(100,100);
    int ans = 0;
    for(int i = 1; i <= a[0]; i++) {
        ans += a[i];
    }
    printf("%d\n", ans);
    return 0;
}
```

## EUler21亲和数（约数操作）

```c
#include <stdio.h>

#define MAX_N 100000

int prime[MAX_N + 5] = {0};

int main() {
    int ans = 0;
    for (int i = 1; i <= MAX_N; i++) {
        for (int j = i * 2; j <= MAX_N; j += i) prime[j] += i;
    }
    for (int i = 3; i <= 10000; i++) {
        if (i == prime[prime[i]] && i != prime[i]) ans += i;
    }
    printf("%d\n", ans);
    return 0;
}
```



## Euler22string操作

```c
 int64_t i = 0;
    while(a[i++].length() != 0);
    sort(a,a + i - 1);
    i = 0;
    int64_t ans = 0;
    while(a[i].length() != 0) {
        int64_t sum = 0;
        for(int j = 0 ; j < a[i].length(); j++) {
            sum += a[i][j] - 'A' + 1;
        }
        ans += sum * (++i);
    }
    printf("%"PRId64"\n",ans);
    return 0;
}
```

## Euler23约数操作

```c
/*************************************************************************
	> File Name: 23.c
	> Author: 
	> Mail: 
	> Created Time: 2018年08月05日 星期日 14时23分55秒
 ************************************************************************/

#include <stdio.h>

#define MAX_N 28150

int prime[MAX_N + 5] = {0};
int is_prime[MAX_N + 5] = {0};

int main() {
    int ans = 0;
    for (int i = 2; i <= MAX_N; i++) { // 计算除本身外因数和
        for (int j = i * 2; j <= MAX_N; j += i) prime[j] += i;
    }
    for (int i = 1; i <= MAX_N; i++) { // 筛盈数
        if (prime[i] <= i) prime[i] = 0;
    }
    for (int i = 1; i <= MAX_N - 1; i++) { // 标记两个盈数和
        for (int j = 1; i + j <= MAX_N; j++) {
            if (prime[i] && prime[j]) is_prime[i + j] = 1;
        }
    }
    for (int i = 1; i <= MAX_N; i++) {
        if (!is_prime[i]) ans += i;
    }
    printf("%d\n", ans);
    return 0;
}
```



## Euler24全排列

```c
/*************************************************************************
	> File Name: oula24.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年08月06日 星期一 09时57分31秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<inttypes.h>
#include<cstdio>
using namespace std;
int main() {
    int a[10];
    for(int i = 0; i < 10; i++) a[i] = i;
    int64_t n = 1;
    do {
        if(n == 1000000) {
            for(int i = 0; i < 10; i++)
            printf("%d" ,a[i]);
            break;
        }
        n++;
    } while(next_permutation(a, a + 10));
    return 0;
}

```

## EUler25斐波那契大数

```c
/*************************************************************************
	> File Name: oula25.c
	> Author: 
	> Mail: 
	> Created Time: 2018年07月27日 星期五 09时55分36秒
 ************************************************************************/

#include<stdio.h>
int fib[3][1005] = {{0, 0}, {1, 1}, {1, 1}};
int n = 2;
int main() {
    while(fib[n % 3][0] < 1000) {
        n += 1;
        int *a = fib[n % 3], *b = fib[(n - 1) % 3], *c = fib[(n - 2) % 3];
        a[0] = b[0];
        for (int i = 1; i <= b[0]; i++ ) {
            a[i] = b[i] + c[i];
        }
        for (int i = 1; i <= a[0]; i++) {
            if(a[i] < 10) continue;
            a[i + 1] += a[i] / 10;
            a[i] %= 10;
            a[0] += (a[0] == i);
        }
    }
    printf("%d\n", n);
    return 0;
}
```



## **字典序排列**

排列指的是将一组物体进行有顺序的放置。例如，3124是数字1、2、3、4的一个排列。如果把所有排列按照数字大小或字母先后进行排序，我们称之为字典序排列。0、1、2的字典序排列是：

012   021   102   120   201   210

数字0、1、2、3、4、5、6、7、8、9的字典序排列中第一百万位的排列是什么？

本题的一种思路是使用ｃ＋＋的ｓｔｌ中全排列函数直接排列到第一百万个，代码如下：

```c
#include<iostream>
#include<algorithm>
#include<inttypes.h>
using namespace std;
int main() {
    int a[10];
    int b[10];
    for(int i = 0; i < 10; i++) {
        a[i] = i;
    }
    int64_t i = 1, ans = 0;
    do{
        for(int j = 0; j < 10; j++) {
            cout << a[j];
        }
        if(i == 1000000)
        break;
        i++;
        cout << endl;
    }while(next_permutation(a, a + 10));
}
```

第二种方法是手动实现全排列

```cassandra
#include <stdio.h>
#define MAX_N 10
int jnum[MAX_N] = {0};//记录位值
int dnum[MAX_N] = {0};//记录答案
void init() {
    jnum[0] = dnum[0] = 1;
    for (int i = 1; i < MAX_N; i++) {
        dnum[i] = 1;
        jnum[i] = i * jnum[i - 1];
    }
    return ; 
}//数组初始化完成
int judge_num(int n, int k) {
    int ind = (k / jnum[n]) + 1, i = -1;
    while (ind > 0) {
        i++;
        ind -= dnum[i];
    }
    dnum[i] = 0;
    return i;
}
int main() {
    init();
    int n, k;
    scanf("%d%d", &n, &k);
    k -= 1;//????
    for (int i = n - 1; i >= 0; i--) {
        int num = judge_num(i, k);
        printf("%d", num);
        k %= jnum[i];
    }
    printf("\n");
    return 0;
}
```

## Euler26模拟除法竖式

单位分数指分子为1的分数。分母为2至10的单位分数的十进制表示如下所示：

1/2= 0.5
1/3= 0.(3)
1/4= 0.25
1/5= 0.2
1/6= 0.1(6)
1/7= 0.(142857)
1/8= 0.125
1/9= 0.(1)
1/10= 0.1

这里0.1(6)表示0.166666…，括号内表示有一位循环节。可以看出，1/7有六位循环节。

找出正整数d < 1000，其倒数的十进制表示小数部分有最长的循环节。

由题可知，如果要求循环节，我们需要模拟除法竖式，以为分子都为一所以我们可以确定每次更新为

分子　×　１０　/　分母，代码如下：

```c
#include<stdio.h>
#include<inttypes.h>
#define MAX_N 1000
int bit(int x) {
    int a[1000] = {0};
    int y = 1, n = 1;
    while(y && a[y] == 0) {
        a[y] = n;
        y = y * 10 % x;
        n++;
    }
    return y ? n - a[y] : 0;
}
int main() {
    int temp = 0, ans = 0,sum = 0;
    for(int i = 2; i < 1000; i++) {
        temp = bit(i);
        if(temp > ans){
            sum = i;//注意结果要的是分子不是循环节长度
            ans = temp;
        }
    }
    printf("%d\n", sum);
    return 0;
 }
```

## Euler２９模拟大整数乘方

考虑所有满足2 ≤ a ≤ 5和2 ≤ b ≤ 5的整数组合生成的幂ab：

> 22=4, 23=8, 24=16, 25=32
> 32=9, 33=27, 34=81, 35=243
> 42=16, 43=64, 44=256, 45=1024
> 52=25, 53=125, 54=625, 55=3125

如果把这些幂按照大小排列并去重，我们得到以下由15个不同的项组成的序列：

4, 8, 9, 16, 25, 27, 32, 64, 81, 125, 243, 256, 625, 1024, 3125

在所有满足2 ≤ a ≤ 100和2 ≤ b ≤ 100的整数组合生成的幂ab排列并去重所得到的序列中，有多少个不同的项？

由题可知，我们需要模拟大整数乘法，并比对。

```c
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int a[10005][500];
int ans = 0;
int rules(int b, int c) {
    int num[500] = {0};
    num[0] = 1;
    num[1] = 1;
    for(int i = 0; i < c; i++) {
        for(int j = 1; j <= num[0]; j++) num[j] *= b;
        for(int k = 1; k <= num[0]; k++) {
            if(num[k] < 10) continue;
            num[k + 1] += num[k] / 10;
            num[k] = num[k] %10;
            if(k == num[0]) num[0]++;
        }
    }//大整数乘法以及进位操作
    int temp = 0;
    for(int i = 0; i < ans; i++) {
        if(memcmp(a[i],num,sizeof(int) * 500) == 0) {//从a[0]　比对到ans-1个如果有便不在记入数组和总个数
            temp = 1;
            break;
        }
    }
    if(temp == 0) {
        memcpy(a[ans],num, sizeof(int) * 500);
        ans++;
    }
}
int main() {
    for(int i = 2; i <= 100; i++) {
        for(int j = 2; j <= 100; j++) {
            rules(i, j);
        }
    }
    printf("%d\n", ans);
}
```

## Euler39勾股数

若三边长{a,b,c}均为整数的直角三角形周长为p，当p = 120时，恰好存在三个不同的解：

{20,48,52}, {24,45,51}, {30,40,50}

在所有的p ≤ 1000中，p取何值时有解的数目最多？

由题意可知，我们可以采用暴力枚举的方法枚举出两条直角边，再通过勾股定理确定第三边：

```c
#include<stdio.h>
int main() {
    int ans = 0, sum = 0;
    for(int i = 3; i < 1001; i++) {
        int temp = 0;
        for(int j = 1; j  < i; j++) {
            for(int k = 1; k < j; k++) {
                int l = i - j - k;
                if(l < 0) break;
                if(j * j + k * k == l * l) {
                    temp++;
                    break;
                }
            }
        }
        if(temp > ans) {
            ans = temp;
            sum = i;
        }
    }
    printf("%d\n", sum);
    return 0;
}
```

但是很明显暴力存在很大的局限性

那让我们从数学的角度思考，如果三个数是勾股数他们又恰好满足了周长的话我们就将其算为一种组成方式。

勾股数分为素勾股数和合勾股数。以下是素勾股数的几条重要性质：

## １．如果ａ,b,c是勾股数那么他们的整数倍（na,nb,nc）也是勾股数.

## 2.如果a,b,c为素勾股数，则a,b,c两两互质即gcd(x,y) == 1

## 3.素勾股数中a,b必为一奇一偶

## ４．任何素勾股数可以表达为如下形式，其中n < m ,

## 且gcd(n, m) == 1;

## a = 2 * n * m; b = m * m - n * n; c = m * m + n *  n

所以我们只要通过枚举m,n来枚举出素勾股数，再通过素勾股数表达合勾股数。

```c
#include<stdio.h>
#define MAX_N 1001
int num[1500] = {0};
int gcd(int a,int b) {
    return b == 0 ? a : gcd(b, a % b);//求公约数，如果公约数为１则两数互质
}
int Addnum(int a, int b ,int c) {
    int temp = a + b + c;
    for(int i = temp; i <= MAX_N; i += temp) {//勾股数的整数倍是勾股数
        num[i] += 1;
    }
}
int main() {
    int ans = 1;
    for(int i = 1; i < 35; i++) {
        for(int j = i + 1; j < 35; j++) {
            if(gcd(j, i) != 1) continue;//经过此步后gcd(n, m) == 1
            int a = 2 * i * j;
            int b = j * j - i * i;
            int c = j * j + i * i;
            if(a + b + c > MAX_N) continue;
            Addnum(a, b, c);
        }
    }
    for(int i = 1; i < MAX_N; i++) {
        if(num[ans] < num[i]) ans = i;
    }
    printf("%d\n",ans);
    return 0;
}
```

## EUler40钱鉑闹恩常数

```c

#include<stdio.h>
#define MAX_N 2002000
int num[MAX_N] = {0};
int ans = 0;
void init() {
    int x = 1;
    for(int i = 1; i < 302000; i++) {
        int n = i, z = i, temp = 1, m = 0;
        while(z) {
            m++;
            temp *= 10;
            z /= 10;
        }
        temp /= 10;
        while(n || m) {
            if(n == 0 && m != 0) num[x] = 0;
            else num[x] = n / temp;
            m--;
            n = n % temp;
            temp /= 10;
            x++;
        }
    }
}
int main() {
    init();
    int y = 1;
    for(int i = 1; i <= 1000000; i *= 10) {
        y *= num[i];
        printf("%d %d\n",num[i], i);
    }
    printf("%d\n", y);
    return 0;
}
```

## EULER41全数字素数



## Euler42string二分

**编码三角形数**

三角形数序列的第n项由公式tn = 1/2n(n+1)给出；因此前十个三角形数是：

1, 3, 6, 10, 15, 21, 28, 36, 45, 55, …

将一个单词的每个字母分别转化为其在字母表中的顺序并相加，我们可以计算出一个单词的值。例如，单词SKY的值就是 19 + 11 + 25 = 55 = t10。如果一个单词的值是一个三角形数，我们就称这个单词为三角形单词。

在这个16K的文本文件[words.txt](https://projecteuler.net/project/resources/p042_words.txt) （右击并选择“目标另存为……”）中包含有将近两千个常用英文单词，这其中有多少个三角形单词？

由题意可知，我们应该设计一个num_judg函数判断一个数是否为特殊规则数（二分法），使用ｓｔｒｉｎｇ数组存储单词。代码如下：

```c
/*************************************************************************
	> File Name: oula42.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年08月02日 星期四 11时12分46秒
 ************************************************************************/

#include<iostream>
#include<string.h>
#include<cstdio>
using namespace std;
int san(int x) {
    return x * (x + 1) / 2;
}
int judg_num(int x) {
    int left = 0, right = x, mid;
    while(left <= right) {
        mid = (left + right);
        if( san(mid) == x) return 1;
        if( san(mid) < x) left = mid + 1;
        if( san(mid) > x) right = mid - 1;
    }
    return 0;
}
int main() {
    string num[100000] = {
    "A","ABILITY","ABLE","ABOUT","ABOVE","ABSENCE","ABSOLUTELY","ACADEMIC","ACCEPT","ACCESS","ACCIDENT","ACCOMPANY","ACCORDING","ACCOUNT","ACHIEVE","ACHIEVEMENT","ACID","ACQUIRE","ACROSS","ACT","ACTION","ACTIVE","ACTIVITY","ACTUAL","ACTUALLY","ADD","ADDITION","ADDITIONAL","ADDRESS","ADMINISTRATION","ADMIT","ADOPT","ADULT","ADVANCE","ADVANTAGE","ADVICE","ADVISE","AFFAIR","AFFECT","AFFORD","AFRAID","AFTER","AFTERNOON","AFTERWARDS","AGAIN","AGAINST","AGE","AGENCY","AGENT","AGO","AGREE","AGREEMENT","AHEAD","AID","AIM","AIR","AIRCRAFT","ALL","ALLOW","ALMOST","ALONE","ALONG","ALREADY","ALRIGHT","ALSO","ALTERNATIVE","ALTHOUGH","ALWAYS","AMONG","AMONGST","AMOUNT","AN","ANALYSIS","ANCIENT","AND","ANIMAL","ANNOUNCE","ANNUAL","ANOTHER","ANSWER","ANY","ANYBODY","ANYONE","ANYTHING","ANYWAY","APART","APPARENT","APPARENTLY","APPEAL","APPEAR","APPEARANCE","APPLICATION","APPLY","APPOINT","APPOINTMENT","APPROACH","APPROPRIATE","APPROVE","AREA","ARGUE","ARGUMENT","ARISE","ARM","ARMY","AROUND","ARRANGE","ARRANGEMENT","ARRIVE","ART","ARTICLE","ARTIST","AS","ASK","ASPECT","ASSEMBLY","ASSESS","ASSESSMENT","ASSET","ASSOCIATE","ASSOCIATION","ASSUME","ASSUMPTION","AT","ATMOSPHERE","ATTACH","ATTACK","ATTEMPT","ATTEND","ATTENTION","ATTITUDE","ATTRACT","ATTRACTIVE","AUDIENCE","AUTHOR","AUTHORITY","AVAILABLE","AVERAGE","AVOID","AWARD","AWARE","AWAY","AYE","BABY","BACK","BACKGROUND","BAD","BAG","BALANCE","BALL","BAND","BANK","BAR","BASE","BASIC","BASIS","BATTLE","BE","BEAR","BEAT","BEAUTIFUL","BECAUSE","BECOME","BED","BEDROOM","BEFORE","BEGIN","BEGINNING","BEHAVIOUR","BEHIND","BELIEF","BELIEVE","BELONG","BELOW","BENEATH","BENEFIT","BESIDE","BEST","BETTER","BETWEEN","BEYOND","BIG","BILL","BIND","BIRD","BIRTH","BIT","BLACK","BLOCK","BLOOD","BLOODY","BLOW","BLUE","BOARD","BOAT","BODY","BONE","BOOK","BORDER","BOTH","BOTTLE","BOTTOM","BOX","BOY","BRAIN","BRANCH","BREAK","BREATH","BRIDGE","BRIEF","BRIGHT","BRING","BROAD","BROTHER","BUDGET","BUILD","BUILDING","BURN","BUS","BUSINESS","BUSY","BUT","BUY","BY","CABINET","CALL","CAMPAIGN","CAN","CANDIDATE","CAPABLE","CAPACITY","CAPITAL","CAR","CARD","CARE","CAREER","CAREFUL","CAREFULLY","CARRY","CASE","CASH","CAT","CATCH","CATEGORY","CAUSE","CELL","CENTRAL","CENTRE","CENTURY","CERTAIN","CERTAINLY","CHAIN","CHAIR","CHAIRMAN","CHALLENGE","CHANCE","CHANGE","CHANNEL","CHAPTER","CHARACTER","CHARACTERISTIC","CHARGE","CHEAP","CHECK","CHEMICAL","CHIEF","CHILD","CHOICE","CHOOSE","CHURCH","CIRCLE","CIRCUMSTANCE","CITIZEN","CITY","CIVIL","CLAIM","CLASS","CLEAN","CLEAR","CLEARLY","CLIENT","CLIMB","CLOSE","CLOSELY","CLOTHES","CLUB","COAL","CODE","COFFEE","COLD","COLLEAGUE","COLLECT","COLLECTION","COLLEGE","COLOUR","COMBINATION","COMBINE","COME","COMMENT","COMMERCIAL","COMMISSION","COMMIT","COMMITMENT","COMMITTEE","COMMON","COMMUNICATION","COMMUNITY","COMPANY","COMPARE","COMPARISON","COMPETITION","COMPLETE","COMPLETELY","COMPLEX","COMPONENT","COMPUTER","CONCENTRATE","CONCENTRATION","CONCEPT","CONCERN","CONCERNED","CONCLUDE","CONCLUSION","CONDITION","CONDUCT","CONFERENCE","CONFIDENCE","CONFIRM","CONFLICT","CONGRESS","CONNECT","CONNECTION","CONSEQUENCE","CONSERVATIVE","CONSIDER","CONSIDERABLE","CONSIDERATION","CONSIST","CONSTANT","CONSTRUCTION","CONSUMER","CONTACT","CONTAIN","CONTENT","CONTEXT","CONTINUE","CONTRACT","CONTRAST","CONTRIBUTE","CONTRIBUTION","CONTROL","CONVENTION","CONVERSATION","COPY","CORNER","CORPORATE","CORRECT","COS","COST","COULD","COUNCIL","COUNT","COUNTRY","COUNTY","COUPLE","COURSE","COURT","COVER","CREATE","CREATION","CREDIT","CRIME","CRIMINAL","CRISIS","CRITERION","CRITICAL","CRITICISM","CROSS","CROWD","CRY","CULTURAL","CULTURE","CUP","CURRENT","CURRENTLY","CURRICULUM","CUSTOMER","CUT","DAMAGE","DANGER","DANGEROUS","DARK","DATA","DATE","DAUGHTER","DAY","DEAD","DEAL","DEATH","DEBATE","DEBT","DECADE","DECIDE","DECISION","DECLARE","DEEP","DEFENCE","DEFENDANT","DEFINE","DEFINITION","DEGREE","DELIVER","DEMAND","DEMOCRATIC","DEMONSTRATE","DENY","DEPARTMENT","DEPEND","DEPUTY","DERIVE","DESCRIBE","DESCRIPTION","DESIGN","DESIRE","DESK","DESPITE","DESTROY","DETAIL","DETAILED","DETERMINE","DEVELOP","DEVELOPMENT","DEVICE","DIE","DIFFERENCE","DIFFERENT","DIFFICULT","DIFFICULTY","DINNER","DIRECT","DIRECTION","DIRECTLY","DIRECTOR","DISAPPEAR","DISCIPLINE","DISCOVER","DISCUSS","DISCUSSION","DISEASE","DISPLAY","DISTANCE","DISTINCTION","DISTRIBUTION","DISTRICT","DIVIDE","DIVISION","DO","DOCTOR","DOCUMENT","DOG","DOMESTIC","DOOR","DOUBLE","DOUBT","DOWN","DRAW","DRAWING","DREAM","DRESS","DRINK","DRIVE","DRIVER","DROP","DRUG","DRY","DUE","DURING","DUTY","EACH","EAR","EARLY","EARN","EARTH","EASILY","EAST","EASY","EAT","ECONOMIC","ECONOMY","EDGE","EDITOR","EDUCATION","EDUCATIONAL","EFFECT","EFFECTIVE","EFFECTIVELY","EFFORT","EGG","EITHER","ELDERLY","ELECTION","ELEMENT","ELSE","ELSEWHERE","EMERGE","EMPHASIS","EMPLOY","EMPLOYEE","EMPLOYER","EMPLOYMENT","EMPTY","ENABLE","ENCOURAGE","END","ENEMY","ENERGY","ENGINE","ENGINEERING","ENJOY","ENOUGH","ENSURE","ENTER","ENTERPRISE","ENTIRE","ENTIRELY","ENTITLE","ENTRY","ENVIRONMENT","ENVIRONMENTAL","EQUAL","EQUALLY","EQUIPMENT","ERROR","ESCAPE","ESPECIALLY","ESSENTIAL","ESTABLISH","ESTABLISHMENT","ESTATE","ESTIMATE","EVEN","EVENING","EVENT","EVENTUALLY","EVER","EVERY","EVERYBODY","EVERYONE","EVERYTHING","EVIDENCE","EXACTLY","EXAMINATION","EXAMINE","EXAMPLE","EXCELLENT","EXCEPT","EXCHANGE","EXECUTIVE","EXERCISE","EXHIBITION","EXIST","EXISTENCE","EXISTING","EXPECT","EXPECTATION","EXPENDITURE","EXPENSE","EXPENSIVE","EXPERIENCE","EXPERIMENT","EXPERT","EXPLAIN","EXPLANATION","EXPLORE","EXPRESS","EXPRESSION","EXTEND","EXTENT","EXTERNAL","EXTRA","EXTREMELY","EYE","FACE","FACILITY","FACT","FACTOR","FACTORY","FAIL","FAILURE","FAIR","FAIRLY","FAITH","FALL","FAMILIAR","FAMILY","FAMOUS","FAR","FARM","FARMER","FASHION","FAST","FATHER","FAVOUR","FEAR","FEATURE","FEE","FEEL","FEELING","FEMALE","FEW","FIELD","FIGHT","FIGURE","FILE","FILL","FILM","FINAL","FINALLY","FINANCE","FINANCIAL","FIND","FINDING","FINE","FINGER","FINISH","FIRE","FIRM","FIRST","FISH","FIT","FIX","FLAT","FLIGHT","FLOOR","FLOW","FLOWER","FLY","FOCUS","FOLLOW","FOLLOWING","FOOD","FOOT","FOOTBALL","FOR","FORCE","FOREIGN","FOREST","FORGET","FORM","FORMAL","FORMER","FORWARD","FOUNDATION","FREE","FREEDOM","FREQUENTLY","FRESH","FRIEND","FROM","FRONT","FRUIT","FUEL","FULL","FULLY","FUNCTION","FUND","FUNNY","FURTHER","FUTURE","GAIN","GAME","GARDEN","GAS","GATE","GATHER","GENERAL","GENERALLY","GENERATE","GENERATION","GENTLEMAN","GET","GIRL","GIVE","GLASS","GO","GOAL","GOD","GOLD","GOOD","GOVERNMENT","GRANT","GREAT","GREEN","GREY","GROUND","GROUP","GROW","GROWING","GROWTH","GUEST","GUIDE","GUN","HAIR","HALF","HALL","HAND","HANDLE","HANG","HAPPEN","HAPPY","HARD","HARDLY","HATE","HAVE","HE","HEAD","HEALTH","HEAR","HEART","HEAT","HEAVY","HELL","HELP","HENCE","HER","HERE","HERSELF","HIDE","HIGH","HIGHLY","HILL","HIM","HIMSELF","HIS","HISTORICAL","HISTORY","HIT","HOLD","HOLE","HOLIDAY","HOME","HOPE","HORSE","HOSPITAL","HOT","HOTEL","HOUR","HOUSE","HOUSEHOLD","HOUSING","HOW","HOWEVER","HUGE","HUMAN","HURT","HUSBAND","I","IDEA","IDENTIFY","IF","IGNORE","ILLUSTRATE","IMAGE","IMAGINE","IMMEDIATE","IMMEDIATELY","IMPACT","IMPLICATION","IMPLY","IMPORTANCE","IMPORTANT","IMPOSE","IMPOSSIBLE","IMPRESSION","IMPROVE","IMPROVEMENT","IN","INCIDENT","INCLUDE","INCLUDING","INCOME","INCREASE","INCREASED","INCREASINGLY","INDEED","INDEPENDENT","INDEX","INDICATE","INDIVIDUAL","INDUSTRIAL","INDUSTRY","INFLUENCE","INFORM","INFORMATION","INITIAL","INITIATIVE","INJURY","INSIDE","INSIST","INSTANCE","INSTEAD","INSTITUTE","INSTITUTION","INSTRUCTION","INSTRUMENT","INSURANCE","INTEND","INTENTION","INTEREST","INTERESTED","INTERESTING","INTERNAL","INTERNATIONAL","INTERPRETATION","INTERVIEW","INTO","INTRODUCE","INTRODUCTION","INVESTIGATE","INVESTIGATION","INVESTMENT","INVITE","INVOLVE","IRON","IS","ISLAND","ISSUE","IT","ITEM","ITS","ITSELF","JOB","JOIN","JOINT","JOURNEY","JUDGE","JUMP","JUST","JUSTICE","KEEP","KEY","KID","KILL","KIND","KING","KITCHEN","KNEE","KNOW","KNOWLEDGE","LABOUR","LACK","LADY","LAND","LANGUAGE","LARGE","LARGELY","LAST","LATE","LATER","LATTER","LAUGH","LAUNCH","LAW","LAWYER","LAY","LEAD","LEADER","LEADERSHIP","LEADING","LEAF","LEAGUE","LEAN","LEARN","LEAST","LEAVE","LEFT","LEG","LEGAL","LEGISLATION","LENGTH","LESS","LET","LETTER","LEVEL","LIABILITY","LIBERAL","LIBRARY","LIE","LIFE","LIFT","LIGHT","LIKE","LIKELY","LIMIT","LIMITED","LINE","LINK","LIP","LIST","LISTEN","LITERATURE","LITTLE","LIVE","LIVING","LOAN","LOCAL","LOCATION","LONG","LOOK","LORD","LOSE","LOSS","LOT","LOVE","LOVELY","LOW","LUNCH","MACHINE","MAGAZINE","MAIN","MAINLY","MAINTAIN","MAJOR","MAJORITY","MAKE","MALE","MAN","MANAGE","MANAGEMENT","MANAGER","MANNER","MANY","MAP","MARK","MARKET","MARRIAGE","MARRIED","MARRY","MASS","MASTER","MATCH","MATERIAL","MATTER","MAY","MAYBE","ME","MEAL","MEAN","MEANING","MEANS","MEANWHILE","MEASURE","MECHANISM","MEDIA","MEDICAL","MEET","MEETING","MEMBER","MEMBERSHIP","MEMORY","MENTAL","MENTION","MERELY","MESSAGE","METAL","METHOD","MIDDLE","MIGHT","MILE","MILITARY","MILK","MIND","MINE","MINISTER","MINISTRY","MINUTE","MISS","MISTAKE","MODEL","MODERN","MODULE","MOMENT","MONEY","MONTH","MORE","MORNING","MOST","MOTHER","MOTION","MOTOR","MOUNTAIN","MOUTH","MOVE","MOVEMENT","MUCH","MURDER","MUSEUM","MUSIC","MUST","MY","MYSELF","NAME","NARROW","NATION","NATIONAL","NATURAL","NATURE","NEAR","NEARLY","NECESSARILY","NECESSARY","NECK","NEED","NEGOTIATION","NEIGHBOUR","NEITHER","NETWORK","NEVER","NEVERTHELESS","NEW","NEWS","NEWSPAPER","NEXT","NICE","NIGHT","NO","NOBODY","NOD","NOISE","NONE","NOR","NORMAL","NORMALLY","NORTH","NORTHERN","NOSE","NOT","NOTE","NOTHING","NOTICE","NOTION","NOW","NUCLEAR","NUMBER","NURSE","OBJECT","OBJECTIVE","OBSERVATION","OBSERVE","OBTAIN","OBVIOUS","OBVIOUSLY","OCCASION","OCCUR","ODD","OF","OFF","OFFENCE","OFFER","OFFICE","OFFICER","OFFICIAL","OFTEN","OIL","OKAY","OLD","ON","ONCE","ONE","ONLY","ONTO","OPEN","OPERATE","OPERATION","OPINION","OPPORTUNITY","OPPOSITION","OPTION","OR","ORDER","ORDINARY","ORGANISATION","ORGANISE","ORGANIZATION","ORIGIN","ORIGINAL","OTHER","OTHERWISE","OUGHT","OUR","OURSELVES","OUT","OUTCOME","OUTPUT","OUTSIDE","OVER","OVERALL","OWN","OWNER","PACKAGE","PAGE","PAIN","PAINT","PAINTING","PAIR","PANEL","PAPER","PARENT","PARK","PARLIAMENT","PART","PARTICULAR","PARTICULARLY","PARTLY","PARTNER","PARTY","PASS","PASSAGE","PAST","PATH","PATIENT","PATTERN","PAY","PAYMENT","PEACE","PENSION","PEOPLE","PER","PERCENT","PERFECT","PERFORM","PERFORMANCE","PERHAPS","PERIOD","PERMANENT","PERSON","PERSONAL","PERSUADE","PHASE","PHONE","PHOTOGRAPH","PHYSICAL","PICK","PICTURE","PIECE","PLACE","PLAN","PLANNING","PLANT","PLASTIC","PLATE","PLAY","PLAYER","PLEASE","PLEASURE","PLENTY","PLUS","POCKET","POINT","POLICE","POLICY","POLITICAL","POLITICS","POOL","POOR","POPULAR","POPULATION","POSITION","POSITIVE","POSSIBILITY","POSSIBLE","POSSIBLY","POST","POTENTIAL","POUND","POWER","POWERFUL","PRACTICAL","PRACTICE","PREFER","PREPARE","PRESENCE","PRESENT","PRESIDENT","PRESS","PRESSURE","PRETTY","PREVENT","PREVIOUS","PREVIOUSLY","PRICE","PRIMARY","PRIME","PRINCIPLE","PRIORITY","PRISON","PRISONER","PRIVATE","PROBABLY","PROBLEM","PROCEDURE","PROCESS","PRODUCE","PRODUCT","PRODUCTION","PROFESSIONAL","PROFIT","PROGRAM","PROGRAMME","PROGRESS","PROJECT","PROMISE","PROMOTE","PROPER","PROPERLY","PROPERTY","PROPORTION","PROPOSE","PROPOSAL","PROSPECT","PROTECT","PROTECTION","PROVE","PROVIDE","PROVIDED","PROVISION","PUB","PUBLIC","PUBLICATION","PUBLISH","PULL","PUPIL","PURPOSE","PUSH","PUT","QUALITY","QUARTER","QUESTION","QUICK","QUICKLY","QUIET","QUITE","RACE","RADIO","RAILWAY","RAIN","RAISE","RANGE","RAPIDLY","RARE","RATE","RATHER","REACH","REACTION","READ","READER","READING","READY","REAL","REALISE","REALITY","REALIZE","REALLY","REASON","REASONABLE","RECALL","RECEIVE","RECENT","RECENTLY","RECOGNISE","RECOGNITION","RECOGNIZE","RECOMMEND","RECORD","RECOVER","RED","REDUCE","REDUCTION","REFER","REFERENCE","REFLECT","REFORM","REFUSE","REGARD","REGION","REGIONAL","REGULAR","REGULATION","REJECT","RELATE","RELATION","RELATIONSHIP","RELATIVE","RELATIVELY","RELEASE","RELEVANT","RELIEF","RELIGION","RELIGIOUS","RELY","REMAIN","REMEMBER","REMIND","REMOVE","REPEAT","REPLACE","REPLY","REPORT","REPRESENT","REPRESENTATION","REPRESENTATIVE","REQUEST","REQUIRE","REQUIREMENT","RESEARCH","RESOURCE","RESPECT","RESPOND","RESPONSE","RESPONSIBILITY","RESPONSIBLE","REST","RESTAURANT","RESULT","RETAIN","RETURN","REVEAL","REVENUE","REVIEW","REVOLUTION","RICH","RIDE","RIGHT","RING","RISE","RISK","RIVER","ROAD","ROCK","ROLE","ROLL","ROOF","ROOM","ROUND","ROUTE","ROW","ROYAL","RULE","RUN","RURAL","SAFE","SAFETY","SALE","SAME","SAMPLE","SATISFY","SAVE","SAY","SCALE","SCENE","SCHEME","SCHOOL","SCIENCE","SCIENTIFIC","SCIENTIST","SCORE","SCREEN","SEA","SEARCH","SEASON","SEAT","SECOND","SECONDARY","SECRETARY","SECTION","SECTOR","SECURE","SECURITY","SEE","SEEK","SEEM","SELECT","SELECTION","SELL","SEND","SENIOR","SENSE","SENTENCE","SEPARATE","SEQUENCE","SERIES","SERIOUS","SERIOUSLY","SERVANT","SERVE","SERVICE","SESSION","SET","SETTLE","SETTLEMENT","SEVERAL","SEVERE","SEX","SEXUAL","SHAKE","SHALL","SHAPE","SHARE","SHE","SHEET","SHIP","SHOE","SHOOT","SHOP","SHORT","SHOT","SHOULD","SHOULDER","SHOUT","SHOW","SHUT","SIDE","SIGHT","SIGN","SIGNAL","SIGNIFICANCE","SIGNIFICANT","SILENCE","SIMILAR","SIMPLE","SIMPLY","SINCE","SING","SINGLE","SIR","SISTER","SIT","SITE","SITUATION","SIZE","SKILL","SKIN","SKY","SLEEP","SLIGHTLY","SLIP","SLOW","SLOWLY","SMALL","SMILE","SO","SOCIAL","SOCIETY","SOFT","SOFTWARE","SOIL","SOLDIER","SOLICITOR","SOLUTION","SOME","SOMEBODY","SOMEONE","SOMETHING","SOMETIMES","SOMEWHAT","SOMEWHERE","SON","SONG","SOON","SORRY","SORT","SOUND","SOURCE","SOUTH","SOUTHERN","SPACE","SPEAK","SPEAKER","SPECIAL","SPECIES","SPECIFIC","SPEECH","SPEED","SPEND","SPIRIT","SPORT","SPOT","SPREAD","SPRING","STAFF","STAGE","STAND","STANDARD","STAR","START","STATE","STATEMENT","STATION","STATUS","STAY","STEAL","STEP","STICK","STILL","STOCK","STONE","STOP","STORE","STORY","STRAIGHT","STRANGE","STRATEGY","STREET","STRENGTH","STRIKE","STRONG","STRONGLY","STRUCTURE","STUDENT","STUDIO","STUDY","STUFF","STYLE","SUBJECT","SUBSTANTIAL","SUCCEED","SUCCESS","SUCCESSFUL","SUCH","SUDDENLY","SUFFER","SUFFICIENT","SUGGEST","SUGGESTION","SUITABLE","SUM","SUMMER","SUN","SUPPLY","SUPPORT","SUPPOSE","SURE","SURELY","SURFACE","SURPRISE","SURROUND","SURVEY","SURVIVE","SWITCH","SYSTEM","TABLE","TAKE","TALK","TALL","TAPE","TARGET","TASK","TAX","TEA","TEACH","TEACHER","TEACHING","TEAM","TEAR","TECHNICAL","TECHNIQUE","TECHNOLOGY","TELEPHONE","TELEVISION","TELL","TEMPERATURE","TEND","TERM","TERMS","TERRIBLE","TEST","TEXT","THAN","THANK","THANKS","THAT","THE","THEATRE","THEIR","THEM","THEME","THEMSELVES","THEN","THEORY","THERE","THEREFORE","THESE","THEY","THIN","THING","THINK","THIS","THOSE","THOUGH","THOUGHT","THREAT","THREATEN","THROUGH","THROUGHOUT","THROW","THUS","TICKET","TIME","TINY","TITLE","TO","TODAY","TOGETHER","TOMORROW","TONE","TONIGHT","TOO","TOOL","TOOTH","TOP","TOTAL","TOTALLY","TOUCH","TOUR","TOWARDS","TOWN","TRACK","TRADE","TRADITION","TRADITIONAL","TRAFFIC","TRAIN","TRAINING","TRANSFER","TRANSPORT","TRAVEL","TREAT","TREATMENT","TREATY","TREE","TREND","TRIAL","TRIP","TROOP","TROUBLE","TRUE","TRUST","TRUTH","TRY","TURN","TWICE","TYPE","TYPICAL","UNABLE","UNDER","UNDERSTAND","UNDERSTANDING","UNDERTAKE","UNEMPLOYMENT","UNFORTUNATELY","UNION","UNIT","UNITED","UNIVERSITY","UNLESS","UNLIKELY","UNTIL","UP","UPON","UPPER","URBAN","US","USE","USED","USEFUL","USER","USUAL","USUALLY","VALUE","VARIATION","VARIETY","VARIOUS","VARY","VAST","VEHICLE","VERSION","VERY","VIA","VICTIM","VICTORY","VIDEO","VIEW","VILLAGE","VIOLENCE","VISION","VISIT","VISITOR","VITAL","VOICE","VOLUME","VOTE","WAGE","WAIT","WALK","WALL","WANT","WAR","WARM","WARN","WASH","WATCH","WATER","WAVE","WAY","WE","WEAK","WEAPON","WEAR","WEATHER","WEEK","WEEKEND","WEIGHT","WELCOME","WELFARE","WELL","WEST","WESTERN","WHAT","WHATEVER","WHEN","WHERE","WHEREAS","WHETHER","WHICH","WHILE","WHILST","WHITE","WHO","WHOLE","WHOM","WHOSE","WHY","WIDE","WIDELY","WIFE","WILD","WILL","WIN","WIND","WINDOW","WINE","WING","WINNER","WINTER","WISH","WITH","WITHDRAW","WITHIN","WITHOUT","WOMAN","WONDER","WONDERFUL","WOOD","WORD","WORK","WORKER","WORKING","WORKS","WORLD","WORRY","WORTH","WOULD","WRITE","WRITER","WRITING","WRONG","YARD","YEAH","YEAR","YES","YESTERDAY","YET","YOU","YOUNG","YOUR","YOURSELF","YOUTH"
    };
    int i = 0, ans = 0;
    while(num[i++].length() != 0) {
        int temp = 0;
        for(int j = 0; j < num[i].length(); j++) {
            temp += num[i][j] - 'A' + 1;
        }
        if(judg_num(temp)) ans++;
    }
    printf("%d\n", ans);
}

```

## Euler46哥德巴赫猜想

**哥德巴赫的另一个猜想**

克里斯蒂安·哥德巴赫曾经猜想，每个奇合数可以写成一个素数和一个平方的两倍之和。

> 9 = 7 + 2×12
> 15 = 7 + 2×22
> 21 = 3 + 2×32
> 25 = 7 + 2×32
> 27 = 19 + 2×22
> 33 = 31 + 2×12

最终这个猜想被推翻了。

最小的不能写成一个素数和一个平方的两倍之和的奇合数是多少？

由题意可知，我们可以如果通过正向枚举肯定很难，所以我们应该枚举平方数，验证素数，来反向枚举，代码如下：

```c
/*************************************************************************
	> File Name: oula46.c
	> Author: 
	> Mail: 
	> Created Time: 2018年08月02日 星期四 11时36分07秒
 ************************************************************************/

#include<stdio.h>
#define MAX_N 500000
int prime[MAX_N] = {0};
void init() {
    for(int i = 2; i * i < MAX_N; i++) {
        if(prime[i]) continue;
        for(int j = i * i; j < MAX_N; j += i) {
            prime[j] = 1;
        }
    }
}//素数筛
int main() {
    init();
    for(int i = 1; i < MAX_N; i += 2) {
        if(!prime[i]) continue;
        //已为奇合数
        int judg = 0;
        for(int j = 1; 2 * j * j < i; j++) {
            int temp = 2 * j * j;
            if(!prime[i - temp]) {
                judg = 1;
                break;
            }
        }
        if(judg == 0) {
            printf("%d\n", i);
            break;
        }
    }
    return 0;
}
```

## Euler47质因数

**不同的质因数**

首次出现连续两个数均有两个不同的质因数是在：

14 = 2 × 7
15 = 3 × 5

首次出现连续三个数均有三个不同的质因数是在：

644 = 22 × 7 × 23
645 = 3 × 5 × 43
646 = 2 × 17 × 19

首次出现连续四个数均有四个不同的质因数时，其中的第一个数是多少？

进行线性筛的同时统计每一个合数的质因数数量

```c
/*************************************************************************
	> File Name: oula47.c
	> Author: 
	> Mail: 
	> Created Time: 2018年08月02日 星期四 14时43分34秒
 ************************************************************************/

#include<stdio.h>
#define MAX_N 1000000
int prime[MAX_N + 5] = {0};
int dnum[MAX_N + 5] = {0};
void init() {//线性筛
    for(int i = 2; i < MAX_N; i++) {
        if(!prime[i]) {
            prime[++prime[0]] = i;
            dnum[i] = 1;// 如果ｉ是素数那他的质因子为１
        }
        for(int j = 1; j <= prime[0] && i * prime[j] < MAX_N; j++) {
            prime[i * prime[j]] = 1;
            dnum[i * prime[j]] = dnum[i] + (i % prime[j] != 0);//i % prime[j]是否等于０可以判断该合数是否拥有该质因子，如果已经有了不计入
            if(i % prime[j] == 0) break;
        }
    }
}
int main() {
    init();
    for(int i = 1; i  <= MAX_N -3; i++) {
        if(dnum[i] < 4) continue;
        if(dnum[i + 1] < 4) continue;
        if(dnum[i + 2] < 4) continue;
        if(dnum[i + 3] < 4) continue;
        printf("%d\n",i);
        break;
    }
    
    return 0;
}
```

## Euler48大数自幂

```c
/*************************************************************************
	> File Name: oula48.c
	> Author: 
	> Mail: 
	> Created Time: 2018年08月01日 星期三 17时41分45秒
 ************************************************************************/

#include<stdio.h>
#include<inttypes.h>
#define MAX_N 100000
int num[MAX_N] = {0};
int dashu_cheng(int b, int c) {
    int a[MAX_N] = {1,1};
    for(int i = 0 ; i < c; i++) {
        for(int j = 1; j <= 10; j++) {
            a[j] *= b;
        }
        for(int k = 1; k <= 10; k++) {
            if(a[k] < 10) continue;
            a[k + 1] += a[k] / 10;
            a[k] = a[k] % 10;
        }
    }
    for(int i = 1; i <= 10; i++) {
        num[i] += a[i];
    }
    for(int j = 1; j <= 10; j++) {
        if(num[j] < 10) continue;
        num[j + 1] += num[j] / 10;
        num[j] = num[j] % 10;
    }
}
int main() {
    int ans = 0;
    for(int i = 1;i < 1001; i++) {
        dashu_cheng(i, i);
    }
    for(int i = 10; i >= 1; i--) {
        printf("%d",num[i]);
    }
    return 0;
}
```



## Euler31硬币dp

**硬币求和**

英国的货币单位包括英镑£和便士p，在流通中的硬币一共有八种：

> 1p, 2p, 5p, 10p, 20p, 50p, £1 (100p), £2 (200p)

以下是组成£2的其中一种可行方式：

> 1×£1 + 1×50p + 2×20p + 1×5p + 1×2p + 3×1p

不限定使用的硬币数目，组成£2有多少种不同的方式？

这是一个动态规划问题，那么应先给予一个状态定义，然后写下状态转移方程

```c
#include<stdio.h>
int a[8] = {1, 2, 5, 10, 20, 50, 100, 200};
int dp[205] = {0};
int main() {
    dp[0] = 1;
    for(int i = 0; i < 8; i++) {
        for(int j = a[i]; j <= 200; j++) {
            dp[j] += dp[j - a[i]];
        }
    }
    printf("%d\n",dp[200]);
    return 0;
}???
```

## Euler32全数字成积

## Euler33非平凡解

49/98是一个有趣的分数，因为缺乏经验的数学家可能在约简时错误地认为，等式49/98 = 4/8之所以成立，是因为在分数线上下同时抹除了9的缘故。

我们也会想到，存在诸如30/50 = 3/5这样的平凡解。

这类有趣的分数恰好有四个非平凡的例子，它们的分数值小于1，且分子和分母都是两位数。

将这四个分数的乘积写成最简分数，求此时分母的值。

```c
/*************************************************************************
	> File Name: oula33.c
	> Author: 
	> Mail: 
	> Created Time: 2018年08月02日 星期四 15时33分11秒
 ************************************************************************/

#include<stdio.h>
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}//公约数
int main() {
    int x = 1, y = 1;
    for(int i = 10; i < 100; i++) {
        for(int j = i + 1; j < 100; j++) {
            int a = i / 10;
            int b = i % 10;
            int c = j / 10;
            int d = j % 10;//分离各位
            if(b == c && d != 0 && i * d == j * a) {
                // 非平凡数＆＆化简相等
                x *= a;
                y *= d;
            }
        }
    }
    printf("%d\n", y / gcd(y, x));//分母化简
    return 0;
}
```

## Euler35数字重排

197被称为圆周素数，因为将它逐位旋转所得到的数：197/971和719都是素数。

小于100的圆周素数有十三个：2、3、5、7、11、13、17、31、37、71、73、79和97。

小于一百万的圆周素数有多少个？

```c
/*************************************************************************
	> File Name: oula35.c
	> Author: 
	> Mail: 
	> Created Time: 2018年08月01日 星期三 14时11分41秒
 ************************************************************************/

#include<stdio.h>
#define MAX_N 1000000
int prime[MAX_N] = {0};
void init() {
    for(int i = 2; i * i < MAX_N; i++) {
        if(prime[i]) continue;
        for(int j = i * i; j < MAX_N; j += i) {
            prime[j] = 1;
        }
    }
}
int num(int x) {
    int cmp = x, y = x, n = 1, m = 0;
    while(x) {
        x /= 10;
        m++;
        n *= 10;
    }
    n /= 10; 
    for(int i = 0; i < m - 1; i++) {
        y = y / 10 + y % 10 * n;
        if(y <= 1)
        return 0;
        if(prime[y])
        return 0;
    }
    return 1;
}
int main() {
    init();
    int ans = 0;
    for(int i = 2; i < MAX_N; i++) {
        if(!prime[i]) {
            if(num(i))
                ans += 1;
        }
    }
    printf("%d\n",ans);
    return 0;
}
```

## Euler37数字规则排列

3797有着奇特的性质。不仅它本身是一个素数，而且如果从左往右逐一截去数字，剩下的仍然都是素数：3797、797、97和7；同样地，如果从右往左逐一截去数字，剩下的也依然都是素数：3797、379、37和3。

只有11个素数，无论从左往右还是从右往左逐一截去数字，剩下的仍然都是素数，求这些数的和。

注意：2、3、5和7不被视为可截素数。模拟：

```c
/*************************************************************************
	> File Name: oula37.c
	> Author: 
	> Mail: 
	> Created Time: 2018年08月01日 星期三 13时46分35秒
 ************************************************************************/

#include<stdio.h>
#define MAX_N 10000000
int prime[MAX_N] = {0};
void init() {
    for(int i = 2; i * i < MAX_N; i++) {
        if(prime[i]) continue;
        for(int j = i * i; j < MAX_N; j += i) {
            prime[j] = 1;
        }
    }
}
int num(int x) {
    int cmp = x, y = x, n = 1, m = 0;
    while(x) {
        x /= 10;
        m++;
        n *= 10;
    }
    n /= 10; 
    for(int i = 0; i < m - 1; i++) {
        y = y - y / n * n;
        n /= 10;
        if(y <= 1)
        return 0;
        if(prime[y])
        return 0;
    }
    for(int i = 0; i < m - 1; i++) {
        cmp /= 10;
        if(cmp <= 1)
        return 0;
        if(prime[cmp])
        return 0;
    }
    return 1;
}
int main() {
    init();
    int ans = 0;
    for(int i = 11; i < MAX_N; i++) {
        if(!prime[i]) {
            if(num(i))
                ans += i;
        }
    }
    printf("%d\n",ans);
    return 0;
}
```

## Euler38全数字的倍数（未解决）



## Euler43全排列子串

**子串的可整除性**

1406357289是一个0至9全数字数，因为它由0到9这十个数字排列而成；但除此之外，它还有一个有趣的性质：子串的可整除性。

记d1是它的第一个数字，d2是第二个数字，依此类推，我们注意到：

- d2d3d4=406能被2整除
- d3d4d5=063能被3整除
- d4d5d6=635能被5整除
- d5d6d7=357能被7整除
- d6d7d8=572能被11整除
- d7d8d9=728能被13整除
- d8d9d10=289能被17整除

找出所有满足同样性质的0至9全数字数，并求它们的和。

 

```c
/*************************************************************************
	> File Name: oula43.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年08月02日 星期四 15时49分20秒
 ************************************************************************/

#include<iostream>
#include<inttypes.h>
#include<cstdio>
#include<algorithm>
using namespace std;
int num[8] = {0, 2, 3, 5, 7, 11,13, 17};
int64_t judg(int *x) {
    if(x[0] == 0) return 0;
    for(int i = 1; i < 8; i++) {
        int temp = 0;
        for(int j = 0; j < 3; j++) {
            temp = temp * 10 + x[i + j];
        }
        if(temp % num[i] != 0) return 0; 
    }
    int64_t ans = 0;
    for(int i = 0; i < 10; i++) {
        ans = ans * 10 + x[i];
    }
    return ans;
}
int main() {
    int a[10];
    int64_t ans = 0;
    for(int i = 0; i < 10; i++) a[i] = i;
    do{
        ans += judg(a);
    }while(next_permutation(a, a + 10));
    printf("%"PRId64"\n", ans);
}
```

## Euler44五边形数二分

```c
/*************************************************************************
	> File Name: oula44.c
	> Author: 
	> Mail: 
	> Created Time: 2018年08月01日 星期三 15时47分20秒
 ************************************************************************/

#include<stdio.h>
#include<inttypes.h>
#define MAX_N 6000000
int64_t a[MAX_N] = {0};
int64_t pentagonal(int64_t x) {
    return x * (x * 3 - 1) / 2;
}
int num_judge(int x) {
    int num_left = 0, num_right = x, mid;
    while(num_left <= num_right) {
        mid = (num_left + num_right) / 2;
        if(pentagonal(mid) == x) return 1;
        if(pentagonal(mid) > x) num_right = mid - 1;
        if(pentagonal(mid) < x) num_left = mid + 1;
    }
    return 0;
}
int main() {
    int64_t i = 1, j = 1, ans = INT64_MAX;
    while (pentagonal(j + 1) - pentagonal(j) < ans) {
        j++;
        i = j - 1;
        do {
            if (num_judge(pentagonal(i) + pentagonal(j))) {
                if (num_judge(pentagonal(j) - pentagonal(i))) {
                    if (pentagonal(j) - pentagonal(i) < ans) {
                        ans = pentagonal(j) - pentagonal(i);
                    }
                }
            }
            i--;
        } while (i >= 1 && pentagonal(j) - pentagonal(i) < ans);
    }
    printf("%" PRId64 "\n", ans);
    return 0;
}
```

## Euler45可变函数二分

```c
/*************************************************************************
	> File Name: oula45.c
	> Author: 
	> Mail: 
	> Created Time: 2018年07月29日 星期日 09时12分47秒
 ************************************************************************/

#include<stdio.h>
#include<inttypes.h>
typedef int64_t int1;
int1 Triangle(int1 n) {
    return n * (n + 1) / 2;
}
int1 Pentagonal(int1 n) {
    return n * (3 * n - 1) / 2;
}
int1 Hexagonal(int1 n) {
    return n * (2 * n - 1);
}
int1 binary_search(int1 (*num)(int1), int1 n, int1 x) {
    int1 head = 0, tail = n - 1, mid;
    while(head <= tail) {
        mid = (head + tail) >> 1;
        if(num(mid) == x) return mid;
        if(num(mid) > x) tail = tail - 1;
        else head = head + 1;
    }
    return -1;
}
int main() {
    int1 n = 144;
    while(binary_search(Pentagonal,2 * n, Hexagonal(n)) == -1 ) ++n;
    printf("%" PRId64 "\n",Hexagonal(n));
    return 0;
}
```

## Euler49素数重排

```c
/*************************************************************************
	> File Name: 49.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年08月05日 星期日 10时36分16秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstdio>

#define MAX_N 200000

using namespace std;

int is_prime[MAX_N + 5] = {0}; // 标记素数
int prime[MAX_N + 5] = {0}; // 存素数
int k = 0; // 记录初始位置

void init() {
    for (int i = 2; i <= MAX_N; i++) {
        if (!is_prime[i]) prime[++prime[0]] = i;
        if (!k && prime[prime[0]] > 1000) k = prime[0]; 
        for (int j = 1; j <= prime[0] && i * prime[j] <= MAX_N; j++) {
            is_prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
}

int check(int i, int n) { // 判断是否成分一样
    int num1[5] = {0}, num2[5] = {0}, num3[5] = {0}, m = 0;
    int a = prime[i], b = prime[i] + n, c = prime[i] + n + n;
    while (m++ < 4) { // 按位储存到数组
        num1[m] = a % 10;
        num2[m] = b % 10;
        num3[m] = c % 10;
        a /= 10, b /= 10, c /= 10;
    }
    sort(num1, num1 + 5);
    sort(num2, num2 + 5);
    sort(num3, num3 + 5);
    while (--m >= 1) { // 判断是否成分一样
        if (num1[m] != num2[m] || num2[m] != num3[m] || num1[m] != num3[m]) return 0;
    }
    return 1;
}

int main() {
    init();
    for (int i = k; prime[i] < 10000; i++) {
        for (int n = 1; prime[i] + n + n < 10000; n++) {
            if (is_prime[prime[i] + n] || is_prime[prime[i] + n + n]) continue; // 判断是否是素数
            if (check(i, n)) printf("%d%d%d\n", prime[i], prime[i] + n, prime[i] + n + n);
        }
    }
    return 0;
}
```

## Euler50最长连续素数和

```c
/*************************************************************************
	> File Name: 50.c
	> Author: 
	> Mail: 
	> Created Time: 2018年08月05日 星期日 18时10分36秒
 ************************************************************************/

#include <stdio.h>

#define MAX_N 1000000

int prime[MAX_N + 5] = {0};
int is_prime[MAX_N + 5] = {0};

void init() {
    for (int i = 2; i <= MAX_N; i++) { // 线性筛
        if (!is_prime[i]) prime[++prime[0]] = i;
        for (int j = 1; i * prime[j] <= MAX_N && j <= prime[0]; j++) {
            is_prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
}

int main() {
    init();
    int sum = 0, ans = 0, len = 0, ans_len = 0;
    for (int i = 1; i <= prime[0]; i++) { // 求小于1000000最长的可以写成连续素数和的素数
        len = 0;
        sum = 0;
        for (int j = i; j <= prime[0]; j++) {
            sum += prime[j];
            len++;
            if (sum >= MAX_N) break;
            if (is_prime[sum]) continue;
            if (len > ans_len) {
                ans_len = len;
                ans = sum;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}

```

