#define USING_GUI
#include "cppmaster.h"


#include "ICalc.h"

int main()
{
	ICalc* calc = load_proxy();	// 1. 이순간 결국 DLL 의 create() 호출합니다.
								// 2. new Calc로 생성됩니다.
								// => "delete"가 필요 하지 않을까요 ?

	delete calc; // 이렇게 해도 될까요 ?				

}





