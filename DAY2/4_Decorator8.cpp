int main()
{
	// Decorator ��� ���͸� ����ϸ� �ȵǳ��� ?
	FileStream fs("a.txt");
	
	fs.add_fillter(��ȣȭ ����);
	fs.add_fillter(���� ����);

	fs.write("hello");	// �Էµ� ����Ÿ��
						// �߰��� ���͵��� ���ؼ� ����Ÿ �����ϰ�
						// ȭ�鿡 ����.

}