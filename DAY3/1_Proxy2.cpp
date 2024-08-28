#include <iostream>
#include <string>
#include <thread>
#include <chrono>


struct IDNS
{
	virtual std::string resolve(const std::string& url) = 0;
	virtual ~IDNS() {}
};

class DNS : public IDNS
{
public:
	std::string resolve(const std::string& url)
	{
		std::cout << "서버에 접속해서 "
			<< url << "에 대한 IP 정보 얻는중\n";

		std::this_thread::sleep_for(std::chrono::seconds(3)); // 3초대기

		return "100.100.100.100";
	}
};

// DNS 클래스를 대신 해서 사용할수 있는 "대행자(proxy)" 를 만들어 봅시다.

class DNSProxy : public IDNS
{
public:
	std::string resolve(const std::string& url)
	{
		if (url == "www.samsung.com") // local DB 에 있는 지 조사하는 코드
			return "100.100.100.100"; // 라고 가정

		// cache(local db) 에 없을 때만 DNS 클래스 사용
		DNS dns;
		return dns.resolve(url);
	}
};

int main()
{
	DNS dns;

	std::cout << dns.resolve("www.samsung.com") << std::endl;
}