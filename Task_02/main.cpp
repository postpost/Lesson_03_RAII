#include <iostream>

class SmartArr {
	int size;
	int* array;
	int last;

public:
	//constructor
	SmartArr(int size) {
		this->size = size;
		array = new int[size];
		last = -1;
	}

	//copy one constructor to another
	SmartArr(const SmartArr& smart)
	{
		int* new_arr = new int[smart.size];
		for (int i = 0; i < smart.size; ++i)
			new_arr[i] = smart.array[i];
		std::cout << "Constructor of copy!" << std::endl;
	}
	//operator =
	SmartArr& operator=(const SmartArr& smart) {
		if (this == &smart)
			throw std::runtime_error("Cannot use the same memory!");
		delete[] array;
		int* new_arr = new int[smart.size];
		for (int i = 0; i < smart.size; ++i) {
			new_arr[i] = smart.array[i];
		}
		array = new_arr;
		return *this;
	}

	// method to add new element
	void add_element(int el) {
		if (last >= size)
			throw std::runtime_error("Can not add new element as array size exceeded!");
		last += 1;
		array[last] = el;

	}

	//method to get element by index
	int get_element(int index) {
		if (index > last)
			throw std::runtime_error("Can not find index as array size exceeded!");
		else if (index < 0)
			throw std::runtime_error("Index is below zero!");
		return array[index];

	}
	////destructor
	~SmartArr() {
		delete[] array;
		//std::cout << "\ndestructor..." << std::endl;
	}
};




int main() {

	SmartArr arr(5);
	arr.add_element(1);
	arr.add_element(4);
	arr.add_element(155);

	SmartArr new_array(2);
	new_array.add_element(44);
	new_array.add_element(34);

	try {
		arr = new_array;
		arr = arr;
	}
	catch (std::runtime_error& ex) {
		std::cout << ex.what();
	}
	//std::cout << arr.get_element(1);

	return 0;
}
