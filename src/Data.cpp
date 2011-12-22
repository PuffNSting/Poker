#include "..\include\Data.h"

Data::Data()
{
    //ctor
}

void Data::add(Hand input) {
    ++hands[input];
}
