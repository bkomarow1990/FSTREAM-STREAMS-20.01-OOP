#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <cstdlib>
using namespace std;
class FileWorker {
public:
	static void renameFile(const string& old_, const string& new_) {
		cout << "Code opration of rename: "<<rename(old_.c_str(), new_.c_str()) << endl;
	}
	static void createTxtFile(const string& filename){
		ofstream file(filename,ios::app);
		if (!file.is_open())
		{
			cout << "File wasn`t opened" << endl;
			return;
		}
		string line;
		
		file << line<<endl;
	
		while (!line.empty())
		{
			file << line<<endl;
			getline(cin, line);
		}
		file.close();
	}
	static void createFile(const string& filename) {
		ofstream outFile(filename);
		if (!outFile)
		{
			cerr << "Can`t to open file " << endl;
			return;
		}
		cout << "File was created" << endl;
	}

	static void showFile(const string& filename) {
		ifstream file(filename);
		if (!file)
		{
			cout << "Incorrect opening of file" << endl;
			return;
		}
		string line;
		while (getline(file,line))
		{
			cout << line << endl;
		}
		file.close();
	}

	static void deleteComments(const string& in_path, const string& out_path) {
		ifstream file(in_path);
		if (!file.good())
		{
			cout << "File open fail" << endl;
			return;
		}
		string line;
		string buffer;
		int distance=0;
		int t_it;
		vector<string>str_list;
		while (getline(file, line))
		{
		//	cout << "dd";
			buffer = "";
			for (int i = 0; i < line.size(); i++)
			{
				
				//cout << i << endl;
				if (line[i]=='/'&&line[i+1]=='/')
				{
					break;
				}
				if (line[i]=='/' && line[i+1]=='*')
				{
					t_it = i;
					while (!file.eof()) {
						if (line[t_it]=='\0')
						{
							t_it = 0;
							getline(file, line);
							distance = 0;
						}
						if (line[t_it]=='*'&& line[t_it+1]=='/')
						{
							i = t_it+1 ;
							break;
						}
						++t_it;
						
					}
					
				}
				else {
					buffer += line[i];
				}
			
			}
			if (!buffer.empty())
			{
				str_list.push_back(buffer);
			}
			
		//	cout << line << endl;
		}
	
		//ofstream file(out_path);
		for (auto& i : str_list)
		{
			cout << i << endl;
		}
		file.close();
	}
};
void stringToDouble(const string& str, double& to) {
	stringstream s(str);
	try {
		s >> to;
	}
	catch (...) {
		cerr << "Error converting" << endl;
	}

}
void doubleToString(const double &from, string& to) {
	stringstream s(to);
	try {
		s << from;
		to = s.str();
	}
	catch (...) {
		cerr << "Error converting" << endl;
	}
}
int main() {
	FileWorker::deleteComments("code.txt","ff.txt");
	FileWorker::createFile("test.dat");
	FileWorker::renameFile("test.dat", "test.cpp");
	double num = 1.24;
	cout << "Num before, is : " << num << endl;
	stringToDouble("3243.2", num);
	cout << "Num after, is : "<<num << endl;
	string newstr = "Test";
	cout << "Str before, is : " << newstr << endl;
	doubleToString(23.2,newstr);
	cout << "Str after, is : " << newstr << endl;
	return 0;
}