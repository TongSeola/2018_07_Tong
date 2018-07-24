#include <string>
#include<iostream>
using namespace std;
int CCharacter::count;

CCharacter::CCharacter()
{
    std:: cout << "기본생성자" << std::endl;
}

CCharacter::CCharacter(const & src)
{
    std:: cout << "복사생성자" << std::endl;
}