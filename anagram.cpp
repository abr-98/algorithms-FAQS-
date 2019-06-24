#include<bits/stdc++.h>
#include<vector>
#include<stdio.h>
using namespace std;
int main()
{
	string s1;
	string s2;
	cout<<"Enter the first string"<<endl;
	cin>>s1;
	cout<<"Enter the second string"<<endl;
	cin>>s2;
	vector<char> v1;
	vector<char> v2;
	int i;
	i=0;
	if(s1.length()==s2.length())
	{
		while(s1[i]!='\0')
		{
			v1.push_back(s1[i]);
			v2.push_back(s2[i]);
			i++;
		}

	}
	else
	{
		cout<<"Not anagram"<<endl;
		return 0;
	}
	sort(v1.begin(),v1.end());
	sort(v2.begin(),v2.end());
	int flag;
	flag=0;
	i=0;
	while(i<v1.size())
	{
		if (v1[i]!=v2[i])
		{
			flag=1;
			break;
		}
		i++;

	}
	if (flag==1)
	{
		cout<<"NOt anagram"<<endl;
	}
	else
	{
		cout<<"Anagram"<<endl;
	}


}