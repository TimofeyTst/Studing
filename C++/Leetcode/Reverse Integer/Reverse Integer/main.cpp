#include <iostream>

int reverse(int x) 
{
	int s = 0;
	while (x)
	{
		//if( ( (INT_MAX - x % 10)/10 > s && x >= 0) || ( (-INT_MAX - x % 10) / 10 < s && x <= 0) )
			//s = s * 10 + x % 10;
		if (x > 0)
		{
			if ((INT_MAX - x % 10) / 10 >= s)
				s = s * 10 + x % 10;
			else
				s = x = 0;
		}
		else if ((-INT_MAX - x % 10) / 10 <= s)
			s = s * 10 + x % 10;
		else 
			s = x = 0;
		x /= 10;
	}
	return s;
}



void print(int x)
{
	std::cout << x << std::endl;
}
int main()
{
	int result = reverse(123);
	print(result);//000 000 000 0
	int test = reverse(1000000003);
	print(test);
	int test2 = reverse(-321);
	print(test2);
	int test3 = reverse(-1000000003);
	print(test3);
	int test4 = reverse(1463847412);
	print(test4);
	return 0;
}