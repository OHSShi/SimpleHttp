#ifndef		__HTTP_STATUS_LINE_HPP__
#define		__HTTP_STATUS_LINE_HPP__

#include	"HttpStartLine.hpp"

using namespace std;

class HttpStatusLine : public HttpStartLine
{
	private:
		map< int , string >	mMapStatusCode;

		int		mHttpVersion;
		int		mStatusCode;
		string	mReasonPhrase;

	public:
		HttpStatusLine();
		virtual ~HttpStatusLine();

		virtual int	Analyze();
		virtual int	Analyze( string rLine );
		int			GetHttpVersion();
		int			GetStatusCode();
		string		GetReasonPhrase();

		virtual int		Assemble();
		virtual void	Clear();

		using HttpStartLine::GetAssembleData;

		void		Print();

};

#endif
