#include "UUIDs.hpp"

Destroyer:: Destroyer(void)
{
}

Destroyer::~Destroyer(void)
{
}

bool Destroyer::Recycling(void)
{
  return true ;
}

bool Destroyer::Destructor(void)
{
  return true ;
}

void * Destroyer::Register(void * package)
{
  return nullptr ;
}
