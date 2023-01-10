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
