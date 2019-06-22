#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>
#include <chrono>
#include <time.h>

using namespace std;
using namespace chrono;
int main()
{
	auto start = system_clock::now();

	int size_array = 0;
	vector<string> a;
	ifstream file("text2.txt");
	string s;
	while (file >> s)
	{
		a.push_back(s);
	}
	vector<vector<string>> table;
	vector<string> col;
	for (int i = 0; i < a.size();)
	{
		col.push_back(a[0]);
		for (int j = 1; j < a.size(); j++)
		{
			if (a[j] == a[0])
			{
				col.push_back(a[j]);
				a.erase(a.begin() + j);
				j--;
			}
		}
		table.push_back(col);
		col.clear();
		a.erase(a.begin());
	}

	int col_count = table.size(); 
	vector<int> ele_count;
	int temp = 0;
	for (int i = 0; i < col_count; i++)
	{
		temp = table[i].size();
		ele_count.push_back(temp);
	}


	vector<vector<string>> table_temp;
	int biggest;
	while(ele_count.size()>0)
	{
		biggest = std::distance(ele_count.begin(),max_element(ele_count.begin(), ele_count.end()));
		table_temp.push_back(table[biggest]);
		ele_count.erase(ele_count.begin()+biggest);
		table.erase(table.begin() + biggest);
	}

	cout << "table2: " << endl << endl;
	vector<vector<string>>::iterator vec_it2;
	for (vec_it2 = table_temp.begin(); vec_it2 != table_temp.end(); vec_it2++)
	{
		vector<string>::iterator it2;
		for (it2 = (*vec_it2).begin(); it2 != (*vec_it2).end(); it2++)
		{
			cout << *it2 << " ";
		}
		cout << endl;
	}

	auto end = system_clock::now();
	auto duration = duration_cast<microseconds>(end - start);
	cout << endl << "time cost: " << double(duration.count()) << " microseconds" << endl;

	
	system("pause");

}