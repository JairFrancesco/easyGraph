#include "countmodel.h"
using namespace Model;

CountModel::CountModel() : mValue(0){}

int CountModel::value()
{
    return mValue;
}

void CountModel::setValue(int value)
{
    mValue = value;
}

