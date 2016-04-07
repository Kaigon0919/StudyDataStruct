#include "StringClass.h"
String::String() :len(0), str(NULL) {}
String::String(const char * s) {
	len = strlen(s);
	str = new char[len+1];
	strcpy_s(str,len+1, s);
}
String::String(const String& s) {
	len = s.len;
	str = new char[len+1];
	strcpy_s(str, len+1, s.str);
}
String::~String()
{
	if (str)
		delete[] str;
}
String& String::operator=(const String & s)
{
	if (str)
		delete[]str;
	len = s.len;
	str = new char[len+1];
	strcpy_s(str, len+1, s.str);

	return *this;
}
String& String::operator+=(const String &s)
{
	*this = *this + s;
	return *this;
}
bool String::operator== (const String& s) 
{
	if (!strcmp(str,s.str))
		return true;
	else
		return false;
}
String String::operator+ (const String& s) const
{
	int tempLen = this->len + s.len;

	/*/case 1
	char  temp[100];
	strcpy_s(temp, this->len + 1, this->str);
	strcat_s(temp,tempLen+1, s.str);
	return temp;
	//*/

	//*/case 2, reference book
	char * str = new char[tempLen+1];
	strcpy_s(str, this->len + 1, this->str);
	strcat_s(str,tempLen+1, s.str); // strcat을 사용하면 동적할당을 새로 해주는것은 아니기 떄문에 합했을때 문제가 없게 미리 두 크기의 합을 잡아줘야한다.
	String temp(str);
	delete[] str;
	return temp;
	//*/
}

ostream& operator<<(ostream& os, const String& s)
{
	os << s.str;
	return os;
}
istream& operator>>(istream& is, String& s)
{
	//reference book
	char str[100];
	is >> str;
	s = str;
	return is;
}