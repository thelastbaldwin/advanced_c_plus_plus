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

namespace VG
{
    class Layer
    {
    private:
        typedef std::list<PlacedGraphic> PlacedGraphicCollection;
		
    public:
        typedef PlacedGraphicCollection::iterator PlacedGraphicIterator;
		
        // insert, remove, iteration support.
		
        // accessors to alias.
		
    private:
        PlacedGraphicCollection graphics;
        std::string alias;
    };
}

#endif /* defined(__Assignment_2__Layer__) */
