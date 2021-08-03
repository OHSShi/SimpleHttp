#include	"HttpResponse.hpp"

HttpResponse::HttpResponse()
{

}

HttpResponse::~HttpResponse()
{
}

int		HttpResponse::Analyze( string rMessageStr )
{
	int		ret;

	mHttpHeader.Clear();
	mBodyStr.clear();

	size_t	rPnt			= 0;
    string  rDelimiter		= "\r\n";	// CRLF
	size_t	rDelimiterSize	= rDelimiter.size();

	rPnt = rMessageStr.find( rDelimiter , rPnt );
	if( rPnt == string::npos )
	{
		return	HTTP_MSG_ANALYZE_NOT_CLOSE;
	}

	string	rStartLine	= rMessageStr.substr( 0 , rPnt );
	ret	= mHttpStatusLine.Analyze( rStartLine );
	if( ret == HTTP_MSG_ANALYZE_FAIL )
	{
		return	HTTP_MSG_ANALYZE_FAIL;
	}

	rPnt	+= rDelimiterSize;
	size_t	rFound;


    while ( 1 )
	{
		rFound = rMessageStr.find( rDelimiter , rPnt );
		if( rFound == string::npos )
		{
			break;
		}

		string	rLine	= rMessageStr.substr( rPnt , rFound - rPnt );
		rPnt = rFound + rDelimiterSize;

		if( rLine.size() == 0 )	// Body Found.
		{
			mBodyStr	= rMessageStr.substr( rPnt );
			break;
		}

		ret	= mHttpHeader.Analyze( rLine );
		if( ret == HTTP_MSG_ANALYZE_FAIL )
		{
			return	HTTP_MSG_ANALYZE_FAIL;
		}
	}

	int	rStatusCode	= mHttpStatusLine.GetStatusCode();
	if( rStatusCode == 204 ||	// No Content
		rStatusCode == 304 ||	// Not Modified
		( rStatusCode >= 100 && rStatusCode < 200 ) )	// 1xx codes have no body
	{
		mBodyLen	= 0;
		return	HTTP_MSG_ANALYZE_SUCCESS;
	}

	if( mBodyStr.size() == 0 )
	{
		return	HTTP_MSG_ANALYZE_NOT_CLOSE;
	}


	string	rTransferEncoding	= mHttpHeader.GetFieldValue( "TRANSFER-ENCODING" );
	if( rTransferEncoding.compare( "chunked" ) == 0 )
	{
		int		rChunkedLen;
		string	rTempBody	= mBodyStr;
		mBodyStr.clear();

		while( 1 )
		{
			rFound	= rTempBody.find( rDelimiter );
			if( rFound == string::npos )
			{
				return	HTTP_MSG_ANALYZE_NOT_CLOSE;
			}
			string	rLine	= rTempBody.substr( 0 , rFound );
			rChunkedLen	= ( int )strtol( rLine.c_str() , NULL , 16 );
	//cout << "Hex: " << rLine << ", ChunkedLen: " << rChunkedLen << endl;

			if( rChunkedLen > ( rTempBody.size() - ( rFound + rDelimiterSize * 2 ) ) ) 
			{
				return	HTTP_MSG_ANALYZE_NOT_CLOSE;
			}

			mBodyStr.insert( mBodyStr.size() , rTempBody.substr( rFound + rDelimiterSize , rChunkedLen ) );	
			rTempBody.erase( 0 , rFound + ( rDelimiterSize * 2 ) + rChunkedLen );


			if( rTempBody.size() > 0 )
			{
				continue;
			}

			if( rChunkedLen != 0 )
			{
				return HTTP_MSG_ANALYZE_CHUNKED;
			}
			break;

		}
	}
	else
	{
		string	rContentLength	= mHttpHeader.GetFieldValue( "CONTENT-LENGTH" );
		if( rContentLength == "" )
		{
			return	HTTP_MSG_ANALYZE_FAIL;
		}

		mBodyLen	= atoi( rContentLength.c_str() );
		if( mBodyLen > mBodyStr.size() )
		{
			return	HTTP_MSG_ANALYZE_NOT_CLOSE;
		}

		mBodyStr.erase( mBodyLen );
	}

	return	HTTP_MSG_ANALYZE_SUCCESS;
}

void	HttpResponse::Print()
{
	mHttpStatusLine.Print();
	mHttpHeader.Print();
	printf( "-- Body -- Len(%d) Real(%d)\n[%s]\n" , mBodyLen , mBodyStr.size() , mBodyStr.c_str() );
}

int		HttpResponse::GetHttpVersion()
{
	return	mHttpStatusLine.GetHttpVersion();
}

int		HttpResponse::GetStatusCode()
{
	return	mHttpStatusLine.GetStatusCode();
}

string	HttpResponse::GetReasonPhrase()
{
	return	mHttpStatusLine.GetReasonPhrase();
}

string	HttpResponse::GetBody()
{
	return	mBodyStr;
}

int		HttpResponse::GetBodyLen()
{
	return	mBodyLen;
}
