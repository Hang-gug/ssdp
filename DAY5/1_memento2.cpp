// 8_메멘토 - 178
#include <iostream>
#include <vector>
#include <map>


class Graphics
{
	int penWidth = 1;
	int penColor = 0;
	int temporary_data;

	// 저장할 필요가 있는 데이타만 별도의 타입으로 설계
	struct Memento
	{
		int width;
		int color;

		Memento(int w, int c) : width(w), color(c) {}
	};

	std::map<int, Memento*> memento_map;

public:
	int Save()
	{
		static int key = 0;
		++key;
		Memento* m = new Memento(penWidth, penColor);
		memento_map[key] = m;
		return key;
	}

	void Restore(int key)
	{
		auto it = memento_map.find(key);

		if (it != memento_map.end())
		{
			penWidth = it->second->width;
			penColor = it->second->color;
		}
	}


	void DrawLine(int x1, int y1, int x2, int y2)
	{
	}
	void SetStrokeColor(int c) { penColor = c; }
	void SetStrokeWidth(int w) { penWidth = w; }
};

int main()
{
	Graphics g;

	g.SetStrokeColor(0);
	g.SetStrokeWidth(10);
	g.DrawLine(0, 0, 100, 100);
	g.DrawLine(0, 0, 200, 200); 

	int token = g.Save(); // memento 패턴
						  // => 객체가 스스로 저장했다가 복구할수 있게 한다.
						  // => 캡슐화를 위해 하지 않고도 객체의 상태저장

	g.SetStrokeColor(1);
	g.SetStrokeWidth(20);
	g.DrawLine(0, 0, 300, 300);
	g.DrawLine(0, 0, 400, 400);

	// 처음에 그렸던 선과 동일 한 속성으로 그리고 싶다.
	g.Restore(token);
}

// undo 를 구현할수 있는 2가지 방법

// memento : 객체 저장에 의한 undo, 객체크기가 큰 경우 메모리 증가
// command : 동작의 취소에 의한 undo








