#include <iostream>
#include <iomanip>
#include <map>

#include <thread>

#include <functional>

#include <Data_Structures/Map.h>
#include <Data_Structures/Vector.h>
#include <Stuff/Stopwatch.h>

#include <Stuff/Function_Wrapper.h>


int main()
{
    LDS::Vector<int> vec;

    vec.resize(200);

    for(int i=0; i<50; ++i)
        vec.push(i);

    vec[150] = 999;

    for(unsigned int i=0; i<50; ++i)
        std::cout << vec[i] << "\n";

    std::cout << vec[150] << "\n";

	return 0;
}
