#include <iostream>
#include <iomanip>
#include <map>

#include <thread>

#include <Data_Structures/Map.h>
#include <Stuff/Stopwatch.h>

struct Test
{
	std::string a;
	std::string b;
	Test(const std::string& _a, const std::string& _b) : a(_a), b(_b) { }
	Test(const std::string& _a) : a(_a) { }
	inline bool operator<(const Test& _other) const { return a < _other.a; }
	inline bool operator>(const Test& _other) const { return a > _other.a; }
	inline bool operator==(const Test& _other) const { return a == _other.a; }
};

int main()
{
	std::setprecision(5);

//	//	LDS::Map<int, int> lds_map_test;
//	LDS::AVL_Tree<Test> lds_map_test;

//	LST::Stopwatch sw;

//	sw.start();

//	for(int i=0; i<1000000; ++i)
//		//		lds_map_test.insert(i, i);
//		lds_map_test.insert({std::to_string(i), std::to_string(i)});

//	sw.stop();

//	std::cout << std::fixed << "LDS::Map::insert:\t" << sw.duration() << "\n";

//	sw.start();

//	auto ldsit = lds_map_test.find({"12481"});
//	//	auto ldsit = lds_map_test.find(12481);

//	sw.stop();

//	//	std::cout << std::fixed << "LDS::Map::find:\t\t" << sw.duration() << "\t" << (ldsit.is_ok() ? std::to_string(*ldsit) : "error") << "\n";
//	std::cout << std::fixed << "LDS::Map::find:\t\t" << sw.duration() << "\t" << (ldsit.is_ok() ? (ldsit->a) : "error") << "\n";

//	unsigned int amount = 0;

//	sw.start();

//	ldsit = lds_map_test.iterator();
//	while(!ldsit.end_reached())
//	{
//		++ldsit;
//		++amount;
//	}

//	sw.stop();

//	std::cout << std::fixed << "LDS::Map iteration:\t" << sw.duration() << "\t" << amount << "\n";

//	sw.start();

//	lds_map_test.clear();

//	sw.stop();

//	std::cout << std::fixed << "LDS::Map::clear:\t" << sw.duration() << "\n\n";




//	LDS::Map<int, int> lds_map_test;
	LDS::Map<std::string, std::string> lds_map_test;

	LST::Stopwatch sw;

	sw.start();

	for(int i=0; i<1000000; ++i)
//		lds_map_test.insert(i, i);
		lds_map_test.insert(std::to_string(i), std::to_string(i));

	sw.stop();

	std::cout << std::fixed << "LDS::Map::insert:\t" << sw.duration() << "\n";

	sw.start();

	auto ldsit = lds_map_test.find("12481");
//	auto ldsit = lds_map_test.find(12481);

	sw.stop();

//	std::cout << std::fixed << "LDS::Map::find:\t\t" << sw.duration() << "\t" << (ldsit.is_ok() ? std::to_string(*ldsit) : "error") << "\n";
	std::cout << std::fixed << "LDS::Map::find:\t\t" << sw.duration() << "\t" << (ldsit.is_ok() ? (*ldsit) : "error") << "\n";

	unsigned int amount = 0;

	sw.start();

	ldsit = lds_map_test.iterator();
	while(!ldsit.end_reached())
	{
		++ldsit;
		++amount;
	}

	sw.stop();

	std::cout << std::fixed << "LDS::Map iteration:\t" << sw.duration() << "\t" << amount << "\n";

	sw.start();

	lds_map_test.clear();

	sw.stop();

	std::cout << std::fixed << "LDS::Map::clear:\t" << sw.duration() << "\n\n";




	std::map<std::string, std::string> std_map_test;
//	std::map<int, int> std_map_test;

	sw.start();

	for(int i=0; i<1000000; ++i)
//		std_map_test.emplace(i, i);
		std_map_test.emplace(std::to_string(i), std::to_string(i));

	sw.stop();

	std::cout << std::fixed << "std::map::emplace:\t" << sw.duration() << "\n";

	sw.start();

	auto stdit = std_map_test.find("12481");
//	auto stdit = std_map_test.find(12481);

	sw.stop();

//	std::cout << std::fixed << "std::map::find:\t\t" << sw.duration() << "\t" << (stdit != std_map_test.end() ? std::to_string(stdit->second) : "error") << "\n";
	std::cout << std::fixed << "std::map::find:\t\t" << sw.duration() << "\t" << (stdit != std_map_test.end() ? (stdit->second) : "error") << "\n";

	amount = 0;

	sw.start();

	stdit = std_map_test.begin();
	while(stdit != std_map_test.end())
	{
		++stdit;
		++amount;
	}

	sw.stop();

	std::cout << std::fixed << "std::map iteration:\t" << sw.duration() << "\t" << amount << "\n";

	sw.start();

	std_map_test.clear();

	sw.stop();

	std::cout << std::fixed << "std::map::clear:\t" << sw.duration() << "\n";




//	LDS::Map<std::string, std::string> lds_map_test;

//	LST::Stopwatch sw;

//	sw.start();

//	for(int i=0; i<1000; ++i)
//		lds_map_test.insert(std::to_string(i), std::to_string(i));

//	sw.stop();

//	std::cout << std::fixed << "LDS::Map::insert:\t" << sw.duration() << "\n";

//	sw.start();

//	LDS::Map<std::string, std::string>::Iterator ldsit = lds_map_test.find("658");

//	sw.stop();

//	std::cout << std::fixed << "LDS::Map::find:\t\t" << sw.duration() << "\t" << (ldsit.is_ok() ? *ldsit : "error") << "\n";

//	sw.start();

//	lds_map_test.clear();

//	sw.stop();

//	std::cout << std::fixed << "LDS::Map::clear:\t" << sw.duration() << "\n\n";




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
