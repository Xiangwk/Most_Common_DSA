#include "Vector.h"
#include <string>
#include <iostream>

int main()
{
	std::cout << "Test construct and destruct:\n" << std::endl;
	dsa::Vector<std::string> vsEmpty;
	dsa::Vector<int> viOrigin(10);
	dsa::Vector<std::string> vsOrigin{ };

	std::cout << "\tEmpty Vector: " << std::endl;
	std::cout << "\tSize: " << vsEmpty.size() << std::endl;
	std::cout << "\tCapacity: " << vsEmpty.capacity() << std::endl;
	std::cout << "\tvsEmpty: ";
	for (auto iter = vsEmpty.begin(); iter != vsEmpty.end(); ++iter)
		std::cout << *iter << " ";
	std::cout << std::endl << std::endl;

	std::cout << "\tInt Vector with value initilize: " << std::endl;
	std::cout << "\tSize: " << viOrigin.size() << std::endl;
	std::cout << "\tCapacity: " << viOrigin.capacity() << std::endl;
	std::cout << "\tviOrigin: ";
	for (auto iter = viOrigin.begin(); iter != viOrigin.end(); ++iter)
		std::cout << *iter << " ";
	std::cout << std::endl << std::endl;

	std::cout << "\tString Vector by initialize_list construction: " << std::endl;
	std::cout << "\tSize: " << vsOrigin.size() << std::endl;
	std::cout << "\tCapacity: " << vsOrigin.capacity() << std::endl;
	std::cout << "\tvsOrigin: ";
	for (auto iter = vsOrigin.begin(); iter != vsOrigin.end(); ++iter)
		std::cout << *iter << " ";
	std::cout << std::endl << std::endl;

	std::cout << "Test copy operation:\n" << std::endl;
	dsa::Vector<int> viCopy(viOrigin);
	dsa::Vector<std::string> vsCopy(vsOrigin);
	
	std::cout << "\tInt Vector by copy construction from vsOrgin: " << std::endl;
	std::cout << "\tSize: " << viCopy.size() << std::endl;
	std::cout << "\tCapacity: " << viCopy.capacity() << std::endl;
	std::cout << "\tviCopy: ";
	for (auto iter = viCopy.begin(); iter != viCopy.end(); ++iter)
		std::cout << *iter << " ";
	std::cout << std::endl << std::endl;

	std::cout << "\tString Vector by copy construction from vsOrigin: " << std::endl;
	std::cout << "\tSize: " << vsCopy.size() << std::endl;
	std::cout << "\tCapacity: " << vsCopy.capacity() << std::endl;
	std::cout << "\tvsCopy: ";
	for (auto iter = vsCopy.begin(); iter != vsCopy.end(); ++iter)
		std::cout << *iter << " ";
	std::cout << std::endl << std::endl;

	vsCopy = vsEmpty;
	std::cout << "\tString Vector by copy assignment from vsEmpty: " << std::endl;
	std::cout << "\tSize: " << vsCopy.size() << std::endl;
	std::cout << "\tCapacity: " << vsCopy.capacity() << std::endl;
	std::cout << "\tvsCopy: ";
	for (auto iter = vsCopy.begin(); iter != vsCopy.end(); ++iter)
		std::cout << *iter << " ";
	std::cout << std::endl << std::endl;

	std::cout << "Test push_back() and pop_back()\n" << std::endl;
	vsCopy.push_back("bupt");
	vsCopy.push_back("ipoc");
	vsCopy.push_back("osg");
	vsCopy.push_back("znb");
	std::cout << "\tString Vector by push_back() " << std::endl;
	std::cout << "\tSize: " << vsCopy.size() << std::endl;
	std::cout << "\tCapacity: " << vsCopy.capacity() << std::endl;
	std::cout << "\tvsCopy: ";
	for (auto iter = vsCopy.begin(); iter != vsCopy.end(); ++iter)
		std::cout << *iter << " ";
	std::cout << std::endl << std::endl;

	vsCopy.pop_back();
	std::cout << "\tString Vector by pop_back() " << std::endl;
	std::cout << "\tSize: " << vsCopy.size() << std::endl;
	std::cout << "\tCapacity: " << vsCopy.capacity() << std::endl;
	std::cout << "\tvsCopy: ";
	for (auto iter = vsCopy.begin(); iter != vsCopy.end(); ++iter)
		std::cout << *iter << " ";
	std::cout << std::endl << std::endl;

	std::cout << "Test resize() and reserve()\n" << std::endl;
	vsCopy.resize(2);
	std::cout << "\tSize: " << vsCopy.size() << std::endl;
	std::cout << "\tCapacity: " << vsCopy.capacity() << std::endl;
	std::cout << "\tvsCopy: ";
	for (auto iter = vsCopy.begin(); iter != vsCopy.end(); ++iter)
		std::cout << *iter << " ";
	std::cout << std::endl << std::endl;
	vsCopy.resize(10);
	std::cout << "\tSize: " << vsCopy.size() << std::endl;
	std::cout << "\tCapacity: " << vsCopy.capacity() << std::endl;
	std::cout << "\tvsCopy: ";
	for (auto iter = vsCopy.begin(); iter != vsCopy.end(); ++iter)
		std::cout << *iter << " ";
	std::cout << std::endl << std::endl;
	vsCopy.reserve(50);
	std::cout << "\tSize: " << vsCopy.size() << std::endl;
	std::cout << "\tCapacity: " << vsCopy.capacity() << std::endl;
	std::cout << "\tvsCopy: ";
	for (auto iter = vsCopy.begin(); iter != vsCopy.end(); ++iter)
		std::cout << *iter << " ";
	std::cout << std::endl << std::endl;

	//vsEmpty.pop_back();

	return 0;
}