#include<iostream>
#include<string.h>
using namespace std;
#define _CRT_SECURE_NO_WARNINGS


class CMYString
{
public:
	CMYString(char* pData = NULL);
	CMYString(const CMYString& str);
	
	~CMYString();
	/*{
		printf("析构%s",m_pData);
	}*/

	CMYString& operator = (const CMYString& str);

	void print();

private:
	char* m_pData;
};

CMYString::~CMYString()
{}

CMYString::CMYString(char* pData)
{
	if(NULL == pData)
	{
		printf("空构造");
		m_pData = new char[1];
		m_pData[0] = '\0';
	}
	else
	{
		printf("非空构造");
		int length = strlen(pData);
		m_pData = new char[length + 1];
		strcpy_s (m_pData, pData);
	}
}

CMYString::CMYString(const CMYString& str)
{
	printf("已有对象构造");
	int length = strlen(str.m_pData);
	m_pData = new char[length + 1];
	strcpy_s(m_pData, str.m_pData);
}

CMYString& CMYString::operator = (const CMYString& str)
{
	if(this == &str)
	{
		printf("赋值运算符 相等");
		return *this;
	}

	printf("赋值运算符 不等");
	delete []m_pData;
	m_pData = NULL;

	m_pData = new char[strlen(str.m_pData)+1];
	strcpy_s(m_pData, str.m_pData);

	return *this;
}

void CMYString::print()
{
	printf("%s",m_pData);
}

