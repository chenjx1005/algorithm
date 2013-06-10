#include <iostream>
#include <string>
#include <assert.h>
#include <algorithm>
using namespace std;

char radix[13] ={'0','1','2','3','4','5','6','7','8','9','A','B','C'};
string itomars(int a)
{
	string mars;
	while( a != 0)
	{
		mars += radix[a%13];
		a /= 13;
	}
	assert( mars.length() <= 2);
	while(mars.length() < 2)
	{
		mars += '0';
	}
	reverse(mars.begin(),mars.end());
	return mars;
}

int main()
{
	int r,g,b;
	cin >> r >> g >> b;
	cout << "#" << itomars(r) << itomars(g) << itomars(b) << endl;
}