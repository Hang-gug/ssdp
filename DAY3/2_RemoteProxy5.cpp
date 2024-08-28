#define USING_GUI
#include "cppmaster.h"


#include "ICalc.h"

int main()
{
	ICalc* calc = load_proxy();	// 1. 이순간 결국 DLL 의 create() 호출합니다.
								// 2. "new Calc" 로 생성됩니다.
								// => "delete" 가 필요 하지 않을까요 ?

	delete calc; // 이렇게 해도 될까요 ?		
				// 동적모듈(DLL) 에서 할당한 자원(new)은
				// 동적모듈(DLL) 에서 반납(delete) 해야 합니다.

				// DLL 과 exe 만들때 컴파일러가(또는 버전이) 다를수도 있습니다.
				// => 다음 단계에서 해결

}





