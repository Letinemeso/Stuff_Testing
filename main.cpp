#include <iostream>
#include <iomanip>
#include <map>

#include <thread>

#include <Data_Structures/Map.h>
#include <Stuff/Stopwatch.h>


int main()
{

	LDS::Map<std::string, int> lds_map_test;

	std::setprecision(3);

	LST::Stopwatch sw;

	sw.start();

	for(int i=0; i<100000; ++i)
		lds_map_test.insert(std::to_string(i), i);

	sw.stop();

	std::cout << std::fixed << "LDS::Map::insert:\t" << sw.duration() << "\n";

	sw.start();

	LDS::Map<std::string, int>::Iterator ldsit = lds_map_test.find("1000000");

	sw.stop();

	std::cout << std::fixed << "LDS::Map::find:\t" << sw.duration() << "\n";

	sw.start();

	lds_map_test.clear();

	sw.stop();

	std::cout << std::fixed << "LDS::Map::clear:\t" << sw.duration() << "\n\n";

	std::map<std::string, int> std_map_test;

	sw.start();

	for(int i=0; i<100000; ++i)
		std_map_test.emplace(std::to_string(i), i);

	sw.stop();

	std::cout << std::fixed << "std::map::emplace:\t" << sw.duration() << "\n";

	sw.start();

	std::map<std::string, int>::iterator stdit = std_map_test.find("1000000");

	sw.stop();

	std::cout << std::fixed << "std::map::find:\t" << sw.duration() << "\n";


	sw.start();

	std_map_test.clear();

	sw.stop();

	std::cout << std::fixed << "std::map::clear:\t" << sw.duration() << "\n";


//	while(true)
//	{
//		LDS::Map<int, std::string> map;
//		for(int i=0; i<100000; ++i)
//			map.insert(i, std::to_string(i));
//		map.clear();
//		std::this_thread::sleep_for(std::chrono::milliseconds(100));
//	}


	return 0;
}
