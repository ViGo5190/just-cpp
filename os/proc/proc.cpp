#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <map>
#include <set>
#include <dirent.h>
 

using namespace std;


class Proc {
	public:
	string name;
	set<int> child;
};

map <int, Proc> proctree;

void printtree (int pid, int w=0) {
	if (proctree[pid].name.empty()) { return ;}
	cout << "*";
	cout << setw(5*w) << setfill('-') << ">";
	cout << pid << " " << proctree[pid].name  << endl;
	Proc thisproc = proctree[pid];
	proctree.erase(pid);
	for (set<int>::iterator i = thisproc.child.begin(); i != thisproc.child.end(); ++i) {
		printtree(*i, w+1);
	}
}

int main(void) {
	DIR *procdir = opendir("/proc");
	struct dirent *thisdir;
	while ( ( thisdir = readdir(procdir)) != NULL ) {
		//cout << thisdir->d_name << endl;
		//cout << atoi(thisdir->d_name) << endl;
		
		
		if (atoi(thisdir->d_name) > 0 ) {
			int pid;// = atoi(thisdir->d_name);
			int ppid;
			//cout << pid << endl;
			char name[100];
			char buff[1024];
			char litle[100];
			sprintf(buff, "/proc/%s/stat",thisdir->d_name);
			ifstream in(buff);
			in >> pid;
			in >> name;
			//name = substr(name,1, strlen(name)-1);
			in >> litle;
			in >> ppid;
			//cout << pid << name << ppid << endl;

			proctree[pid].name = name;
			proctree[ppid].child.insert(pid);


			

		}
		 
		/*
		if ( (thisdir->d_name[0] >= '0') &&  ((thisdir->d_name[0] <= '9')) ) {
			//cout << atoi(thisdir->d_name) << endl;	
			int pid = atoi(thisdir->d_name);
		}
		*/
		
	}
	//cout << readdir(dir);

	closedir(procdir);

	for (map<int, Proc>::iterator i = proctree.begin(); i != proctree.end(); ++i) {
		printtree(i->first);
	}
}