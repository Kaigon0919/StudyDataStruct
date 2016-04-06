#pragma once
#ifndef __STRINGCLASS_H__
#define __STRINGCLASS_H__

#include<iostream>
#include<cstring>
using namespace std;

class String
{
private:
	int len;
	char * str;
public:
	String();
	String(const char * s);
	String(const String& s);
	~String();
	String& operator=(const String & s);
	String& operator+=(const String &s);
	bool operator== (const String& s);
	String operator+ (const String& s)const;

	friend ostream& operator<<(ostream& os, const String& s);
	friend istream& operator>>(istream& is, String& s);
};
#endif
