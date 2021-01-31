#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;
class File{
public:
	File(const string& file_path="file.txt") { setPath(file_path); };
	void setPath(const string& file_path) {
		if (file_path.empty())
		{
			return;
		}
		else {
			this->file_path = file_path;
		}
	}
	void findString(const string&yourStr)const{
		ifstream file(file_path);
		if (!file.good())
		{
			cout << "Error to open file, enter correct file_path" << endl;
			return;
		}
		int count = -1;
		string current;
		while (!file.eof())
		{
			++count;
			getline(file,current);
			
			if (current==yourStr)
			{
			
				cout << current << "\tis your string with index "<< count << endl;
				
			}
			else {
				cout << current << " \tisn`t your string , index = " << count << endl;
			
			}
		}
		file.close();
	}
	void replaceString(const string&fromString, const string& toString)const {
		ifstream file(file_path);
		vector<string> lines;
		if (!file.good())
		{
			cout << "Error to open file, enter correct file_path" << endl;
			return;
		}

		string current;
		bool have = 0;
		while (!file.eof())
		{
		
			getline(file, current);

			if (current == fromString)
			{

				cout << current << "\tis your string, will be replaced  " << endl;
				lines.push_back(toString);
				have = 1;
			}
			else {
				cout << current << " \tis not your string"  << endl;
				lines.push_back(current);

			}
	
		}
		if (have==0)
		{
			file.close();
			return;
		}

		file.close();
		ofstream outFile(file_path);
		if (!outFile.good())
		{
			cout << "Incorrect open output file" << endl;
			return;
		}
		for (auto& i : lines)
		{
			outFile << i <<endl;
		}
		outFile.close();
	}
	void reverseFile()const {
		ifstream file(file_path);
		if (!file.good())
		{
			cout << "Error open file" << endl;
			return;
		}
		string line;
		vector<string> lines;
		while (!file.eof())
		{
			getline(file, line);
			lines.push_back(line);
		}
		file.close();
		ofstream outFile(file_path);
		for (size_t i = lines.size(); 0 < i; --i)
		{
			outFile << lines[i] << endl;
		}
		outFile.close();
	}
	void print()const {
		ifstream file(file_path);
		if (!file.good())
		{
			cout << "Error to open file, enter correct file_path" << endl;
			return; 
		}
		string current;
		while (!file.eof())
		{
			getline(file,current);
			cout << current << endl;
		}
		file.close();
	}
private:
	string file_path;
};
void printMenu() {
	cout << "1. Change file_path" << endl;
	cout << "2. Find String in file" << endl;
	cout << "3. Reverese text" << endl;
	cout << "4. Replace string in file" << endl;
	cout << "5. Print file" << endl;
	cout << "0. Exit" << endl;
}
string cinString() {
	string str;
	getline(cin,str);
}
string cinString(const string& text) {
	string str;
	cout << text << endl;
	getline(cin, str);
}
int main() {
	//File testFile("testFile.txt");
	//testFile.findString("ut labore et dolore magna aliqua.");
	//cout << "Replce" << endl;
	//testFile.replaceString("ut labore et dolore magna aliqua.","REPLACED");
	//testFile.print();
	int answer;
	File file;
	file.setPath(cinString());
	while (true)
	{
		printMenu();
		cin >> answer;
		switch (answer)
		{
		case 1:
			file.setPath(cinString());
			break;
		case 2:
			file.findString(cinString());
			break;

		case 3:

		case 4:
			file.replaceString(cinString("Enter which string you need to replace..."), cinString("Enter string to replace..."));
			break;
		case 5:
			file.print();
			break;
		default:
			exit(0);
		}
	}
	return 0;
}