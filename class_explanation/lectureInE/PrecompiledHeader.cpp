// precompiled header(Pch) : 컴파일 할때 너무 시간이 너무 많이 시간이 걸리니까
// 한번 컴파일 된것을 저장해 놓아 다시 컴파일 안해도 되게 만듦
/*
Pch름 먼저 include 하고 코드를 사용해야 그 안에 include한 것들을 가져와서 사용할 수 있다
header file에 include 안해도 cpp파일에 Pch를 include 하면 됨
*/
#include <stdio.h>
#include <tchar.h>
#include "stafx.h"