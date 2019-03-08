#include "UUIDs.hpp"

#pragma pack(push,1)

#pragma pack(pop)

Destroyer:: Destroyer(void)
{
}

Destroyer::~Destroyer(void)
{
}

bool Destroyer::Interrupt(void)
{
  return true ;
}

bool Destroyer::Recycling(void)
{
  return true ;
}

bool Destroyer::Destructor(void)
{
  return true ;
}

void * Destroyer::Register(void *)
{
  return nullptr ;
}
