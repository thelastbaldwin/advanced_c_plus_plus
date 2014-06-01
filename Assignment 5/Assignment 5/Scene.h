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
#include <stdexcept>
#include "Layer.h"
#include "iXML.h"

namespace VG
{
	class Scene: public iXML
	{		
	public:
		Scene();
		Scene(const std::shared_ptr<XMLNode> element);
		
		void addLayer(const Layer& l);
		
		void setWidth(const int& w) { width = w; };
		void setHeight(const int& h) {height = h; };
		
		int getWidth() const { return width; };
		int getHeight() const { return height; };
		
		std::ostream& toXML(std::ostream& os);
		iXML& fromXML(const std::shared_ptr<XMLNode> element);
		
	private:
		std::list<Layer> layers;
		void checkBounds(); //determine if layers are within scene
		int width;
		int height;
	};
}
#endif /* defined(__Assignment_2__Scene__) */
