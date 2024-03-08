#pragma once
#include "BSpline.h"

class TrimmedBSpline : public BSpline
{
public:
	TrimmedBSpline(const SPLINE_TYPE type = SPLINE_TYPE::FILL);
	void display();
};

