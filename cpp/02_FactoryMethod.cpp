#include <iostream>
#include <stdio.h>

//定义产品类型
typedef enum {
    Tank_Type_56,//56式坦克。
    Tank_Type_96,
    Tank_Type_Num,
} Tank_Type;

//抽象产品类
class Tank
{
public:
    virtual const std::string& type() = 0;
};

//具体产品类
class Tank56: public Tank
{
public:
    Tank56(): Tank(), m_strType("Tank56")
    {

    }
    const std::string& type() override
    {
        printf("type:%s\n", m_strType.c_str());
        return m_strType;
    }
private:
    std::string m_strType;
};

//具体产品类
class Tank96: public Tank
{
public:
    Tank96(): Tank(), m_strType("Tank96")
    {

    }
    const std::string& type() override
    {
        printf("type:%s\n", m_strType.c_str());
        return m_strType;
    }
private:
    std::string m_strType;
};

//抽象工厂类
class TankFactory
{
public:
    virtual Tank* createTank() = 0;

};
//具体工厂类
class Tank56Factory : public TankFactory
{
public:
    Tank* createTank() override
    {
        return new Tank56();
    }
};
//具体工厂类
class Tank96Factory : public TankFactory
{
public:
    Tank* createTank() override
    {
        return new Tank96();
    }
};

int main()
{
    TankFactory *factory56 = new Tank56Factory();
    Tank* tank56 = factory56->createTank();
    tank56->type();
    delete tank56;
    delete factory56;
    return 0;
}

