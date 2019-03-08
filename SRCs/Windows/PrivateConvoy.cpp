#include "UUIDs.hpp"
#include "PrivateUUIDs.hpp"

#ifndef DONT_USE_NAMESPACE
namespace PARALLEL_NAMESPACE {
#endif

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
  size_t cnt                  ;
  lock                    ( ) ;
  cnt = Destroyers . size ( ) ;
  unlock                  ( ) ;
  return cnt                  ;
}

bool ManageDestroyers::exists(Destroyer * destroyer)
{
  return std::find ( Destroyers . begin ( )                         ,
                     Destroyers . end   ( )                         ,
                     destroyer            ) != Destroyers . end ( ) ;
}

Destroyer * ManageDestroyers::at(int index)
{
  Destroyer * destroyer = nullptr     ;
  std::list<Destroyer *>::iterator it ;
  /////////////////////////////////////
  lock   ( )                          ;
  /////////////////////////////////////
  it = Destroyers . begin ( )         ;
  if ( 0 == index )                   {
    destroyer = (*it)                 ;
  } else                              {
    it = std::next ( it , index - 1 ) ;
    if ( it != Destroyers . end ( ) ) {
      destroyer = (*it)               ;
    }                                 ;
  }                                   ;
  /////////////////////////////////////
  unlock ( )                          ;
  /////////////////////////////////////
  return destroyer                    ;
}

size_t ManageDestroyers::add(Destroyer * destroyer)
{
  size_t cnt                             ;
  lock                      ( )          ;
  if ( ! exists ( destroyer ) )          {
    Destroyers . push_back ( destroyer ) ;
    destroyer -> Register  ( nullptr   ) ;
  }                                      ;
  cnt   = Destroyers . size ( )          ;
  unlock                    ( )          ;
  /////////////////////////////////////
     printf("%s\n",__FUNCTION__) ;
  /////////////////////////////////////
  return cnt                             ;
}

size_t ManageDestroyers::remove(Destroyer * destroyer)
{
  size_t cnt                          ;
  lock                      ( )       ;
  if ( exists ( destroyer ) )         {
    Destroyers . remove ( destroyer ) ;
            printf("Destroyers . remove\n") ;
  }                                   ;
  cnt   = Destroyers . size ( )       ;
  unlock                    ( )       ;
  /////////////////////////////////////
     printf("%s\n",__FUNCTION__) ;
  /////////////////////////////////////
  return cnt                          ;
}

void ManageDestroyers::clean(void)
{
  lock               ( ) ;
  Destroyers . clear ( ) ;
  unlock             ( ) ;
}

void ManageDestroyers::discontinue(void)
{
  std::list<Destroyer *>::iterator it                                     ;
  for ( it = Destroyers . begin ( ) ; it != Destroyers . end ( ) ; ++it ) {
    (*it) -> Interrupt ( )                                                ;
  }                                                                       ;
}

#ifndef DONT_USE_NAMESPACE
}
#endif
