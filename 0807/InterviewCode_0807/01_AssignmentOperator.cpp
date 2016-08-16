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
		printf("����%s",m_pData);
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
		printf("�չ���");
		m_pData = new char[1];
		m_pData[0] = '\0';
	}
	else
	{
		printf("�ǿչ���");
		int length = strlen(pData);
		m_pData = new char[length + 1];
		strcpy_s (m_pData, pData);
	}
}

CMYString::CMYString(const CMYString& str)
{
	printf("���ж�����");
	int length = strlen(str.m_pData);
	m_pData = new char[length + 1];
	strcpy_s(m_pData, str.m_pData);
}

CMYString& CMYString::operator = (const CMYString& str)
{
	if(this == &str)
	{
		printf("��ֵ����� ���");
		return *this;
	}

	printf("��ֵ����� ����");
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

