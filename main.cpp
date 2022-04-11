#include <iostream>
#include<string>
#include <assert.h>    
#include "namespace.h"
using namespace TelCoColorCoder;

void testNumberToPair(int pairNumber, TelCoColorCoder::MajorColor expectedMajor,TelCoColorCoder::MinorColor expectedMinor)
{
    TelCoColorCoder::ColorPair colorPair = TelCoColorCoder::GetColorFromPairNumber(pairNumber);
    std::cout << "Got pair " << colorPair.ToString() << std::endl;
    assert(colorPair.getMajor() == expectedMajor);
    assert(colorPair.getMinor() == expectedMinor);
}

void testPairToNumber( TelCoColorCoder::MajorColor major, TelCoColorCoder::MinorColor minor, int expectedPairNumber)
{
    int pairNumber = TelCoColorCoder::GetPairNumberFromColor(major, minor);
    std::cout << "Got pair number " << pairNumber << std::endl;
    assert(pairNumber == expectedPairNumber);
}

std::string colourPairReferenceManual()
{
    int pairNumber, totalPairs = numberOfMinorColors * numberOfMajorColors;
    std::string manual,sub_string;
    std::cout << "\nColor Code Manual" << std::endl << "\nPair Number- Major colour Minor Colour\n  " << std::endl;;
    for (pairNumber = 1; pairNumber <= totalPairs; pairNumber++)
    {
        TelCoColorCoder::ColorPair colorPair = TelCoColorCoder::GetColorFromPairNumber(pairNumber);
        sub_string = std::to_string(pairNumber) + " - " + colorPair.ToString() + "\n";
        manual += sub_string;
    }
    return manual;
}

int main() 
{
    std::string colourManual;
    testNumberToPair(4, TelCoColorCoder::WHITE, TelCoColorCoder::BROWN);
    testNumberToPair(5, TelCoColorCoder::WHITE, TelCoColorCoder::SLATE);
    testPairToNumber(TelCoColorCoder::BLACK, TelCoColorCoder::ORANGE, 12);
    testPairToNumber(TelCoColorCoder::VIOLET, TelCoColorCoder::SLATE, 25);
    colourManual = colourPairReferenceManual();
    std::cout << colourManual << std::endl;
    return 0;
}
