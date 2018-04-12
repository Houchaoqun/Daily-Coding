#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int main()
{
	vector<vector<int> > image;
	string s;
	string temp;
	int n = 0;
	vector<int> row;

	getline(cin, s);
	stringstream str_split(s);
	
	while(getline(str_split, temp, ' ')){
		// convert str to digit
		stringstream str2digit;
		int str2num;
		str2digit << temp;
		str2digit >> str2num;
		
	 	row.push_back(str2num);
        n++;  
    }
	
	image.push_back(row);
	
	for (int i = 0; i < n - 1; i++)
	{
		getline(cin, s);
		row.clear();
		stringstream str_split(s);
		
		while(getline(str_split, temp, ' ')){
			
			// convert str to digit
			stringstream str2digit;
			int str2num;
			str2digit << temp;
			str2digit >> str2num;
			
		 	row.push_back(str2num);
	    }
	 
		image.push_back(row);
	}
	
	for (int i = 0; i < n; i++)
	{
		for (int j = n - 1; j >= 0; j--)
		{
	    	cout << image[j][i] << ' ';
		}
	 
		cout << endl;
	}
	
	return 0;
}
