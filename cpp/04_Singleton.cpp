#include <stdio.h>
#include <iostream>
#include <mutex>

std::mutex g_mutex;
class Singleton
{
public:
    static Singleton* getInstance()
    {
        if(m_singleton == NULL) {
            std::lock_guard lock(g_mutex);
            if(m_singleton == NULL) {
                m_singleton = new Singleton();
            }
        }
        return m_singleton;
    }
    ~Singleton();
private:
    Singleton()
    {
        //私有构造，空的就行。
    }
    Singleton(const Singleton& ) = delete;
    Singleton& operator=(const Singleton& ) = delete;

    static Singleton* m_singleton;
};
Singleton* Singleton::m_singleton = NULL;

int main(int argc, char const *argv[])
{

    return 0;
}

