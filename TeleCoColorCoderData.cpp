
#include "ColorPair.h"

namespace TelCoColorCoder
{
	const char* MajorColorNames[] = 
	{
		"White", "Red", "Black", "Yellow", "Violet"
	};

	const int numberOfMajorColors = sizeof(MajorColorNames) / sizeof(MajorColorNames[0]);

	const char* MinorColorNames[] =
	{
		"Blue", "Orange", "Green", "Brown", "Slate"
	};

	const int numberOfMinorColors = sizeof(MinorColorNames) / sizeof(MinorColorNames[0]);
}
