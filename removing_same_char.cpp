#include<bits/stdc++.h>
#include<iostream>
#include<stdio.h>
#include<cstdio>
#include<stdlib.h>
#define MAX 256
using namespace std;
string remove(string s)
{
	int maintain[MAX]={0};
	int l;
	l=s.length();

	string re;
	re="";
	for(int i=0;i<l;i++)
	{
		if (maintain[s[i]]==0)
		{
			re=re+s[i];
			maintain[s[i]]=1;
		}
	}
	return re;
}

int main()
{
	char k[1000];
	cout<<"Enter the string"<<endl;
	fgets(k,1000,stdin);
	int le;
	le=strlen(k);
	k[le]='\0';
	string p;
	p=k;
	string l;
	l=remove(p);

	cout<<l<<endl;

}