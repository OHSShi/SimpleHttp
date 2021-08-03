#ifndef		__HTTP_UTIL_HPP__
#define		__HTTP_UTIL_HPP__

#include	<string>
#include	<stdlib.h>
#include	<stdio.h>

#define TRIM_SPACE " \t\n\v"

std::string Trim(std::string s,const std::string& drop = TRIM_SPACE);
std::string RTrim(std::string s,const std::string& drop = TRIM_SPACE);
std::string LTrim(std::string s,const std::string& drop = TRIM_SPACE);

#endif
