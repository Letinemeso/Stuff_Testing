#include <iostream>
#include <iomanip>

#include <thread>

#include <Data_Structures/Map.h>
#include <Stuff/Stopwatch.h>

int main()
{
	LDS::Map<int, std::string> lds_map_test;

//	for(unsigned int i=0; i<10000; ++i)

//	lds_map_test.insert("ass", 1);
//	lds_map_test.insert("bass", 3);
//	lds_map_test.insert("balaclava", 16);
//	lds_map_test.insert("poui", 999);

	std::setprecision(3);


	LST::Stopwatch sw;

	sw.start();

	for(unsigned int i=0; i<10000; ++i)
		lds_map_test.insert(i, std::to_string(i));

	sw.stop();

	std::cout << std::fixed << "LDS::Map::insert:\t" << sw.duration() << "\n";

	std::map<int, std::string> std_map_test;

	sw.start();

	for(unsigned int i=0; i<10000; ++i)
		std_map_test.emplace(i, std::to_string(i));

	sw.stop();

	std::cout << std::fixed << "std::map::emplace:\t" << sw.duration() << "\n";


	sw.start();

	lds_map_test.clear();

	sw.stop();

	std::cout << std::fixed << "LDS::Map::clear:\t" << sw.duration() << "\n";


	sw.start();

	std_map_test.clear();

	sw.stop();

	std::cout << std::fixed << "std::map::clear:\t" << sw.duration() << "\n";



	return 0;
}
