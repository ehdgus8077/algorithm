#include<iostream>
#include<fstream>
#include<string>

using namespace std;

char change(string str) {
	if (str.compare(".-")==0)
		return 'A';
	if (str.compare("-...")==0)
		return 'B';
	if (str.compare("-.-.") == 0 )
		return 'C';
	if (str.compare("-..") == 0)
		return 'D';
	if (str.compare(".") == 0)
		return 'E';
	if (str.compare("..-.") == 0)
		return 'F';
	if (str.compare("--.") == 0)
		return 'G';
	if (str.compare("....") == 0)
		return 'H';
	if (str.compare("..") == 0)
		return 'I';
	if (str.compare(".---") == 0)
		return 'J';
	if (str.compare("-.-") == 0)
		return 'K';
	if (str.compare(".-..") == 0)
		return 'L';
	if (str.compare("--") == 0)
		return 'M';
	if (str.compare("-.") == 0)
		return 'N';
	if (str.compare("---") == 0)
		return 'O';
	if (str.compare(".--.") == 0)
		return 'P';
	if (str.compare("--.-") == 0)
		return 'Q';
	if (str.compare(".-.") == 0)
		return 'R';
	if (str.compare("...") == 0)
		return 'S';
	if (str.compare("-") == 0)
		return 'T';
	if (str.compare("..-") == 0)
		return 'U';
	if (str.compare("...-") == 0)
		return 'V';
	if (str.compare(".--") == 0)
		return 'W';
	if (str.compare("-..-") == 0)
		return 'X';
	if (str.compare("-.--") == 0)
		return 'Y';
	if (str.compare("--..") == 0)
		return 'Z';
}
int main() {
	 ifstream inStream;
   int numTestCases;
   inStream.open("input.txt");
   inStream >> numTestCases;
	while (numTestCases--) {
		string str;
		inStream >> str;
		int front= 0, count = 0;
		for (int i = 0;i < str.size();i++) {
			if (str[i] == '|') {
				cout<<change(str.substr(front,count));
				front = i + 1;
				count = 0;
			}
			else if (str[i] == '#') {
                cout<<change(str.substr(front,count))<<"_";
				front = i + 1;
				count = 0;
			}
			else {
				count++;
			}
		}
		cout<<change(str.substr(front,count))<<endl;
	}
	return 0;
}
