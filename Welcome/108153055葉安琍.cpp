#include <iostream>
 
 using namespace std;
 
 int main(int argc, char *argv[])
 {
 	if(argc <3||argc >3)
 	{
 		cout<<"usage="<<endl;
 		cout<<"    "<<argv[0]<<"host"<<endl;
	 }
	else{
		cout<<"Hello, "<<argv[1]<<"."<<endl;
		cout<<argv[2]<<"Welcome"<<argv[1]<<endl;
	}
	return 0;
 }
 
