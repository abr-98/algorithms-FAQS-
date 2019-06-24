#include<bits/stdc++.h>
//#include<iostream.h>
#include<vector>
using namespace std;
int main()
{
	double nu;
	double de;
	int length;
	cout<<"Enter the Numerator and the Denominator"<<endl;
	cin>>nu>>de;
	double q;
	q=nu/de;
	//cout<<q<<endl;
	string s;
	s=to_string(q);
	cout<<s<<endl;
	length=s.length();
	int index;
	index=s.find('.');
	int l;
	string dec=s.substr(index+1,length-1);
	//cout<<dec<<endl;
	l=dec.length();
	string rep;
	string rep_2;
	rep_2="";
	int len_2;
	len_2=0;
	rep=dec[0];
	int i;
	int f_rep;
	int flag;
	flag=0;
	f_rep=0;
	int len;
	len=1;
	i=1;
	while(i<dec.length())
	{
		if(rep[len_2]!=dec[i])
		{
			if (len_2!=0)
			{
				rep=rep+rep_2;
				rep_2="";
				len_2=0;
			}
			rep=rep+dec[i];
			len++;
			//cout<<"b"<<endl;
		//	cout<<rep<<endl;
		}
		else
		{
			rep_2=rep_2+dec[i];

			len_2++;
			// /cout<<"a"<<endl;
			//cout<<rep_2<<endl;
			if(len==len_2)
			{
				//cout<<"A"<<endl;
				if (2*len==dec.length())
				{	flag=1;
					break;
				}
				else{	
					//cout<<"B"<<endl;
					//cout<<dec[2*(len)]<<endl;
					if (dec[2*(len)]==rep[0])
					{
						//cout<<"c"<<endl;
						flag=1;
						break;
					}
			}
			}


		}
		i++;
	}
	if (flag==1)
	{
		cout<<rep<<endl;

	}
	else
	{
		cout<<"No pattern"<<endl;
	}

}