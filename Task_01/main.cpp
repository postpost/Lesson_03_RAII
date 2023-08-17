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

	//void add_element(int el) {
	//	int log_size = size, act_size = size;
	//	if (log_size < act_size)
	//		last += 1;
	//	if (log_size >= act_size)
	//	{
	//		//create new array
	//		int* new_arr = new int[act_size * 2] {0};
	//		for (int i = 0; i < act_size; ++i) {
	//			new_arr[i] = array[i];
	//		}
	//		array = new_arr;
	//		last += 1;
	//		act_size *= 2;
	//	}
	//	array[last] = el;
	//	log_size += 1;
	//}
	// method to add new element
	void add_element(int el) {
		last += 1;
		array[last] = el;
		if (last >= size)
			throw std::exception ("Can not add new element as array size exceeded!");
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
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}
}
