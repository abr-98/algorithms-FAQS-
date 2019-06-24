#include<bits/stdc++.h>
#include<fstream>
#include <ctype.h>
#include <vector>
#include<stdlib.h>
#include<string.h>
using namespace std;
int main()
{
	vector<char> v;
	int l;
	string line;
	int count;
	int i;
	count=1;
	ifstream out("test.txt");
	while(getline(out,line))
	{
		//l=strlen(line);
		v.clear();
		i=0;
		while(line[i]!='\0')
		{
			if(isdigit(line[i])!=0)
			{
				v.push_back(line[i]);
			}
			i++;

		}
		//cout<<"a"<<endl;
		//cout<<line<<endl;

			if(count%2!=0)
			{
				for(i=0;i<v.size();i++)
				{
					cout<<v[i]<<" ";
				}
				
			}
			else
			{
				for(i=v.size()-1;i>=0;i--)
				{
					//cout<<"a"<<endl;
					cout<<v[i]<<" ";
				}
			}
			cout<<endl;

		count++;	

		}


	}

