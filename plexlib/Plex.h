#pragma once
#include "exception.h"
#include "List.h"
#include "Line.h"
#include <iostream>
class Plex
{
protected:
	List<Line> lineList;
public:
	Plex();
	Plex(Plex& plex);
	~Plex();
	Plex& operator+=(Line& line);
	bool DeleteLine(const Line& line);
};

