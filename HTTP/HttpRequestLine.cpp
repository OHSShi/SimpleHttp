#include	"HttpRequestLine.hpp"
#include	"HttpUtil.hpp"

HttpRequestLine::HttpRequestLine()
{
	mHttpVersion	= -1;
}

HttpRequestLine::~HttpRequestLine()
{
}

void	HttpRequestLine::Clear()
{
	mLine.clear();
	mMethod.clear();
	mRequestUri.clear();
	mHttpVersion	= -1;

	mAssembleData.clear();
}

int		HttpRequestLine::Analyze( string rLine )
{
	mLine	= Trim( rLine );
	return	this->Analyze();
}

int		HttpRequestLine::Analyze()
{
	string  delimiters  = " ";
	string::size_type lastPos = mLine.find_first_not_of(delimiters, 0); // 맨 처음 문자가 구분자일 때
	string::size_type pos     = mLine.find_first_of( delimiters );     // 구분자 찾기
	//while (string::npos != pos || string::npos != lastPos)
	
	string	rHttpVersion;

	for( int i = 0 ; i < 3 ; i++ )
	{
		if( !( string::npos != pos || string::npos != lastPos ) )
		{
			return	-1;
		}
		if( i == 0 )
		{
			mMethod			= mLine.substr(lastPos, pos - lastPos);
		}
		if( i == 1 )
		{
			mRequestUri		= mLine.substr(lastPos, pos - lastPos);
		}
		if( i == 2 )
		{
			rHttpVersion	= mLine.substr(lastPos, pos - lastPos);
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

	return	0;
}

int		HttpRequestLine::GetHttpVersion()
{
	return	mHttpVersion;
}

string		HttpRequestLine::GetMethod()
{
	return	mMethod;
}

string	HttpRequestLine::GetRequestUri()
{
	return	mRequestUri;
}

void	HttpRequestLine::Print()
{
	printf( "Method(%s) RequestUri(%s) HttpVersion(%d)\n" , mMethod.c_str() , mRequestUri.c_str() , mHttpVersion );
}

void	HttpRequestLine::SetMethod( string rMethod )
{
	mMethod	= rMethod;
}

void	HttpRequestLine::SetRequestUri( string rRequestUri )
{
	mRequestUri	= rRequestUri;
}

void	HttpRequestLine::SetHttpVersion( int rHttpVersion )
{
	mHttpVersion	= rHttpVersion;
}

int		HttpRequestLine::Assemble()
{
	if( mMethod.size() == 0 || mRequestUri.size() == 0 )
	{
		return	-1;
	}
	mAssembleData.clear();

	mAssembleData.append( mMethod );
	mAssembleData.append( " " );
	mAssembleData.append( mRequestUri );
	mAssembleData.append( " " );

	if( mHttpVersion == 10 )
	{
		mAssembleData.append( "HTTP:/1.0" );
	}
	else
	{
		mAssembleData.append( "HTTP/1.1" );
	}
	
	mAssembleData.append( "\r\n" );

	return	0;
}

