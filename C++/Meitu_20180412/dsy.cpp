#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<vector<int> > image;
	string s;
	int n;
	
	getline(cin, s);
	n = (int) (s.size() + 1) / 2;
	vector<int> row;
	
	for (int i=0; i<s.size(); i++)
	{
		if (s[i] != ' ')
		{
			row.push_back(s[i] - '0');
		}
	}
	
	image.push_back(row);
	
	for (int i = 0; i < n - 1; i++)
	{
		getline(cin, s);
		row.clear();
	 
		for (int i=0;i<s.size();i++)
		{
			if (s[i] != ' ')
			{
	       	row.push_back(s[i] - '0');
	    	}
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
