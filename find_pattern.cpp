#include<bits/stdc++.h>
#include<vector>
using namespace std;

int main()
{
	int l;
	cout<<"enter the length of the array"<<endl;
	cin>>l;
	char ch[l];
	cout<<"Enter the characters"<<endl;
	int i,j;
	i=0;
	int p;
	p=l;
	while(i<l)
	{
		
		cin>>ch[i];
		//cout<<ch<<" ";
		i++;
	}
	char cur,prev,prev_2;
	if(l<4)
	{
		cout<<"False"<<endl;
	}
	i=0;
	//vector<string> v;
	vector<int> v;
	vector<char> num;
	while(i<l)
	{	
		num.clear();
		if (ch[i]!=',')
		{
			while(ch[i]!=',')
			{
				num.push_back(ch[i]);
				i++;
			}
			string s(num.begin(),num.end());
			//num.push_back('\0');
			//cout<<s<<endl;
			v.push_back(stoi(s));
		}
		i++;
	}
	i=2;
	int flag;
	flag=0;
	while(i<v.size())
	{
		if(v[i-2]+v[i-1]==v[i])
		{
			flag=1;
			break;
		}
		i++;
	}
	if(flag==1)
	{
		cout<<"True"<<endl;

	}
	else
	{
		cout<<"False"<<endl;
	}
}	
