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

#include <MDL_Reader.h>
#include <Type_Manager.h>
#include <Variable_Base.h>


class Test : public LV::Variable_Base
{
	DECLARE_VARIABLE;

private:
	int ass = 0;
	bool stuff = false;
	std::string string;

public:
	void print() const
	{
		std::cout << string << "\n" << ass << "\n" << stuff << "\n\n";
	}

};

INIT_FIELDS(Test, Variable_Base)

ADD_FIELD(int, ass, "ass");
ADD_FIELD(bool, stuff, "stuff");
ADD_FIELD(std::string, string, "string");

FIELDS_END


int main()
{
	LV::MDL_Reader reader;
	reader.parse_file("../format_test");


	LV::Type_Manager::register_type("int", {
										[](const std::string& _val)
										{
											unsigned int i=0;
											if(_val[0] == '+' || _val[0] == '-')
												++i;
											for(; i<_val.size(); ++i)
												if(_val[i] < '0' || _val[i] > '9')
													return false;
											return true;
										},
										[](void*& _variable_vptr, const LDS::Vector<std::string>& _values_as_string) { *((int*&)_variable_vptr) = std::stoi(_values_as_string[0]); },
										[](void*& _variable_vptr, void* _data_ptr) { *((int*&)_variable_vptr) = *(int*)_data_ptr; }
									});
	LV::Type_Manager::register_type("bool", {
										[](const std::string& _val)
										{
											if(_val == "true" || _val == "false")
												return true;
											return false;
										},
										[](void*& _variable_vptr, const LDS::Vector<std::string>& _values_as_string) { *((bool*&)_variable_vptr) = _values_as_string[0] == "true" ? true : false; },
										[](void*& _variable_vptr, void* _data_ptr) { *((bool*&)_variable_vptr) = *(bool*)_data_ptr; }
									});
	LV::Type_Manager::register_type("std::string", {
										[](const std::string& _val) { return true; },
										[](void*& _variable_vptr, const LDS::Vector<std::string>& _values_as_string) {
											*((std::string*&)_variable_vptr) = _values_as_string[0];
										},
										[](void*& _variable_vptr, void* _data_ptr) { *((std::string*&)_variable_vptr) = *(std::string*)_data_ptr; }
									});

	Test test;
	test.assign_values(reader.get_stub("Test_Stub"));


	reader.save_to_file("../output");

	return 0;
}
