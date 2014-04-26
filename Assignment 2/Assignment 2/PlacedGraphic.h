//
//  PlacedGraphic.h
//  Assignment 2
//
//  Created by Steve Minor on 4/19/14.
//  Copyright (c) 2014 Steve Minor. All rights reserved.
//

#ifndef __Assignment_2__PlacedGraphic__
#define __Assignment_2__PlacedGraphic__

#include <iostream>
#include "iXML.h"
#include "VectorGraphic.h"

namespace VG{
	class PlacedGraphic: public iXML {
	public:
		PlacedGraphic();
		PlacedGraphic(const std::shared_ptr<XMLNode> element);
		
		void setPlacementPoint (Point const& placement);
		const Point& getPlacementPoint () const;
		
		void setGraphic (VectorGraphic const& graphic);
		VectorGraphic const& getGraphic () const;
		
		std::ostream& toXML(std::ostream& os);
		iXML& fromXML(const std::shared_ptr<XMLNode> element);
	private:
		Point placementPoint;
		VectorGraphic graphic;
	};
}


#endif /* defined(__Assignment_2__PlacedGraphic__) */
