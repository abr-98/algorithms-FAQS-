#include<bits/stdc++.h>
#include<vector>
#include<string.h>
#define ll long long int
using namespace std;
string url(ll n)
{
	string total="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
	int mod;


	string url_t;
	url_t="";
	while(n)
	{
		//cout<<"A"<<endl;
		mod=n%62;
		n=n/62;
		url_t=url_t+total[mod];

	}

	reverse(url_t.begin(),url_t.end());
	return url_t;
}

ll url_to_id(string n)
{	
	ll id;
	id=0;
	for(int i=0;i<n.length();i++)
	{
		if ('a'<=n[i] && n[i]<='z')
		
		  id = id*62 + n[i] - 'a'; 
        if ('A' <= n[i] && n[i] <= 'Z') 
          id = id*62 + n[i] - 'A' ; 
        if ('0' <= n[i] && n[i] <= '9') 
          id = id*62 + n[i] - '0'; 
		
	}
	return id;
}

int main()
{
	ll n;
	cout<<"Enter the id"<<endl;
	cin>>n;

	string u;
	u=url(n);

	ll p;
	p=url_to_id(u);
	cout<<"The url is "<<u<<endl;
	cout<<"The id is "<<p<<endl;
}