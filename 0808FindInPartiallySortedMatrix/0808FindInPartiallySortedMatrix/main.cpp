#include<stdio.h>
#include<stdlib.h>

//��ÿ��ÿ�ж��Ǵ�С�������кõĶ�ά�����в�ѯ����
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

//������������
void Test1()
{
	int matrix[][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
	Test("Test1", (int*)matrix, 4, 4, 7, true);
}

//���ֲ���������
void Test2()
{
	int matrix[][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
	Test("Test2", (int*)matrix, 4, 4, 5, false);		
}

//����Ϊ��С
void Test3()
{
	int matrix[][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
	Test("Test3", (int*)matrix, 4, 4, 1, true);		
}

//�������
void Test4()
{
	int matrix[][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
	Test("Test4", (int*)matrix, 4, 4, 15, true);
}

//����С�Ļ�С
void Test5()
{
	int matrix[][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
	Test("Test5", (int*)matrix, 4, 4, 0, false);		
}

//�����Ļ���
void Test6()
{
	int matrix[][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
	Test("Test6", (int*)matrix, 4, 4, 99, false);		
}

//�����ָ��
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