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

	//copy of one constructor to another
	SmartArr(const SmartArr& smart) :
		size(smart.size), array(smart.array), last(smart.last) 
	{
		//std::cout << "Constructor of copy!" << std::endl;
	}

	// method to add new element
	void add_element(int el) {
		last += 1;
		array[last] = el;
		if (last >= size)
			throw std::exception("Can not add new element as array size exceeded!");
	}

	//method to get element by index
	int get_element(int index) {
		return array[index];
		if (index > last)
			throw std::exception("Can not find index as array size exceeded!");
	}
	////destructor
	~SmartArr() {
		delete[] array;
		//std::cout << "\ndestructor..." << std::endl;
	}
};




int main() {

	{SmartArr arr(5);
	arr.add_element(1);
	arr.add_element(4);
	arr.add_element(155); }

	SmartArr new_array(2);
	new_array.add_element(44);
	new_array.add_element(34);

	SmartArr arr{new_array};
	//std::cout << arr.get_element(1);

	return 0;
}
