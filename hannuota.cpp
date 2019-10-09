#include<iostream>
using namespace std;
void move(int count, char start = 'a', char finish = 'b', char temp = 'c')
{
	if (count > 0)
	{
		move(count - 1, start, temp, finish);
		cout << "Move " << count << " from " << start << " to " << finish << endl;
		move(count - 1, temp, finish, start);
	}
}
void move_without_recursion(int count, char start = 'a', char finish = 'b', char temp = 'c')
{
	char swap;
	while (count > 0)
	{
		move_without_recursion(count - 1, start, temp, finish);
		cout << "Move " << count << " from " << start << " to " << finish << endl;
		count--;
		swap = start;
		start = temp;
		temp = swap;
	}
}
int main()
{
	int count;
	cout << "please enter the number:";
	cin >> count;
	cout << "递归方法运行过程:" << endl;
	move(count);
	cout << "消除尾递归方法运行过程:" << endl;
	move_without_recursion(count);
	return 0;
}