#pragma once
class MyString
{
private:
	int size;
	char* Cs;

	int strLength(const char*)const;
	void construct(char);

public:
	MyString();
	MyString(char);
	MyString(const char*);
	MyString(int);
	MyString(int, bool);

	void print()const;

	void replaceFirst(char);

	//Deep Copy:-
	MyString(const MyString&);

	int length()const;

	int Atoi()const;

	//why return any value???
	MyString itoa(int x);

	char index(int)const;

	void trim();

	char charAtI(int)const;

	char& charRefAt(int)const;

	bool equal(const MyString&)const;

	int CMP(const MyString&)const;

	MyString str_cat(const MyString&)const;
};