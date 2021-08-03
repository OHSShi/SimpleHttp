#include	"HttpRequest.hpp"

int main( int argc , char** argv )
{
	int				ret;
	HttpRequest		ht;

	
	ht.SetMethod( "GET" );
	ht.SetRequestUri( "/containers/json?all=1" );
	ht.SetHttpVersion( 11 );

	ht.SetField( "Host" , "70.11.238.10:2375" );
	ht.SetField( "Connection" , "close" );
	ht.SetField( "Accept" , "*/*" );

	ret	= ht.Assemble();
	if( ret < 0 )
	{
		cout << "Assemble Fail" << endl;
		return	-1;
	}

	string	rRequestStr	= ht.GetAssembleData();
	cout << rRequestStr << endl;
	
	ht.Print();


#if 0
	//ret = ht.Analyze( "GET /containers/json?all=1 HTTP/1.1" );
	ret = ht.Analyze( rRequestStr );
	if( ret < 0 )
	{
		cout << "Fail" << endl;
	}
	else
	{
#if 0
		cout << ht.GetMethod() << endl;
		cout << ht.GetHttpVersion() << endl;
		cout << ht.GetRequestUri() << endl;
#endif
		ht.Print();

	}
#endif

	return	0;
}
