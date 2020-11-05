#include <stdio.h>
#include <iostream>

class Clone
{
public:
    virtual Clone* clone() = 0;
    virtual void show() = 0;
};

class Sheep: public Clone
{
public:
    Sheep(int id, std::string name)
    : Clone(),
      m_id(id),
      m_name(name)
    {
        printf("id address(construct):%p\n", &m_id);
        printf("name address(construct):%p\n", &m_name);
    }
    ~Sheep()
    {

    }
    //关键代码，拷贝构造
    Sheep(const Sheep& other)
    {
        this->m_id = other.m_id;
        this->m_name = other.m_name;
        printf("id address(copy construct):%p\n", &m_id);
        printf("name address(copy construct):%p\n", &m_name);
    }
    Clone* clone() override
    {
        return new Sheep(*this);
    }
    void show() override
    {
        printf("id:%d\n", m_id);
        printf("name:%s\n", m_name.c_str());
    }
private:
    int m_id;
    std::string m_name;
};

int main(int argc, char const *argv[])
{
    Clone *s1 = new Sheep(1, "aaa");
    s1->show();
    Clone *s2 = s1->clone();
    s2->show();

    return 0;
}

