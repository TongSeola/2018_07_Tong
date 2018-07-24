#include <string>
#include <iostream>
using namespace std;

class CCharacter:
{
public:
    CCharacter();
    ~CCharacter();

    virtual void SayMyName() {
        std:: cout << "My Name is : " << Name << std::endl;
        // 상속된 것 안에 똑같은 이름의 것이 있는지 확인(virtual)
    }

    static int count;

protected:
        std:: string Name;
}