#ifndef		__HTTP_TYPE_HPP__
#define		__HTTP_TYPE_HPP__

#include	<string>
#include	<map>
#include	<vector>

using namespace std;

// [ Request
typedef struct {
	string  mName;
	string  mValue;
} StField;

typedef vector< StField >           VecField;
typedef vector< StField >::iterator VecFieldIter;
// ]

// [ Response
typedef	map< string , string >				MapField;
typedef	map< string , string >::iterator	MapFieldIter;
// ]


const int       HTTP_MSG_ANALYZE_SUCCESS	= 0;
const int       HTTP_MSG_ANALYZE_FAIL		= -1;
const int       HTTP_MSG_ANALYZE_NOT_CLOSE	= 1;
const int       HTTP_MSG_ANALYZE_SPARE		= 2;
const int       HTTP_MSG_ANALYZE_CHUNKED	= 3;

#endif
