#include <MDL_Reader.h>
#include <Type_Manager.h>
#include <Variable_Base.h>


class Child : public LV::Variable_Base
{
    DECLARE_VARIABLE;

public:
    std::string value;

};

INIT_FIELDS(Child, Variable_Base)

ADD_FIELD(std::string, value);

FIELDS_END


class Test : public LV::Variable_Base
{
	DECLARE_VARIABLE;

private:
	int* arr = nullptr;
	int arr_size = 0;

    Child child;

public:
	Test()
	{
	}

	void print() const
    {
        std::cout << "Child: " << child.value << "\n";

		for(unsigned int i=0; i<(unsigned int)arr_size; ++i)
			std::cout << arr[i] << " ";
		std::cout << "\n\n";
	}

};

INIT_FIELDS(Test, Variable_Base)

ADD_FIELD(int*, arr);
ADD_FIELD(int, arr_size);

ADD_CHILD(child);

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
										[](void* _variable_vptr, const LDS::Vector<std::string>& _values_as_string) { *((int*)_variable_vptr) = std::stoi(_values_as_string[0]); }
									});
	LV::Type_Manager::register_type("bool", {
										[](const std::string& _val)
										{
											if(_val == "true" || _val == "false")
												return true;
											return false;
										},
										[](void* _variable_vptr, const LDS::Vector<std::string>& _values_as_string) { *((bool*&)_variable_vptr) = _values_as_string[0] == "true" ? true : false; }
									});
	LV::Type_Manager::register_type("std::string", {
										[](const std::string& _val) { return true; },
										[](void* _variable_vptr, const LDS::Vector<std::string>& _values_as_string) {
											*((std::string*)_variable_vptr) = _values_as_string[0];
										}
									});
	LV::Type_Manager::register_type("int*", {
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
										[](void* _variable_vptr, const LDS::Vector<std::string>& _values_as_string)
										{
											int** var_ptr_ptr = (int**)_variable_vptr;

											if(*var_ptr_ptr == nullptr)
												*var_ptr_ptr = new int[_values_as_string.size()];

											int* var_ptr = *var_ptr_ptr;

											for(unsigned int i=0; i<_values_as_string.size(); ++i)
												var_ptr[i] = std::stoi(_values_as_string[i]);
										}
									});


	Test test;
	test.assign_values(reader.get_stub("Test_Stub"));
	test.print();

    Child child;
    child.assign_values(reader.get_stub("Test_Child"));
    std::cout << child.value << "\n";

	reader.save_to_file("../output");

	return 0;
}
