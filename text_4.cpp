#include<bits/stdc++.h>
#define ll long long
using namespace std;
string a[105];
int main(){
	int target = 0;
	cin>>target;
	bool judge = false;
	int i = 0;
	int sum = 0;
	while(judge == false)
	{
		i++;
		sum+=i;
		if(sum>=target)
		{
			int n = sum;
			if((n - target)%3==0)
			{
				judge = true;
				cout<<"find the door nums"<<endl;
				cout<<"sum_door_num: "<<i<<endl;
				cout<<"myHome nums: "<<(n - target)/3<<endl;
			}
		}
	}
	return 0;
}

