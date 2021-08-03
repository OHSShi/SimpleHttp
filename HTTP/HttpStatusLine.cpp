#include	"HttpStatusLine.hpp"
#include	"HttpUtil.hpp"

HttpStatusLine::HttpStatusLine()
{
	mMapStatusCode.insert( make_pair( 100 , "Continue" ) );
	mMapStatusCode.insert( make_pair( 101 , "Switching Protocols" ) );
	mMapStatusCode.insert( make_pair( 200 , "OK" ) );
	mMapStatusCode.insert( make_pair( 201 , "Created" ) );
	mMapStatusCode.insert( make_pair( 202 , "Accepted" ) );
	mMapStatusCode.insert( make_pair( 203 , "Non-Authoritative Information" ) );
	mMapStatusCode.insert( make_pair( 204 , "No Content" ) );
	mMapStatusCode.insert( make_pair( 205 , "Reset Content" ) );
	mMapStatusCode.insert( make_pair( 206 , "Partial Content" ) );
	mMapStatusCode.insert( make_pair( 300 , "Multiple Choices" ) );
	mMapStatusCode.insert( make_pair( 301 , "Moved Permanently" ) );
	mMapStatusCode.insert( make_pair( 302 , "Found" ) );
	mMapStatusCode.insert( make_pair( 303 , "See Other" ) );
	mMapStatusCode.insert( make_pair( 304 , "Not Modified" ) );
	mMapStatusCode.insert( make_pair( 305 , "Use Proxy" ) );
	mMapStatusCode.insert( make_pair( 307 , "Temporary Redirect" ) );
	mMapStatusCode.insert( make_pair( 400 , "Bad Request" ) );
	mMapStatusCode.insert( make_pair( 401 , "Unauthorized" ) );
	mMapStatusCode.insert( make_pair( 402 , "Payment Required" ) );
	mMapStatusCode.insert( make_pair( 403 , "Forbidden" ) );
	mMapStatusCode.insert( make_pair( 404 , "Not Found" ) );
	mMapStatusCode.insert( make_pair( 405 , "Method Not Allowed" ) );
	mMapStatusCode.insert( make_pair( 406 , "Not Acceptable" ) );
	mMapStatusCode.insert( make_pair( 407 , "Proxy Authentication Required" ) );
	mMapStatusCode.insert( make_pair( 408 , "Request Time-out" ) );
	mMapStatusCode.insert( make_pair( 409 , "Conflict" ) );
	mMapStatusCode.insert( make_pair( 410 , "Gone" ) );
	mMapStatusCode.insert( make_pair( 411 , "Length Required" ) );
	mMapStatusCode.insert( make_pair( 412 , "Precondition Failed" ) );
	mMapStatusCode.insert( make_pair( 413 , "Request Entity Too Large" ) );
	mMapStatusCode.insert( make_pair( 414 , "Request-URI Too Large" ) );
	mMapStatusCode.insert( make_pair( 415 , "Unsupported Media Type" ) );
	mMapStatusCode.insert( make_pair( 416 , "Requested range not satisfiable" ) );
	mMapStatusCode.insert( make_pair( 417 , "Expectation Failed" ) );
	mMapStatusCode.insert( make_pair( 500 , "Internal Server Error" ) );
	mMapStatusCode.insert( make_pair( 501 , "Not Implemented" ) );
	mMapStatusCode.insert( make_pair( 502 , "Bad Gateway" ) );
	mMapStatusCode.insert( make_pair( 503 , "Service Unavailable" ) );
	mMapStatusCode.insert( make_pair( 504 , "Gateway Time-out" ) );
	mMapStatusCode.insert( make_pair( 505 , "HTTP Version not supported" ) );
}

HttpStatusLine::~HttpStatusLine()
{
}

void	HttpStatusLine::Clear()
{
	mLine.clear();
	mHttpVersion	= -1;
	mStatusCode		= -1;
	mReasonPhrase.clear();
	mAssembleData.clear();
}

int		HttpStatusLine::Analyze( string rLine )
{
	mLine	= Trim( rLine );
	return	this->Analyze();
}

int		HttpStatusLine::Analyze()
{
	string  delimiters  = " ";
	string::size_type lastPos = mLine.find_first_not_of(delimiters, 0); // 맨 처음 문자가 구분자일 때
	string::size_type pos     = mLine.find_first_of( delimiters );     // 구분자 찾기
	//while (string::npos != pos || string::npos != lastPos)
	
	string	rHttpVersion;
	string	rStatusCode;

	for( int i = 0 ; i < 2 ; i++ )
	{
		if( !( string::npos != pos || string::npos != lastPos ) )
		{
			return	-1;
		}
		if( i == 0 )
		{
			rHttpVersion	= mLine.substr(lastPos, pos - lastPos);
		}
		if( i == 1 )
		{
			rStatusCode		= mLine.substr(lastPos, pos - lastPos);
		}
		lastPos = mLine.find_first_not_of(delimiters, pos);        // 구분자 다음으로 이동
		pos = mLine.find_first_of(delimiters, lastPos);        // 다음구분자 찾기
	}

	if( rHttpVersion.compare( "HTTP:/1.0" ) == 0 )
	{
		mHttpVersion	= 10;
	}
	else if( rHttpVersion.compare( 0 , 7 , "HTTP/1." ) == 0 )
	{
		mHttpVersion	= 11;
	}
	else	// Unknown Version.
	{
		return	-1;
	}

	mStatusCode	= atoi( rStatusCode.c_str() );
	map< int , string >::iterator	rMapIter	= mMapStatusCode.find( mStatusCode );
	if( rMapIter == mMapStatusCode.end() )
	{
		return	-1;
	}
	else
	{
		mReasonPhrase	= rMapIter->second;
	}

	return	0;
}

int		HttpStatusLine::GetHttpVersion()
{
	return	mHttpVersion;
}

int		HttpStatusLine::GetStatusCode()
{
	return	mStatusCode;
}

string	HttpStatusLine::GetReasonPhrase()
{
	return	mReasonPhrase;
}

void	HttpStatusLine::Print()
{
	printf( "HttpVersion(%d) StatusCode(%d) ReasonPhrase(%s)\n" , mHttpVersion , mStatusCode , 
			mReasonPhrase.c_str() );
}

int		HttpStatusLine::Assemble()
{

	return	-1;
}
