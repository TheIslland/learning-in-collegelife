/*************************************************************************
	> File Name: 释放一个类.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年04月05日 星期五 09时57分05秒
 ************************************************************************/
#include <iostream>
#include <string>
#include <memory>

using namespace std;

class Animal
{
public:
    string name;

    virtual string Introduce() = 0;
};

class IAnimalFactory
{
public:
    virtual shared_ptr<Animal> CreateAnimal() = 0;
};

class Cat : public Animal
{
public:
    string Introduce()override
    {
        return "我是一只猫，我的名字是" + name + "。";
    }
};

class CatFactory : public IAnimalFactory
{
public:
    shared_ptr<Animal> CreateAnimal()override
    {
        auto cat = make_shared<Cat>();
        cat->name = "Tom";
        return cat;
    }
};

void IntroduceAnimalFromFactory(IAnimalFactory* factory)
{
    auto animal = factory->CreateAnimal();
    cout << animal->Introduce() << endl;
}

int main()
{
    CatFactory factory;
    IntroduceAnimalFromFactory(&factory);
    return 0;
}
