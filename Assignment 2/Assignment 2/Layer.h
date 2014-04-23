//
//  Layer.h
//  Assignment 2
//
//  Created by Steve Minor on 4/19/14.
//  Copyright (c) 2014 Steve Minor. All rights reserved.
//

#ifndef __Assignment_2__Layer__
#define __Assignment_2__Layer__

#include <iostream>
#include <list>
#include "PlacedGraphic.h"
#include "iXML.h"

namespace VG
{
    class Layer: public iXML
    {		
    public:
		Layer();
		Layer(const XMLNode& element);
		Layer(std::string _alias);
		
		void addPlacedGraphic(const PlacedGraphic& pg);
		
		std::list<PlacedGraphic> getPlacedGraphics();
		std::string getAlias();
		
		std::ostream& toXML(std::ostream& os); //output in XML format
		iXML& fromXML(const XMLNode& element);
		
    private:
        std::list<PlacedGraphic> graphics;
        std::string alias;
    };
}

#endif /* defined(__Assignment_2__Layer__) */
