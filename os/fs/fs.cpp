#ifndef FS
	#define FS 
	#include "fs.h"
#endif



void SHOW_ERROR (const string & str) {
	throw(str);
}


int main(int argc, char* argv[]) {
	vector<string> args;
	//cout << argc;
	for (size_t i = 1; i < argc; ++i) {
			args.push_back(argv[i]);
		}

	try {

		//init
		if (argc < 3) { SHOW_ERROR ("use \"help\" for more info");}
		
		//check path

		string path = args[1];
		//cout << path ;

		//parse arg

		//cout << args[0];

		if (args[0] == "help") {
			cout << "1"<<endl;
			//help
		} else if (args[0] == "config") {
			//show config
			cout << "2"<<endl;
		} else if (args[0] == "init"){
			myfs *fs = new myfs();
			fs->init();
		}

		else {
			cout << "use \"help\" for more info" << endl;
		}



	} catch (const string& str) {
        cerr << str << "\n";
        return 1;
    }

	return 0;
}