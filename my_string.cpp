#include "my_string.h"
#include <iostream>

void MyString::construct(char c)
{
	size = 1;
	Cs = new char[size + 1];
	Cs[0] = c;
	Cs[1] = '\0';
}
int MyString::strLength(const char* c)const
{
	if (c == nullptr)
		return 0;

	int i = 0;
	while (c[i] != '\0')
		i++;
	return i;
}

MyString::MyString()
{
	Cs = nullptr;
	size = 0;
}
MyString::MyString(char c)
{
	construct(c);
}
MyString::MyString(const char* c)
{
	size = strLength(c);
	Cs = new char[size + 1];
	for (int i = 0; i < size + 1; i++)
		Cs[i] = c[i];
}
MyString::MyString(int x, bool ignore)
{
	this->size = x;
	this->Cs = new char[this->size + 1];
}

void MyString::print()const
{
	for (int i = 0; i < this->size; i++)
		std::cout << this->Cs[i];
}

MyString::MyString(int x)
{
	if (x == 0)
	{
		this->construct('0');
		return;
	}

	//Find size:-
	this->size = 0;
	int temp = x;
	while (temp != 0)
	{
		temp /= 10;
		size++;
	}

	//For -ve numbers:-
	if (x < 0)
	{
		size++;
		Cs = new char[size + 1];
		Cs[0] = '-';
		x *= -1;
	}
	else
		Cs = new char[size + 1];

	int i = 0;
	while (x > 0)
	{
		Cs[size - 1 - i] = char('0' + (x % 10));
		x /= 10;
		i++;
	}
	Cs[size] = '\0';
}

void MyString::replaceFirst(char c)
{
	this->Cs[0] = c;
}
//Deep Copy:-
MyString::MyString(const MyString& str)
{
	this->size = str.size;
	this->Cs = new char[str.size + 1];

	for (int i = 0; i <= this->size; i++)
		this->Cs[i] = str.Cs[i];

}

int MyString::length()const
{
	if (Cs == nullptr)
		return 0;

	int l = 0;
	while (Cs[l] != '\0')
		l++;
	return l;
}

int MyString::Atoi()const
{
	int x = 0;
	if (this->Cs[0] == '-')
		for (int i = 1; i < this->size; i++)
		{
			x *= 10;
			x -= int(Cs[i] - '0');
		}
	else
		for (int i = 0; i < this->size; i++)
		{
			x *= 10;
			x += int(Cs[i] - '0');
		}

	return x;
}

//why return any value???
MyString MyString::itoa(int x)
{
	MyString str(x);
	*this = str;
	return *this;
}

char MyString::index(int i)const
{
	if (i >= this->size or i < 0)
		return '\0';
	return Cs[i];
}

void MyString::trim()
{
	int startI = 0,
		endI = this->length();

	while (this->Cs[startI] == '\t' || this->Cs[startI] == '\n' || this->Cs[startI] == ' ')
		startI++;
	while (this->Cs[endI] == '\t' || this->Cs[endI] == '\n' || this->Cs[endI] == ' ')
		endI--;

	int S = endI - startI;
	MyString newStr(S, 1);

	for (int index = 0, i = startI; i <= endI; index++, i++)
	{
		newStr.Cs[index] = this->Cs[i];
	}
	*this = newStr;
}

char MyString::charAtI(int i)const
{
	return this->Cs[i];
}

char& MyString::charRefAt(int i)const
{
	return this->Cs[i];
}

bool MyString::equal(const MyString& str2)const
{
	return (!this->CMP(str2));
}

int MyString::CMP(const MyString& str2)const
{
	int i = -1;
	do
	{
		i++;
		if (this->Cs[i] < str2.Cs[i])
			return 1;
		if (this->Cs[i] > str2.Cs[i])
			return -1;
	} while (this->Cs[i] != '\0' && str2.Cs[i] != '\0');

	return 0;
}

MyString MyString::str_cat(const MyString& str2)const
{
	MyString newStr;
	newStr.size = this->size + str2.size;
	newStr.Cs = new char[newStr.size + 1];

	for (int i = 0; Cs[i] != '\0'; i++)
		newStr.Cs[i] = this->Cs[i];
	for (int i = this->size; str2.Cs[i - this->size] != '\0'; i++)
		newStr.Cs[i] = str2.Cs[i - this->size];
	newStr.Cs[newStr.size] = '\0';

	return newStr;
}