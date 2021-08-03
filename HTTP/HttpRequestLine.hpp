#ifndef		__HTTP_REQUEST_LINE_HPP__
#define		__HTTP_REQUEST_LINE_HPP__

#include	"HttpStartLine.hpp"

using namespace std;

class HttpRequestLine : public HttpStartLine
{
	private:
		string	mMethod;
		string	mRequestUri;
		int		mHttpVersion;

	public:
		HttpRequestLine();
		virtual ~HttpRequestLine();

		// [ Analyze
		virtual int	Analyze();
		virtual int	Analyze( string rLine );

		string	GetMethod();
		string	GetRequestUri();
		int		GetHttpVersion();
		// ]


		// [ Assemble
		void	SetMethod( string rMethod );
		void	SetRequestUri( string rRequestUri );
		void	SetHttpVersion( int rHttpVersion );

		virtual int		Assemble();
		virtual void	Clear();
		using HttpStartLine::GetAssembleData;
		// ]

		void		Print();

};

#endif
