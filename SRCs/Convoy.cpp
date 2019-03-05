#include "UUIDs.hpp"

Convoy:: Convoy    (void)
       : Destroyer (    )
{
}

Convoy::~Convoy(void)
{
}

bool Convoy::Interrupt(void)
{
  return true ;
}

bool Convoy::Recycling(void)
{
  return true ;
}

bool Convoy::Destructor(void)
{
  return true ;
}

void * Convoy::Register(void *)
{
  return nullptr ;
}

int Convoy::Join(Destroyer * destroyer)
{
  return 0 ;
}

int Convoy::Remove(Destroyer * destroyer)
{
  return 0 ;
}

bool Convoy::Discontinue(void)
{
  return true ;
}

bool Convoy::Eliminate(void)
{
  return true ;
}

int Convoy::Survived(void) const
{
  return 0 ;
}
