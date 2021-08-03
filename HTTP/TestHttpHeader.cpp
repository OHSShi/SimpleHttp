#include	<iostream>

#include	"HttpHeader.hpp"

int main( int argc , char** argv )
{
	int				ret;
	HttpHeader		ht;

	

	ht.SetField( "Host" , "70.11.238.192:2375" );
	ht.SetField( "Connection" , "close" );

	ret	 = ht.Assemble();
	if( ret < 0 )
	{
		cout << "Assemble Fail" << endl;
	}

	string	rHeader	= ht.GetAssembleData();
	cout << rHeader << endl;

	string	rLine	= "Host: 70.11.238.192:2375";
#if  1
	ret = ht.Analyze( rLine );
	if( ret < 0 )
	{
		cout << "Fail" << endl;
	}
	else
	{
		ht.Print();
	}
#endif

	return	0;
}
