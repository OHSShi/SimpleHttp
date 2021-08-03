#include	"HttpRequest.hpp"

HttpRequest::HttpRequest()
{

}

HttpRequest::~HttpRequest()
{
}

int		HttpRequest::Analyze( string rMessageStr )
{
	return	HTTP_MSG_ANALYZE_SUCCESS;
}

void	HttpRequest::Print()
{
	mHttpRequestLine.Print();
	mHttpHeader.Print();
}


int		HttpRequest::GetHttpVersion()
{
	return	mHttpRequestLine.GetHttpVersion();
}

string	HttpRequest::GetMethod()
{
	return	mHttpRequestLine.GetMethod();
}

string	HttpRequest::GetRequestUri()
{
	return	mHttpRequestLine.GetRequestUri();
}

string	HttpRequest::GetFieldValue( string rFieldName )
{
    return  mHttpHeader.GetFieldValue( rFieldName );
}


void	HttpRequest::SetMethod( string rMethod )
{
	mHttpRequestLine.SetMethod( rMethod );
}

void	HttpRequest::SetRequestUri( string rRequestUri )
{
	mHttpRequestLine.SetRequestUri( rRequestUri );
}

void	HttpRequest::SetHttpVersion( int rHttpVersion )
{
	mHttpRequestLine.SetHttpVersion( rHttpVersion );
}

void	HttpRequest::SetField( string rFieldName , string rFieldValue )
{
	mHttpHeader.SetField( rFieldName , rFieldValue );
}

int		HttpRequest::Assemble()
{
	int		ret;

	ret	= mHttpRequestLine.Assemble();
	if( ret < 0 )
	{
		return	-1;
	}

	ret	= mHttpHeader.Assemble();
	if( ret < 0 )
	{
		return	-1;
	}

	mAssembleData.clear();

	string	rHttpRequestLineStr	= mHttpRequestLine.GetAssembleData();
	string	rHttpHeaderStr		= mHttpHeader.GetAssembleData();

	mAssembleData.insert( 0 , ( char* )rHttpRequestLineStr.c_str() , rHttpRequestLineStr.size() );
	mAssembleData.insert( mAssembleData.size() , ( char* )rHttpHeaderStr.c_str() , rHttpHeaderStr.size() );
	mAssembleData.append( "\r\n" );

	return	0;
}

string	HttpRequest::GetAssembleData()
{
	return	mAssembleData;
}

void	HttpRequest::Clear()
{
	mHttpRequestLine.Clear();
	mHttpHeader.Clear();
	mAssembleData.clear();
}
