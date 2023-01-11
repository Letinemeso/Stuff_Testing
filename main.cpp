#include <iostream>

#include <thread>

#include <Data_Structures/Map.h>
#include <Stuff/Stopwatch.h>

int main()
{
	LDS::Map<std::string, int> map_test;

//	for(unsigned int i=0; i<10000; ++i)

//	map_test.insert("ass", 1);
//	map_test.insert("bass", 3);
//	map_test.insert("balaclava", 16);
//	map_test.insert("poui", 999);

	LST::Stopwatch sw;

	sw.start();

	std::this_thread::sleep_for(std::chrono::seconds(2));

	sw.stop();

	std::cout << sw.duration() << "\n";

	return 0;
}
