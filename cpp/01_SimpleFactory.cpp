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
//工厂类
class TankFactory
{
public:
    Tank* createTank(Tank_Type type)
    {
        switch (type)
        {
        case Tank_Type_56:
            return new Tank56();
            break;
        case Tank_Type_96:
            return new Tank96();
            break;
        default:
            return nullptr;
            break;
        }
    }
};

int main()
{
    TankFactory *factory = new TankFactory();
    Tank* tank56 = factory->createTank(Tank_Type_56);
    tank56->type();
    delete tank56;
    delete factory;
}

