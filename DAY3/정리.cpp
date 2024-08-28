// 정리

// 디자인 패턴의 핵심 #1. 변하지 않은 코드에서 변하는 코드 분리

// => template method - 도형편집기 draw/draw_imp
// => strategy		  - Edit/IValidator
// => policy base design - std::vector<int, debug_alloc<int>> v;


// #2. 재귀적 포함을 위한 공통의 기반 클래스를 만드는 경우가 많다.

// composite : 재귀적 포함을 사용한 복합객체 만들기(PopupMenu/MenuItem)
// 
// decorator : 재귀적 포함을 사용한 "객체에 기능추가" ( FileStream/ZipDecorator)


// #3. 문제를 해결하기 위해서 중간층(간접층)을 만드는 경우가 많다.

// 왜? 어떤 의도를 가지고 간접층을 만들었는가에 따라 패턴의 이름이 달라집니다.


// 사용자 =========== ZipDecorator =================> FileStream
//									// 의도 : 기능의 추가
//									// "decorator"
// 
// 사용자 =========== stack  =======================> list
//									// 의도 : 인터페이스(함수이름)의 변경
//									// "adapter, adaptor"
// 
// 사용자 =========== Calc   =======================> Remote Server
//									// 의도 : 다양한 용도의 "대행자(대신사용)"
//									// "proxy"
// 
// 사용자 =========== TCPServer ====================> Socket, IPAddress....
//									// 의도 : 복잡한 절차의 단순화
//									// "facade"

// 사용자 ========== BrightCommand =================> m.set_brightness(80);
//									// 의도 : "undo 등의 기능을 추가하기 위한"
//									// command 패턴