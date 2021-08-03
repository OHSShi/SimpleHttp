#ifndef		__HTTP_START_LINE_HPP__
#define		__HTTP_START_LINE_HPP__

#include	<iostream>
#include	<string>
#include	<map>
#include	<vector>

#include	"HttpType.hpp"
#include	"HttpUtil.hpp"

using namespace std;

class HttpStartLine
{
	private:

	protected:
		string	mLine;
		string	mAssembleData;

	public:
		HttpStartLine();
		virtual ~HttpStartLine();

		virtual int		Analyze() = 0;
		virtual int		Analyze( string rLine );

		virtual int		Assemble()	= 0;
		virtual void	Clear()	= 0;

		string	GetAssembleData();

};

#endif
