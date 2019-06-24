#include<bits/stdc++.h>
#include<string.h>
using namespace std;
int main()
{
	int num;
	cin>>num;
	//cout<<num;



	string s;
	s=to_string(num);
	vector<string> name;
	//cout<<s;

	string tens_one[10]={"ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"};
	string tens_el[10]={"","","twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"};
	string mile[11]={"","","","hundred","thousand","thousand","lakh","lakh","crore","crore"};
	string ones[10]={"","one","two","three","four","five","six","seven","eight","nine"};
	string zero="zero";
	string code;
	int i,l,count;
	char n;
	i=0;
	i=s.length()-1;
	l=1;
	count=1;
	//cout<<"s";/*
	if(s.length()==0)
	{
		cout<<"empty string"<<endl;
		return 0;
	}
	if(s.length()==1)
	{	
		cout<<"s"<<endl;
		//cout<<int(s[s.length()-1])<<endl;}
	
		if(s[s.length()-1]=='0')
		{ 
			cout<<zero<<endl;
			return 0;
		}
		else
		{
			//cout<<"a"<<endl;
			cout<<ones[int(s[0])-int('0')];
			return 0;
		}
	}

	while(i>=0)
	{
		n=s[i];				//count=1 ,i=3 n=5 l=2
		if((count%2==0) and count>3)
		{
			l=1;
		}
		if(l==1)
		{
			if(s[i-1]=='1')
			{
				if((count>3) )
				{
					name.push_back(mile[count]);
				}
				name.push_back(tens_one[int(n)-int('0')]);
				
				i-=2;
				l+=2;
				count+=2;
				continue;
			}
			if((count>3) )
				{
					name.push_back(mile[count]);
				}		//fivr
			l++;
			name.push_back(ones[int(n)-int('0')]);

			count++;
			i--;
		}
		else if(l==2)
		{
			/*if((s.length()%2!=0) && (count>3))
			{
					name.push_back(mile[count]);
			}*/
			
			name.push_back(tens_el[int(n)-int('0')]);
			
			l++;
			count++;
			i--;
		}
		 else if(l==3)
		{
			name.push_back(mile[l]);
			//cout<<"b";
			name.push_back(ones[int(n)-int('0')]);
			//cout<<"a";
			//cout<<
			
			l++;
			count++;
			i--;
		}
		else
		{
			continue;
		}

	}
	i=0;
	string actual;
	actual="";
	i=name.size()-1;
	while(i>=0)
	{
		actual=actual+" "+name[i];
		i--;
	}
	cout<<actual<<endl;
}