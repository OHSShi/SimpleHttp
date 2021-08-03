#include	"HttpStartLine.hpp"

HttpStartLine::HttpStartLine()
{
}

HttpStartLine::~HttpStartLine()
{
}

int		HttpStartLine::Analyze( string rLine )
{
	mLine	= Trim( rLine );
	return	this->Analyze();
}

string	HttpStartLine::GetAssembleData()
{
	return	mAssembleData;
}
