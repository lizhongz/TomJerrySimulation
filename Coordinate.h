// Coordinate.h: interface for the Coordinate class.
//
//////////////////////////////////////////////////////////////////////

#ifndef _COORDINATE_H_
#define _COORDINATE_H_

//! Position in a 2 dimention map
class Coordinate  
{
public:
	//! Constructor
	/*!
	  \param x x coordinate
	  \param y y coordinate value
	*/
	Coordinate(int x, int y);

	//! Default constructor
	Coordinate();

	//! Deconstructor
	virtual ~Coordinate();

	int x; //! x coordinate value
	int y; //! y coordinate value
};

#endif 
