#include	"HttpHeader.hpp"
#include	<stdio.h>

static	void	StrToUpper( string& rInputStr )
{
	static int	rDiff	= 'a' - 'A';
	for( int i = 0 ; i < rInputStr.size() ; i++ )
	{
		if( rInputStr[ i ] >='a' && rInputStr[ i ] <= 'z' )
		{
			rInputStr[ i ] = rInputStr[ i ] - rDiff;
		}
	}
}

HttpHeader::HttpHeader()
{
}

HttpHeader::~HttpHeader()
{
}


int		HttpHeader::Analyze( string& rLine )
{
	size_t	rFound;
	rFound	= rLine.find( ":" );
	if( rFound == string::npos )
	{
		return	HTTP_MSG_ANALYZE_FAIL;
	}

	string	rFieldName	= rLine.substr( 0 , rFound );
	string	rFieldValue	= Trim( rLine.substr( rFound + 1 ) );

	StrToUpper( rFieldName );

	mMapField.insert( make_pair( rFieldName , rFieldValue ) );

	return	HTTP_MSG_ANALYZE_SUCCESS;
}

string	HttpHeader::GetFieldValue( string rFieldName )
{
	MapFieldIter	rMapFieldIter	= mMapField.find( rFieldName );
	if( rMapFieldIter == mMapField.end() )
	{
		return	"";
	}

	return	rMapFieldIter->second;
}

void	HttpHeader::Clear()
{
	mVecField.clear();
	mMapField.clear();

	mAssembleData.clear();
}

void	HttpHeader::Print()
{
	for( MapFieldIter rMapFieldIter = mMapField.begin() ; rMapFieldIter != mMapField.end() ; rMapFieldIter++ )
	{
		printf( "Name: [%s] , Value: [%s]\n" , rMapFieldIter->first.c_str() , rMapFieldIter->second.c_str() );
	}
}

void	HttpHeader::SetField( string rFieldName , string rFieldValue )
{
	StField	rStField;
	rStField.mName	= rFieldName;
	rStField.mValue	= rFieldValue;

	mVecField.push_back( rStField );
}

int		HttpHeader::Assemble()
{
	mAssembleData.clear();
	for( int i = 0 ; i < mVecField.size() ; i++ )
	{
		mAssembleData.insert( mAssembleData.size() , mVecField[ i ].mName.c_str() , mVecField[ i ].mName.size() );
		mAssembleData.append( ": " );
		mAssembleData.insert( mAssembleData.size() , mVecField[ i ].mValue.c_str() , mVecField[ i ].mValue.size() );
		mAssembleData.append( "\r\n" );
	}

	return	0;
}

string	HttpHeader::GetAssembleData()
{
	return	mAssembleData;
}
