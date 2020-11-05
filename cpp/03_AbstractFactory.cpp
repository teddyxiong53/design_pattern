#include <stdio.h>
#include <iostream>

//抽象上衣
class Coat
{
public:
    virtual const std::string& color() = 0;
};
//黑色上衣
class BlackCoat: public Coat
{
public:
    BlackCoat() : Coat(), m_strColor("black coat")
    {

    }
    const std::string& color() override
    {
        printf("color:%s\n", m_strColor.c_str());
        return m_strColor;
    }
private:
    std::string m_strColor;
};
//白色上衣
class WhiteCoat : public Coat
{
public:
    WhiteCoat() : Coat(), m_strColor("white coat")
    {

    }
    const std::string& color() override
    {
        printf("color:%s\n", m_strColor.c_str());
        return m_strColor;
    }
private:
    std::string m_strColor;
};
//抽象裤子
class Pants
{
public:
    virtual const std::string& color() = 0;
};

//黑色裤子
class BlackPants: public Pants
{
public:
    BlackPants() : Pants(), m_strColor("black pants")
    {

    }
    const std::string& color() override
    {
        printf("color:%s\n", m_strColor.c_str());
        return m_strColor;
    }
private:
    std::string m_strColor;
};

//白色裤子
class WhitePants: public Pants
{
public:
    WhitePants() : Pants(), m_strColor("white pants")
    {

    }
    const std::string& color() override
    {
        printf("color:%s\n", m_strColor.c_str());
        return m_strColor;
    }
private:
    std::string m_strColor;
};

//抽象工厂
class Factory
{
public:
    virtual Coat* createCoat() = 0;
    virtual Pants* createPants() = 0;
};

//生成白色服装的工厂
class WhiteFactory: public Factory
{
public:
    Coat * createCoat() override
    {
        return new WhiteCoat();
    }
    Pants* createPants() override
    {
        return new WhitePants();
    }

};

//生成黑色服装的工厂
class BlackFactory: public Factory
{
public:
    Coat * createCoat() override
    {
        return new BlackCoat();
    }
    Pants* createPants() override
    {
        return new BlackPants();
    }

};

int main()
{
    Factory *factoryWhite = new WhiteFactory();
    Coat* coatWhite = factoryWhite->createCoat();
    Pants *pantsWhite = factoryWhite->createPants();
    coatWhite->color();
    pantsWhite->color();
    return 0;
}
