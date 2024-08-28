// github.com/codenuri/ssdp 에서 DAY4.zip 받으시면 됩니다.
#define MAKE_SINGLETON(classname)					\
private:											\
	classname() {}									\
	classname(const classname&) = delete;			\
	classname& operator=(const classname&) = delete;\
public:												\
	static classname& get_instance()				\
	{												\
		static classname instance;					\
		return instance;							\
	}

class Cursor
{
	MAKE_SINGLETON(Cursor)
};

int main()
{
	Cursor& c = Cursor::get_instance();
}