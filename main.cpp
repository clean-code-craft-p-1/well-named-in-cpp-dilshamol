#include <iostream>
#include <cassert>
#include "ColorPair.h"

void testNumberToPair(int pairNumber,TelCoColorCoder::MajorColor expectedMajor,TelCoColorCoder::MinorColor expectedMinor)
{
	TelCoColorCoder::ColorPair colorPair =TelCoColorCoder::GetColorFromPairNumber(pairNumber);
	std::cout << "Got pair " << colorPair.ToString() << std::endl;
	assert(colorPair.getMajor() == expectedMajor);
	assert(colorPair.getMinor() == expectedMinor);
}

void testPairToNumber(TelCoColorCoder::MajorColor major,TelCoColorCoder::MinorColor minor,int expectedPairNumber)
{
	int pairNumber = TelCoColorCoder::GetPairNumberFromColor(major, minor);
	std::cout << "Got pair number " << pairNumber << std::endl;
	assert(pairNumber == expectedPairNumber);
}

std::string GenerateReferenceManual()
{
	std::string referenceManual;
	for (int pairNumber = 1; pairNumber <= TelCoColorCoder::numberOfMajorColors * TelCoColorCoder::numberOfMinorColors; pairNumber++)
	{
		TelCoColorCoder::ColorPair colorPair = TelCoColorCoder::GetColorFromPairNumber(pairNumber);
		std::string colorPairStr = colorPair.ToString();
		referenceManual += "Pair " + std::to_string(pairNumber) + ": " + colorPairStr + "\n";
	}
	return referenceManual;
}

int main()
{
	testNumberToPair(4, TelCoColorCoder::WHITE, TelCoColorCoder::BROWN);
	testNumberToPair(5, TelCoColorCoder::WHITE, TelCoColorCoder::SLATE);

	testPairToNumber(TelCoColorCoder::BLACK, TelCoColorCoder::ORANGE, 12);
	testPairToNumber(TelCoColorCoder::VIOLET, TelCoColorCoder::SLATE, 25);

	std::string referenceManual = GenerateReferenceManual();
	std::cout << "Color Coding Reference Manual:\n" << referenceManual;

	return 0;
}
