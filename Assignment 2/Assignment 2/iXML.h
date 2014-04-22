//
//  iXML.h
//  Assignment 2
//
//  Created by Steve Minor on 4/21/14.
//  Copyright (c) 2014 Steve Minor. All rights reserved.
//

#ifndef __Assignment_2__iXML__
#define __Assignment_2__iXML__

#include "XMLNode.h"

namespace VG{
	class iXML{
	public:
		virtual std::ostream& toXML(std::ostream& os) = 0; //output in XML format
		virtual iXML& fromXML(const XMLNode& element) = 0; //create empty object and fill from xml data
	};
}

#endif /* defined(__Assignment_2__iXML__) */
