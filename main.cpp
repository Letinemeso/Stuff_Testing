/*#include <iostream>

#include "Type_Manager.h"

#include "Base_Types/Variable_Base.h"

#include "Variable_Manager.h"

#include "OMFL_Reader.h"

int main()
{
	Type_Manager::register_type("int",
		{
			[](void* _data_vptr){ delete (int*)_data_vptr; },
			[](void* _variable_vptr, const std::string& _value_as_string){ *(int*)_variable_vptr = std::stoi(_value_as_string); },
			[](void* _variable_vptr, void* _data_ptr){ *(int*)_variable_vptr = *(int*)_data_ptr; }
		}
	);
	Type_Manager::register_type("float",
		{
			[](void* _data_vptr){ delete (float*)_data_vptr; },
			[](void* _variable_vptr, const std::string& _value_as_string)
									{
										*(float*)_variable_vptr = std::stof(_value_as_string);
									},
			[](void* _variable_vptr, void* _data_ptr){ *(float*)_variable_vptr = *(float*)_data_ptr; }
		}
	);
	Type_Manager::register_type("bool",
		{
			[](void* _data_vptr){ delete (bool*)_data_vptr; },
			[](void* _variable_vptr, const std::string& _value_as_string)
									{
										if(_value_as_string == "true")
											*(bool*)_variable_vptr = true;
										else if(_value_as_string == "false")
											*(bool*)_variable_vptr = false;
									},
			[](void* _variable_vptr, void* _data_ptr){ *(float*)_variable_vptr = *(float*)_data_ptr; }
		}
	);
	Type_Manager::register_type("std::string",
		{
			[](void* _data_vptr){ delete (std::string*)_data_vptr; },
			[](void* _variable_vptr, const std::string& _value_as_string){ *(std::string*)_variable_vptr = _value_as_string; },
			[](void* _variable_vptr, void* _data_ptr){ *(std::string*)_variable_vptr = *(std::string*)_data_ptr; }
		}
	);

//	std::string raw =
//			"ass  = [[123]]   \n"
//			"arr = [\"text\", true, \"balaclava\"]\n"
//			"floooat = 12321.123 adasd\n"
//			"[other_section]\n"
//			"arr = [\"idioticy\"]\n"
//			"[other_section.balaclava]\n"
//			"balaclava = true\n";

	OMFL_Reader reader;

//	reader.parse(raw);
	reader.load_file("../../MDL_Parser/file");

	std::cout << reader.error_log() << "\n";

	Variable_Manager vm;
	vm.add_variables(reader);

	return 0;
}
*/

#include "Data_Structures/Vector.h"
#include <vector>

#include <iostream>
#include <chrono>

class Test
{
private:
	int* arr = nullptr;

public:
	Test()
	{
		arr = new int[10];
		for(unsigned int i=0; i<10; ++i)
			arr[i] = i;
	}

	Test(const Test& _other)
	{
		arr = new int[10];
		for(unsigned int i=0; i<10; ++i)
			arr[i] = _other.arr[i];
	}

	~Test()
	{
		delete[] arr;
	}

};

int main()
{
	std::chrono::high_resolution_clock::time_point start;
	std::chrono::high_resolution_clock::time_point end;
	std::chrono::duration<float> duration;

	//	std::vector Test

	std::vector<Test> stdvec;

	for(unsigned int i=0; i<10000000; ++i)
		stdvec.push_back({});

	start = std::chrono::high_resolution_clock::now();

	std::vector<Test>::iterator stdvit = stdvec.begin();
	while(stdvit != stdvec.end())
		++stdvit;

	end = std::chrono::high_resolution_clock::now();

	duration = end - start;
	std::cout << "std::vector:\t" << duration.count() << "\n\n";

	//	~std::vector Test


	//	LDS::Vector Test

	LDS::Vector<Test> ldsvec;

	for(unsigned int i=0; i<10000000; ++i)
		ldsvec.push({});

	start = std::chrono::high_resolution_clock::now();

	LDS::Vector<Test>::Iterator ldsvit = ldsvec.iterator();
	while(!ldsvit.end_reached())
		++ldsvit;

	end = std::chrono::high_resolution_clock::now();

	duration = end - start;
	std::cout << "LDS::Vector:\t" << duration.count() << "\n\n";

	//	~LDS::Vector Test



	return 0;
}
