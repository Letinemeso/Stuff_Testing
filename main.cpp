#include <iostream>
#include <thread>
#include <chrono>

#include <list>

#include "../Utility/include/Data_Structures/List.h"
#include "../Utility/include/Stuff/Stopwatch.h"


constexpr int amount = 100000000;

int main()
{
	LST::Stopwatch sw;

	//	LDS::List

	LDS::List<int> ldslist;

	sw.start();

	for(int i=0; i<amount; ++i)
		ldslist.push_back(i);

	sw.stop();

	std::cout << "LDS::List::push_back: \t" << sw.duration() << "\n";

	sw.start();

	auto ldsit = ldslist.begin();
	while(!ldsit.end_reached())
		++ldsit;

	sw.stop();

	std::cout << "LDS::List iteration: \t" << sw.duration() << "\n";

	sw.start();

	ldslist.clear();

	sw.stop();

	std::cout << "LDS::List::clear: \t" << sw.duration() << "\n";



	std::cout << "\n";

	//	std::list

	std::list<int> stdlist;

	sw.start();

	for(int i=0; i<amount; ++i)
		stdlist.push_back(i);

	sw.stop();

	std::cout << "std::list::push_back: \t" << sw.duration() << "\n";

	sw.start();

	auto stdit = stdlist.begin();
	while(stdit != stdlist.end())
		++stdit;

	sw.stop();

	std::cout << "std::list iteration: \t" << sw.duration() << "\n";

	sw.start();

	stdlist.clear();

	sw.stop();

	std::cout << "std::list::clear: \t" << sw.duration() << "\n";


	return 0;
}
