#include <iostream>
#include <vector>
#include <fstream>

int main(int argc, char* argv[]){
	if(argc==1){
		std::cerr<<"Too few  arguments"<<std::endl;
		return 1;
	}
	char* str=argv[1];
	std::vector<char> v;
	bool started=false;
	for(int i=0;str[i];++i){
		if(str[i]=='*'){
			std::cerr<<"No tests"<<std::endl;
			return 1;
		}
		if(str[i]=='.'){
			break;
		}
		if(started){
			v.push_back(str[i]);
		}
		if(str[i]=='/'){
			started=true;
		}
	}
	char* name=new char[v.size()];
	for(int i=0;i<v.size();++i){
		name[i]=v[i];
	}
	char c=name[0];
	name[0]=toupper(name[0]);
	std::ofstream fs1("tmp1.txt");
	std::ofstream fs2("tmp2.txt");
	std::cout<<"Creating test for "<<name<<"..."<<std::endl;
	fs1<<"#include \""<<str<<"\""<<std::endl;
	fs2<<"std::cout<<\" "<<name<<" testing...\"<<std::endl;"<<std::endl;
	name[0]=c;
	fs2<<name<<"_test();"<<std::endl;
	name[0]=toupper(name[0]);
	fs2<<"std::cout<<\" "<<name<<" OK\"<<std::endl;"<<std::endl;
	std::cout<<"Test for "<<name<<" created."<<std::endl;
	fs1.close();
	fs2.close();
}

