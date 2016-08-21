#include<stdio.h>
#include<stdlib.h>

//在每行每列都是从小到大排列好的二维数组中查询数字
bool Find(int* matrix, int rows, int columns, int number)
{
	bool found = false;

	if(matrix != NULL && rows > 0 && columns > 0)
	{
		int row = 0;
		int column = columns - 1;

		while(row < rows && column >= 0)
		{
			if(matrix[row * columns + column] == number)
			{
				found = true;
				break;
			}
			else if(matrix[row * columns + column] > number)
			{
				--column;
			}
			else
			{
				++row;
			}
		}
	}
	return found;
}

void Test(char* testname, int* matrix, int rows, int columns, int number, bool expected)
{
	if(testname != NULL)
		printf("%s begin: ",testname);

	bool result = Find(matrix, rows, columns, number);
	if(result == expected)
		printf("passed.\n");
	else
		printf("failed.\n");
}

//数字在数组中
void Test1()
{
	int matrix[][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
	Test("Test1", (int*)matrix, 4, 4, 7, true);
}

//数字不在数组中
void Test2()
{
	int matrix[][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
	Test("Test2", (int*)matrix, 4, 4, 5, false);		
}

//数字为最小
void Test3()
{
	int matrix[][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
	Test("Test3", (int*)matrix, 4, 4, 1, true);		
}

//数字最大
void Test4()
{
	int matrix[][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
	Test("Test4", (int*)matrix, 4, 4, 15, true);
}

//比最小的还小
void Test5()
{
	int matrix[][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
	Test("Test5", (int*)matrix, 4, 4, 0, false);		
}

//比最大的还大
void Test6()
{
	int matrix[][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
	Test("Test6", (int*)matrix, 4, 4, 99, false);		
}

//输入空指针
void Test7()
{
	int matrix[][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
	Test("Test7", NULL, 4, 4, 7, false);		
}

int main()
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();
	
	system("pause");

    return 0;
}