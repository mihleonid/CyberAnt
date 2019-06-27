#include <cassert>
#include "build.cpp"

#include "resourceset_test.cpp"
#include "field_test.cpp"

int main(){
	std::cout<<"CyberAnt testing..."<<std::endl;

	std::cout<<" ResourceSet testing..."<<std::endl;
	resourceset_test();
	std::cout<<" ResourceSet OK"<<std::endl;

	std::cout<<" Field testing..."<<std::endl;
	field_test();
	std::cout<<" Field OK"<<std::endl;

	std::cout<<"OK"<<std::endl;
	return 0;
}

