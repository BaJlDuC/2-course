#pragma once
#include <stdint.h>
#include "IShape.h"

using namespace std;

class ISolidShape : public IShape
{
public:
	virtual uint32_t GetFillColor() const = 0;
};