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
	//prohibit copy constructor and operator =
	SmartArr(const SmartArr&) = delete;
	SmartArr& operator =(const SmartArr&) = delete;

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
	}
};

int main() 
{
	try {
		SmartArr arr(5);
		arr.add_element(1);
		arr.add_element(4);
		arr.add_element(155);
		arr.add_element(14);
		arr.add_element(15);
		//arr.add_element(77);
		std::cout << arr.get_element(1) << std::endl;
	}
	catch (const std::runtime_error& ex) {
		std::cout << ex.what() << std::endl;
	}
}
