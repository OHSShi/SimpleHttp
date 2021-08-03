#ifndef		__HTTP_RESPONSE_HPP__
#define		__HTTP_RESPONSE_HPP__

#include	"HttpStatusLine.hpp"
#include	"HttpHeader.hpp"

class	HttpResponse
{
	private:
		HttpStatusLine	mHttpStatusLine;
		HttpHeader		mHttpHeader;

		string			mBodyStr;
		int				mBodyLen;

		string			mAssembleData;

	public:
		HttpResponse();
		virtual ~HttpResponse();

		int		Analyze( string rMessageStr );
		void	Print();

		int		GetHttpVersion();
		int		GetStatusCode();
		string	GetReasonPhrase();

		string	GetFieldValue( string rFieldName );
		string	GetBody();
		int		GetBodyLen();

		int		Assemble();
		string	GetAssembleData();
};

#endif
