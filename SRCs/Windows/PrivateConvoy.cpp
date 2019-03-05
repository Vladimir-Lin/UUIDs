#include "UUIDs.hpp"
#include "PrivateUUIDs.hpp"

ManageDestroyers:: ManageDestroyers(void)
{
  ::InitializeCriticalSection ( &mutex ) ;
}

ManageDestroyers::~ManageDestroyers(void)
{
  ::DeleteCriticalSection ( &mutex ) ;
}

void ManageDestroyers::lock(void)
{
  ::EnterCriticalSection ( &mutex ) ;
}

void ManageDestroyers::unlock(void)
{
  ::LeaveCriticalSection ( &mutex ) ;
}

size_t ManageDestroyers::count(void)
{
  size_t cnt                    ;
  this -> lock              ( ) ;
  cnt   = Destroyers . size ( ) ;
  this -> unlock            ( ) ;
  return cnt                    ;
}

bool ManageDestroyers::exists(Destroyer * destroyer)
{
  return std::find ( Destroyers . begin ( )                         ,
                     Destroyers . end   ( )                         ,
                     destroyer            ) != Destroyers . end ( ) ;
}

Destroyer * ManageDestroyers::at(int index)
{
  Destroyer * destroyer = nullptr ;
  std::list<Destroyer *>::iterator it                  ;
  this -> lock   ( )                                   ;
  it    = std::next ( Destroyers . begin ( ) , index ) ;
  if ( it != Destroyers . end ( ) )                    {
    destroyer = (*it)                                  ;
  }                                                    ;
  this -> unlock ( )                                   ;
  return destroyer                                     ;
}

size_t ManageDestroyers::add(Destroyer * destroyer)
{
  size_t cnt                             ;
  this -> lock              ( )          ;
  if ( ! exists ( destroyer ) )          {
    Destroyers . push_back ( destroyer ) ;
    destroyer -> Register  ( nullptr   ) ;
  }                                      ;
  cnt   = Destroyers . size ( )          ;
  this -> unlock            ( )          ;
  return cnt                             ;
}

size_t ManageDestroyers::remove(Destroyer * destroyer)
{
  size_t cnt                          ;
  this -> lock              ( )       ;
  if ( exists ( destroyer )   )       {
    Destroyers . remove ( destroyer ) ;
  }                                   ;
  cnt   = Destroyers . size ( )       ;
  this -> unlock            ( )       ;
  return cnt                          ;
}

void ManageDestroyers::clean(void)
{
  this      -> lock   ( ) ;
  Destroyers . clear  ( ) ;
  this      -> unlock ( ) ;
}

void ManageDestroyers::discontinue(void)
{
  std::list<Destroyer *>::iterator it                                     ;
  for ( it = Destroyers . begin ( ) ; it != Destroyers . end ( ) ; ++it ) {
    (*it) -> Interrupt ( )                                                ;
  }                                                                       ;
}