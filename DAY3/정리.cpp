// 정리

// 디자인 패턴의 핵심 #1. 변하지 않은 코드에서 변하는 코드 분리

// => template method - 도형편집기 draw/draw_imp
// => strategy		  - Edit/IValidator
// => policy base design - std::vector<int, debug_alloc<int>> v;


// #2. 재귀적 포함을 위한 공통의 기반 클래스를 만드는 경우가 많다.

// composite : 재귀적 포함을 사용한 복합객체 만들기(PopupMenu/MenuItem)
// 
// decorator : 재귀적 포함을 사용한 "객체에 기능추가" ( FileStream/ZipDecorator)


// #3. 

// 사용자 ==================================> FileStream
// 
// 사용자 ==================================> list
// 
// 사용자 ==================================> RemoteServer
// 
// 사용자 ==================================> Socket, IPAddress....