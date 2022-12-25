#include<iostream>
using namespace std;

#include "my_string.h"

int main()
{
	MyString str1("sup mate");
	MyString str2;
	MyString str3('e');
	MyString str4(786);

	cout << "str1: ";	str1.print();
	cout << "\nstr2: ";	str2.print();
	cout << "\nstr3: ";	str3.print();
	cout << "\nstr4: ";	str4.print();

	MyString str5 = "Sara";
	MyString str6 = str5;
	str5.replaceFirst('z');

	cout << "\nstr5: ";	str5.print();
	cout << "\nstr6: ";	str6.print();

	MyString str7;
	cout << endl << str7.length();

	MyString str8 = "-5872";
	int val = str8.Atoi();
	cout << endl << val + 1;

	MyString str9;
	str9.itoa(-786);
	cout << "\nstr9: ";	str9.print();

	MyString str10 = "abcde";
	cout << endl << str10.index(-1);

	MyString str11 = "\n\t       I am a happy man\n";
	cout << "\nstr11: ";	str11.print();
	str11.trim();
	cout << "\n~Trimmed~\nstr11: ";	str11.print();

	char c1 = str11.charAtI(9);
	cout << "\nchar at index-8 (of str11) is: " << c1;

	char& c2 = str11.charRefAt(9);
	c2 = 'P';
	cout << "\nChanged str11 (using char& at index-8) is: ";	str11.print();


	MyString str12 = str11;
	if (str12.equal(str11))
		cout << "\nstr12 and str11 are equal.";
	else
		cout << "\nstr12 and str11 are not equal.";

	if (str12.CMP(str10) > 0)
		cout << "\nstring1 comes before string2.";
	else if (str12.CMP(str10) < 0)
		cout << "\nstring1 comes after string2.";
	else
		cout << "\nstring1 is equal to string2.";

	MyString str13 = str11.str_cat(str10);
	cout << "\n str11 + str10 is: ";	str13.print();


	system("pause>nul");
	return 0;
}