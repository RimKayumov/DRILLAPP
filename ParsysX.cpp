#include "ParsysX.h"

ParsysX::ParsysX()
{

}

int ParsysX::sizeOf(const int& i) const
{
    return params_sizes.at(i);
}
