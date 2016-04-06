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
	if (len != s.len){
		if (str)
			delete[]str;
	}
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

	/*case 1
	char * temp = new char[tempLen + 1];
	strcpy_s(temp, this->len + 1, this->str);
	strcat_s(temp,tempLen+1, s.str);
	return temp;
	*/
	
	String temp = *this;
	strcat_s(temp.str, tempLen+1, s.str);
	temp.len = tempLen;
	return temp;
}

ostream& operator<<(ostream& os, const String& s)
{
	os << s.str << endl;
	return os;
}
istream& operator>>(istream& is, String& s)
{
	is >> s;
	return is;
}