/**
 * task a aka 52
 * link: http://informatics.mccme.ru/moodle/mod/statements/view3.php?id=206&chapterid=52#1
 * Copyright reserved.
 * author: Gumeniuk Stanislav
 */

 #include <iostream>
 #include <fstream>
 #include <stack>
 using namespace std;




 int main(void) {
	stack<int> seq;
	ifstream in("input.txt");
	char c;
	int st = 1;
	int num = 0;
	while (in.get(c)) {
		//cout << c;
		int q = (int)c;
		if ((q>=48) && (q<=57)) {
			num = num*10 + (q - 48);
			

				
		} else if (c==' ') {
			//cout << num << " ";
			seq.push(num);
			num=0; 
			
		} else if (c=='+') {
			num = seq.top();
			seq.pop();
			num += seq.top();
			seq.pop();
			//seq.push(num);
			
		} else if (c=='-') {
			num = seq.top();
			seq.pop();
			num = seq.top() - num;
			seq.pop();
			//seq.push(num);
			
		} else if (c=='*') {
			num = seq.top();
			seq.pop();
			num *= seq.top();
			seq.pop();
			//seq.push(num);
			
		}
		
		

	}
	

	in.close();

	ofstream out("output.txt");
	out << num;
	out.flush();
	out.close();
	
	 	
 	return 0;
 }