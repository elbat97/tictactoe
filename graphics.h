#ifndef GD_H
#define GD_H

#include <iostream> 
#include <vector> 
#include <memory>
#include "grid.h"

class Xwindow; //For the graphics

class Graphics: public Grid {   
	std::unique_ptr<Xwindow> xw;

#endif
