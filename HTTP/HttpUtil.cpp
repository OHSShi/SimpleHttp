#include	"HttpUtil.hpp" 

std::string Trim(std::string s,const std::string& drop)
{
	std::string r=s.erase(s.find_last_not_of(drop)+1);
	return r.erase(0,r.find_first_not_of(drop));
}
std::string RTrim(std::string s,const std::string& drop)
{
	return s.erase(s.find_last_not_of(drop)+1);
}
std::string LTrim(std::string s,const std::string& drop)
{
	return s.erase(0,s.find_first_not_of(drop));
}
