#ifndef		__HTTP_HEADER_HPP__
#define		__HTTP_HEADER_HPP__

#include	"HttpType.hpp"
#include	"HttpUtil.hpp"

class HttpHeader
{
	private:
		VecField	mVecField;
		MapField	mMapField;

		string		mAssembleData;

	public:
		HttpHeader();
		virtual ~HttpHeader();

		int		Analyze( string& rLine );
		string	GetFieldValue( string rFieldName );

		void	SetField( string rFieldName , string rFieldValue );
		int		Assemble();
		string	GetAssembleData();

		void	Clear();
		void	Print();
};

#endif
