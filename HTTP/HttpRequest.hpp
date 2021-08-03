#ifndef		__HTTP_REQUEST_HPP__
#define		__HTTP_REQUEST_HPP__

#include	"HttpRequestLine.hpp"
#include	"HttpHeader.hpp"

class	HttpRequest
{
	private:
		HttpRequestLine	mHttpRequestLine;
		HttpHeader		mHttpHeader;

		string			mAssembleData;

	public:
		HttpRequest();
		virtual ~HttpRequest();

		int		Analyze( string rMessageStr );
		void	Print();

		int		GetHttpVersion();
		string	GetMethod();
		string	GetRequestUri();

		string  GetFieldValue( string rFieldName );

		void	SetMethod( string rMethod );
		void	SetRequestUri( string rRequestUri );
		void	SetHttpVersion( int rHttpVersion );
		void    SetField( string rFieldName , string rFieldValue );

		int		Assemble();
		string	GetAssembleData();

		void	Clear();

};

#endif
