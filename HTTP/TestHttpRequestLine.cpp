#include	"HttpRequestLine.hpp"

int main( int argc , char** argv )
{
	int				ret;
	HttpRequestLine	ht;

	
	ht.SetMethod( "GET" );
	ht.SetRequestUri( "/containers/json?all=1" );
	ht.SetHttpVersion( 11 );

	ret	= ht.Assemble();
	if( ret < 0 )
	{
		cout << "Assemble Fail" << endl;
		return	-1;
	}

	string	rRequestStr	= ht.GetAssembleData();
	cout << rRequestStr << endl;


	//ret = ht.Analyze( "GET /containers/json?all=1 HTTP/1.1" );
	ret = ht.Analyze( rRequestStr );
	if( ret < 0 )
	{
		cout << "Fail" << endl;
	}
	else
	{
		cout << ht.GetMethod() << endl;
		cout << ht.GetHttpVersion() << endl;
		cout << ht.GetRequestUri() << endl;
	}

	return	0;
}
