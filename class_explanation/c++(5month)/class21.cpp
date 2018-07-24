/*
[stl 알고리즘]
벡터의 .end는 마지막 요소가 아닌 null(마지막 다음)을 반환한다

reverse 이터레이터는 rbegin rend를 사용한다
-> ++로 증가해야 함!!!!!

벡터의 find가 찾지 못하면 .end와 비교한다
즉, 찾지 못하면 null이 나오는 건가??
찾으면 위치가 나온다

즉 있는지 없는지 확인하기 위해서(in string)
npos를 이용해서 true false를 출력시킨다(?)

find_if : 인자는 string을 넣고 true를 반환하는 함수를 넣어야 한다

std::vector<item*> itemVec;
itemVec.push_back(new item(99));

while(true)
{
    auto it = std::find_if(itemVec.begin(), itemVec.end(), True에 해당하는 함수 넣기);
    if(it == itemVec.end()) break;
    //한개만 찾을때
    // 여러개 찾을 려면 it=itemVec.begin()
    // 으로 설정하고 find_if시작을 it로 받아와서 넣는다

}


for(item* pltem : itemVec)
{
    delete pltem;
}
itemVec.clear();


remove  VS   erase
remove : 뒤에것이 한칸씩 copy하고 마지막 원소는 중복이 된다 = 즉 크기 변경이 없다
erase : 이터레이터로 계산(즉, 새로운것을 만들어서 복사된다)
백터의 크기를 줄이거나 늘릴때 copy가 나타나므로 remove를 사용한다

sort는 랜덤selet가 가능해야 하므로 list에는 없다
- quit sort -> c b a or c a b
stable_sort : 삽입sort c a b (원소의 순서를 고려한다)

*/