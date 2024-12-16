//zlHeader.h
//#ifndef _zlHeader_h
#if !defined(_zlHeader_h)
#define _zlHeader_h

typedef struct {
	int   Num;      //the number of 'Occupation, 1950 basis', and it is also the ID
	char  Occ[255]; //The name of Occupation
	int   iWordsCount;
} OCC50;

/******
typedef struct {
int   Num;      //the number of 'Occupation, 1950 basis', and it is also the ID
char  KinshipWords[4096]; //The name of Occupation
int   kwSize;
} QUERY;
*********/
typedef struct {
	int   Age;
	int   Income;
	int   Num;      //the number of 'Occupation, 1950 basis', and it is also the ID
	char  Occ[255]; //The name of Occupation
} RESULT;


typedef struct {
	char  Title[255]; //The name of book
	char  Issn[255]; // 
	char  Author[255]; // 
	char  Press[255]; // 
	int   PYear;	      //the year of published
	char  Price[255]; //
}BJUTBOOK;


typedef struct {
	int   iSizeHashBuckets;  //the number of tuples
	int   iSizeWnList;
	int   iNumDBNote;
}HEADER;

typedef struct {
	CString	    m_SearchWord;
	int	m_AgeFrom;
	int	m_AgeTo;
	int	m_IncomeFrom;
	int	m_IncomeTo;
}Q_CONDITION;

typedef struct {
	int	   ID;     //tuple ID
	double a;     // an attribute value (say, a0)
}TUPLE_ID_ATTR;

typedef struct{
	TUPLE_ID_ATTR * t;
}LIST;

/*struct TUPLE_POINTER
{
double	x[COL_NUM+1];	// the ith axis of tuple
double	d;				// the distance  between this tuple and the query
int		num;			// the number of this tuples in topN
int     ID;				// the ID of the tuple
bool	bIN;            // In the rectangle(S[i], or scr) or not
bool	bOK;            // whether or not in the Ball B(Q,mr,d), i.e., ? is it a top-N tuple?
double  d_max;          // the L_inf distance  between this tuple and the query
TUPLE_POINTER *next;
};*/




double a(double n);
double p(double n);


#endif