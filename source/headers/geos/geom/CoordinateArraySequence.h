/**********************************************************************
 * $Id$
 *
 * GEOS - Geometry Engine Open Source
 * http://geos.refractions.net
 *
 * Copyright (C) 2006 Refractions Research Inc.
 *
 * This is free software; you can redistribute and/or modify it under
 * the terms of the GNU Lesser General Public Licence as published
 * by the Free Software Foundation. 
 * See the COPYING file for more information.
 *
 **********************************************************************/

#ifndef GEOS_GEOM_COORDINATEARRAYSEQUENCE_H
#define GEOS_GEOM_COORDINATEARRAYSEQUENCE_H

#include <vector>

//#include <geos/platform.h>
#include <geos/geom/CoordinateSequence.h>

#include <geos/inline.h>

// Forward declarations
namespace geos {
	namespace geom { 
		class Coordinate;
	}
}


namespace geos {
namespace geom { // geos.geom

/// The default implementation of CoordinateSequence
class CoordinateArraySequence : public CoordinateSequence {
public:

	CoordinateArraySequence(const CoordinateArraySequence &cl);

	CoordinateSequence *clone() const;

	//const Coordinate& getCoordinate(int pos) const;
	const Coordinate& getAt(unsigned int pos) const;

	/// Copy Coordinate at position i to Coordinate c
	virtual void getAt(unsigned int i, Coordinate& c) const;

	//int size() const;
	unsigned int getSize() const;
	const std::vector<Coordinate>* toVector() const;

	/// Construct an empty sequence
	CoordinateArraySequence();

	/// Construct sequence taking ownership of given Coordinate vector
	CoordinateArraySequence(std::vector<Coordinate> *coords);

	/// Construct sequence allocating space for n coordinates
	CoordinateArraySequence(unsigned int n);

	~CoordinateArraySequence();

	bool isEmpty() const;

	void add(const Coordinate& c);

	void setAt(const Coordinate& c, unsigned int pos);

	void deleteAt(unsigned int pos);

	std::string toString() const;

	void setPoints(const std::vector<Coordinate> &v);

	double getOrdinate(unsigned int index,
			unsigned int ordinateIndex) const;

	void setOrdinate(unsigned int index, unsigned int ordinateIndex,
			double value);

	void expandEnvelope(Envelope &env) const;

	unsigned int getDimension() const { return 3; }

	void apply_rw(const CoordinateFilter *filter); 

	void apply_ro(CoordinateFilter *filter) const; 

	virtual CoordinateSequence& removeRepeatedPoints();

private:
	std::vector<Coordinate> *vect;
};

/// This is for backward API compatibility
typedef CoordinateArraySequence DefaultCoordinateSequence;

} // namespace geos.geom
} // namespace geos

//#ifdef GEOS_INLINE
//# include "geos/geom/CoordinateArraySequence.inl"
//#endif

#endif // ndef GEOS_GEOM_COORDINATEARRAYSEQUENCE_H

/**********************************************************************
 * $Log$
 * Revision 1.3  2006/05/03 08:58:34  strk
 * added new non-static CoordinateSequence::removeRepeatedPoints() mutator.
 *
 * Revision 1.2  2006/03/24 09:52:41  strk
 * USE_INLINE => GEOS_INLINE
 *
 * Revision 1.1  2006/03/09 16:46:49  strk
 * geos::geom namespace definition, first pass at headers split
 *
 **********************************************************************/