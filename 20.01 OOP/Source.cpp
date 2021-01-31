#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
class FileWorker {
public:
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
			for (size_t i = 0; i < line.size(); i++)
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
int main() {
	FileWorker::deleteComments("code.txt","ff.txt");
	return 0;
}