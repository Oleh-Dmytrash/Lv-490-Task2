#pragma once

#include <typeinfo>
#include "TypeUnion.h"

typedef struct 
{
	Value value;
	type_info* type;
} Element;