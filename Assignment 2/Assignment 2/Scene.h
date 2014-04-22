//
//  Scene.h
//  Assignment 2
//
//  Created by Steve Minor on 4/19/14.
//  Copyright (c) 2014 Steve Minor. All rights reserved.
//

#ifndef __Assignment_2__Scene__
#define __Assignment_2__Scene__

#include <iostream>
#include "Layer.h"

namespace VG
{
	class Scene
	{
	private:
		typedef std::list<Layer> LayerCollection;
		
	public: typedef LayerCollection::iterator LayerIterator;
		
		// insert, remove, iteration support.
		
		// accessors to width and height.
		
	private:
		LayerCollection layers;
		int width;
		int height;
	};
}
#endif /* defined(__Assignment_2__Scene__) */
