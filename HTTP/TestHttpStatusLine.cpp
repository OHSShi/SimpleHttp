#include	"HttpStatusLine.hpp"

int main( int argc , char** argv )
{
	int				ret;
	HttpStatusLine	ht;
	//HttpStartLine*	ht	= new HttpStatusLine;

	ret = ht.Analyze( "HTTP/1.1 200 OK" );
	if( ret < 0 )
	{
		cout << "Fail" << endl;
	}
	else
	{
		cout << ht.GetHttpVersion() << endl;
		cout << ht.GetStatusCode() << endl;
		cout << ht.GetReasonPhrase() << endl;
	}

	return	0;
}
