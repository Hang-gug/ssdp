// ����

// ������ ������ �ٽ� #1. ������ ���� �ڵ忡�� ���ϴ� �ڵ� �и�

// => template method - ���������� draw/draw_imp
// => strategy		  - Edit/IValidator
// => policy base design - std::vector<int, debug_alloc<int>> v;


// #2. ����� ������ ���� ������ ��� Ŭ������ ����� ��찡 ����.

// composite : ����� ������ ����� ���հ�ü �����(PopupMenu/MenuItem)
// 
// decorator : ����� ������ ����� "��ü�� ����߰�" ( FileStream/ZipDecorator)


// #3. 

// ����� ==================================> FileStream
// 
// ����� ==================================> list
// 
// ����� ==================================> RemoteServer
// 
// ����� ==================================> Socket, IPAddress....