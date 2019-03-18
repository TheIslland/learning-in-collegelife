# lambda表达式

lambda对应的旧时代的概念应该是函数指针，虽然lambda表达式的大部分功能时函数指针无法实现的。

## vector里的偶数个数和奇数个数

### 经典算法

```
int Count(vector<int>& numbers, bool(*filter)(int)) {
    int counter = 0;
    for (int x : numbers) {
        if (filter(x)) {
            counter++;
        }
    }
    return counter;
}

bool Odd(int x) {
    return x % 2 == 1;
}

bool Even(int x) {
    return x % 2 == 0;
}

int CountOdds(vector<int>& numbers) {
    return Count(numbers, &Odd);
}

int CountEvens(vector<int>& numbers) {
    return Count(numbers, &Even);
}
```

### Lambda

```
template<typename U>
int Count(vector<int>& numbers, U filter) {
    int counter = 0;
    for (int x : numbers) {
        if (filter(x)) {
            counter++;
        }
    }
    return counter;
}

int CountOdds(vector<int>& numbers) {
    return Count(numbers, [](int x){ return x % 2 == 1; });
}

int CountEvens(vector<int>& numbers) {
    return Count(numbers, [](int x){ return x % 2 == 0; });
}
```

## Lambda表达式写法

语法:`[捕获](参数){一些语句}`

捕获：捕获主要控制Lambda表达式的函数体可以看见外面的名字。空的话表示什么都不给看

参数：就跟函数的参数一样。Lambda表达式既然也是函数的一种那他就可以需要参数

一些语句：Lambda表达式的函数体

### 模板的简单功能

一.声明一个模板参数，他的名字是u，用来代表一个暂时无法确定的类型。使用u的心情，就跟过去使用void*的时候差不多

```
template<typename u>
```

二.告诉大家，filter参数的类型是什么我不知道，我也不想管，总之它可以接受Lambda表达式就行了。我们不需要使用任何代码来指明u必须就一个Lambda爱表达式的类型--举个例子，如果你穿了一个int进去，那就会在filter(x)的那一行代码里报错， 因为一个数字，譬如说0你写0(x)肯定是过不了编译的而且也灭有任何意义

```
int Count(vector<int>& numbers, u filter)
```

### Lambda表达式和函数指针的区别

函数指针的声明比较复杂。虽然在这个例子里面含不怎么看出来，但是里面的东西一多你就只好不断地typedef

使用函数指针会使用代码逻辑分散。其实这个在vector和排序的例子里面已经提到过了。Lambda表达式可以让所有相关的代码都放在一起。而使用函数指针经常会让你把几段完整的表达逻辑代码分散在不用的函数里面难以阅读

### 使用count函数来寻找vector里面所有大于x的数字一共多少个

写一个新的count

让你的count函数增加一个"上下文"参数

```
int Count(vector<int>& numbers, bool(*filter)(int, void*), void* context) {
    int counter = 0;
    for (int x : numbers) {
        if (filter(x, context)) {
            counter++;
        }
    }
    return counter;
}

bool GreaterThan(int x, void* context) {
    return x > *reinterpret_cast<int*>(context);
}

int CountGreaterThan(vector<int>& numbers, int y) {
    return Count(numbers, &GreaterThan, &y);
}
```

#### countodds和countevens

```
bool Odd(int x, void*) {
    return x % 2 == 1;
}

bool Even(int x, void*) {
    return x % 2 == 0;
}

int CountOdds(vector<int>& numbers) {
    return Count(numbers, &Odd, nullptr);
}

int CountEvens(vector<int>& numbers) {
    return Count(numbers, &Even, nullptr);
}
```

#### Lambda

```
// Count函数不用改
template<typename U>
int Count(vector<int>& numbers, U filter);

int CountGreaterThan(vector<int&> numbers, int y)
{
    return Count(numbers, [=](int x){ return x > y; });
}
```

凡是这个Lambda表达式需要用到的外部的值，我们都要复制一份进去。在这里赋值一个是一个int比起传统的版本你要把它编程void*然后再变回来无伤大雅

我们可以在方括号里面加入的所有东西。方括号里面可以写不同的项，每一项由逗号分开。覅一项可以是下列集中：

=:需要的值都复制

&:需要的值都复制他们的引用，意味着你可以让你的Lambda表达式使用外部的一个vector而且还可以修改它

this:如果你的Lambda表达式在一个类里，那么你还可以看到这个类，使用类成员的时候仍然可以省略this指针

省略:就像前面的几个例子一样，既然什么都不需要，那可以不写

后面的几项就可以是x或者&x这样的东西，代表你要赋值x还是赋值x的引用。如果你的Lambda表达式需要看到a，b，c三个vector，外加一个字符串x的副本，你就可以携程[&, x]。&在这里代表"所有使用到的东西都把它的指针复制进去"。x在这里代表"但是x就要复制它的值"

[const auto& x = f(y)]这样的代码，把f(y)返回的一个引用复制进去，起个名字叫x。

## 把a里面所有大于x的值复制进b，其中a和b都是vector

```
template<typename U>
void Traverse(vector<int>& xs, U process) {
    for (int x : xs) {
        process(x);
    }
}

void CopyGreaterThan(vector<int>& a, vector<int>& b, int y) {
    Traverse(a, [&, y](int x) {
        if (x > y) {
            b.push_back(x);
        }
    });
}
```

一般来说我们都简易使用模板参数表示函数，从而可以使用Lambda表达式。保存下来不可的时候可以使用，譬如说存到一个类里，或者vector里

自从有了Lambda表达式之后，类似bind这样的函数其实也就失去了意义。任何操作function东西都可以使用Lambda表达式来完成，而且更直观易读

我们现在完成一个函数Adder。Adder(x)会返回一个函数，给一个整数加上x。说起来可能有点拗口，上面这句话表达成代码就是：

```
auto f = Adder(1);
cout << f(2) << endl; // 输出3
```

## 如何返回一个函数

c++中没有办法让我们拿到一个整数x就立即生成一个函数，我们只能用Lambda表达式来做，但是Lambda表达式的类型是没有名字的，因此返回值只能时std::function。那韩慧的函数的类型是什么呢，它输入一个整数返回一个整数，所以是int(int).因此Adder的代码:

```
function<int(int)> Adder(int x) {
    return [=](int y){ return x + y; };
}
```

```
function<int(int)> Compose(function<int(int)> f, function<int(int)> g)
{
    return[=](int y){ return f(g(y)); };
}

int main()
{
    auto adder = Compose(Adder(1), Adder(2));
    cout << adder(3) << endl;
    return 0;
}
//1+2+3=6
```

函数compose接受两个参数，他们是函数f和g然后返回一个新的函数:输入y得到f(g(y))。在main函数里面，我们令f加1令g加2令y加3答案就为6了

### 原始代码	:

```
auto adder = Compose(Adder(1), Adder(2));
cout << adder(3) << endl;
```

第一步展开compose

```
auto f = Adder(1);
auto g = Adder(2);
auto adder = [](int y){ return f(g(y)) };
cout << adder(3) << endl;
```

第二部展开Adder

```
auto f = [](int y){ return 1 + y; };
auto g = [](int y){ return 2 + y; };
auto adder = [](int y){ return f(g(y)) };
cout << adder(3) << endl;
```

第三步,展开f：

```
auto g = [](int y){ return 2 + y; };
auto adder = [](int y){ return 1 + g(y) };
cout << adder(3) << endl;
```

第四步,展开g:

```
auto adder = [](int y){ return 1 + 2 + y };
cout << adder(3) << endl;
```

最后一步展开addr

```
cout << 1 + 2 + 3 << endl;
```





















