/*
하위클래스에 정의 된 객체를 (부모, 자식)
부모속에 있는 것을 함수 이름은 같으나 안의 내용을 바꾼것(재정의)

부모타입으로 만들어진 Vector/Array에 자식들을 넣고 
Vector/Array[i]로 오버라이딩 한것들을 실행하면 부모타입으로 실행된다. (vlaue만 복사했기 때문에)
그래서 그냥 넣지 않고 pointer를 넣느다(즉, 참조를 넣는다)

pointer 만들때
타입* 이름 = new 타입();

pointer에서 함수 사용시
이름->함수이름();
Vecter이름[index]->함수이름()

printf_s할 때 stirng 타입인 경우 Vecter이름[index]->함수이름().c_str() 맨뒤에 이거 붙여줘야 함

*/