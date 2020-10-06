#include<iostream>
using namespace std;
void error(const string& msg) {
    cerr << "Error:\n  " << msg << endl;
}
void usage(const string& cmd)	
{
	string opt[]={
		"where\n" ,
		" -h host      the host name.\n",
		" -v guests   the guests name.\n",
	};
	cout << "Usage:" << endl;
	cout << "  " << "Welcome" << " -h host -v guests\n";
	for(int i=0; i<(sizeof(opt))/(sizeof(string)); i++)
	{
		cout << opt[i];
	}
	exit(-1);
}
void welcome(const string& host, const string& guests) 
	{
		cout<<"Hello "<<guests<<".\n";
		cout<<"This is " << host<<"'s home, Welcome."<<endl;    
	}
int main(int argc, char* argv[]) 
{
	string host;
	string guests;
	string arg;
	if (argc == 3)
	{	
		arg =argv[2];	
		if(arg == "-?")
		{			
			usage(argv[0]);
		}			
		else 
		{
			error("Wrong number of parameters.");
			usage(argv[0]);
		}
	}
	else if (argc> 6 || argc <6)
	{	
		error("Wrong number of parameters.");
		usage(argv[0]);
	}
	for(int i=2; i<argc; i=i+2)
	{
		arg =argv[i];
		if(arg == "-h")
		{
			host = argv[i + 1];		
		}
		else if(arg == "-v")
		{
			guests = argv[i + 1];
		}
		else
		{	
			error("Unknown options: " + arg);
			usage(argv[0]);
		}
	}
	welcome(host, guests);
	return 0;
}
