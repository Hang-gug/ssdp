// 1_Flyweight - 167
#include <iostream>
#include <string>
#include <map>

class Image
{
	std::string image_url;

	Image(const std::string& url) : image_url(url)
	{
		std::cout << url << " Downloading..." << std::endl;
	}
public:
	void Draw() { std::cout << "Draw " << image_url << std::endl; }

	static std::map<std::string, Image*> image_map;

	// 자신의 객체를 만드는 static 멤버 함수
	static Image* Create(const std::string& url)
	{
		Image* img = nullptr;

		auto it = image_map.find(url);

		if (it == image_map.end()) // map 에 없는 경우
		{
			img = new Image(url);
			image_map[url] = img;
		}
		else
		{
			img = it->second;  // map 은 pair 보관. 
							   // first 는 key, second 는 value(Image)
		}
		return img;
	}
};

int main()
{
	Image* img1 = Image::Create("www.naver.com/a.png");
	img1->Draw();

	Image* img2 = Image::Create("www.naver.com/a.png");
	img2->Draw();

}



