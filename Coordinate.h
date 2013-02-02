// Coordinate.h: interface for the Coordinate class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_COORDINATE_H__9AD535D5_6AC8_4675_8D56_102178E61D8A__INCLUDED_)
#define AFX_COORDINATE_H__9AD535D5_6AC8_4675_8D56_102178E61D8A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class Coordinate  
{
public:
	Coordinate(int x, int y);
	Coordinate();
	virtual ~Coordinate();

	int x;
	int y;
};

#endif // !defined(AFX_COORDINATE_H__9AD535D5_6AC8_4675_8D56_102178E61D8A__INCLUDED_)
