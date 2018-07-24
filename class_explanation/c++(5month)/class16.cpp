/*
복사하면 시간이 느려지기 때문에 복사말고 참조를 사용해서 넣기를 추천한다.

std::list<int>& 를 넣어서 복사를 방지한다.
할당 할때도 std::list<int>& 를 사용해서 할당 받는다

복사 자체를 못하게 할려면 return 값을 포인터로 받게 한다. 
std::list<int>* @@@ (return &result) -> 할당 받을 때 std::list<int>*로 받아야 함

[이팩티브 c++] = 필수도서 ㅋㅋㅋㅋ

벡터의 push_back은 2배로 길이를 늘린 이후 복사해서 기존의 것을 지우는 과정
따라서 안에다가 캐릭터가 아니라 포인터로 넣어야 한다.

[header]
declthpe(&arrList) GetList() {return &arrList;} - auto이전의 버전에서는
auto* GetList() {return &arrList;}

set map은 중복값을 넣을 수 없다. 
insert로 넣는다 (set)
find (set)  있냐 없냐

map = 사전 (키, 값) - 찾는것을 차례대로 하지 않기 때문에 빠르게 logn만큼으로 
아름[키] = 값;
-> 키값은 중복 될 수 없기 때문에 뒤에서 선언된것만 유효하다.
(삽입과 삭제가 느리다 - 재구축이 있어야 해서 - 검색이 빠르다)
- 그래서 map을 이용해서 삭제를 할때는 real 삭제 말고 사용할 수 없다고 표시만 함
(리스트는 삽입과 삭제가 빠르지만 검색이 느리다)
- 이진탐색을 하기 때문에
(그래서 자료 구조상 균형이진트리로 만들어야 함)

find의 경우 iterator를 반환한다 
그래서 존재하지 않는 경우 end()/값이 없다!!!!!!/를 반환해 준다
(mapID.find(name) == napID.end())

리스트를 거꾸로 돌때는 rbegin ~ rend로 돌아야 한다
*/
#include <vector>
#include <list>
#include <iostream>
#include <set>
#include <map>
using namespace std;

int main()
{
    list<int> listInt;
    listInt.push_back(1);
    listInt.push_back(2);
    listInt.push_back(3);
    listInt.push_back(2);

    for(auto num : listInt)
    // iterator를 사용하지 못함
    {
        std :: cout << num;
    }

    auto it = listInt.begin();
    auto it_end = listInt.end();
    for( ; it != it_end ; ++it)
    {
        std::cout << *it;
        if(*it == 2)
        {
            listInt.erase(it);
            break; // 첫번째 2만 삭제됨
        }
    }
// 둘중하나 만 실행시 
    for( ; it != it_end ; )
    {
        std::cout << *it;
        if(*it == 2)
        {
            it = listInt.erase(it); // 다음 iterator를 준다
        }
        else  ++it;
    }


    std::set<int> setInt;
    setInt.insert(1);
    setInt.insert(2);
    setInt.insert(3);
    setInt.insert(1);  // 3개의 값 (123)이 들어 있다.
    
    std::map<string, string> alias;
    alias["Tong"] = "women";
    alias["Kim"] = "man";

    std::cout << alias["Tong"];

    map<string map<string, int>> guminMap;
    guminMap["성북구"]["이혜진"] = 1;

    map<string map<string, int>>:: it; // 이렇게 이터레이터를 만든다
    return 0;
}