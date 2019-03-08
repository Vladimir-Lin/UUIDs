/****************************************************************************\
 *
 *                         SUID and TUID private functions
 *
\****************************************************************************/

#ifndef PRIVATEUUIDS_HPP
#define PRIVATEUUIDS_HPP

#include "UUIDs.hpp"

#include <Windows.h>

#include <list>
#include <map>

#ifndef DONT_USE_NAMESPACE
namespace PARALLEL_NAMESPACE {
#endif

class ManageDestroyers
{
  public:

    std::list<CIOS::Destroyer *> Destroyers ;

    explicit    ManageDestroyers (void) ;
    virtual    ~ManageDestroyers (void) ;

    size_t      count            (void) ;

    Destroyer * at               (int index) ;

    size_t      add              (Destroyer * destroyer) ;
    size_t      remove           (Destroyer * destroyer) ;

    void        clean            (void) ;
    void        discontinue      (void) ;

  protected:

    bool        exists           (Destroyer * destroyer) ;

    void        lock             (void) ;
    void        unlock           (void) ;

  private:

    CRITICAL_SECTION mutex ;

} ;

#ifndef DONT_USE_NAMESPACE
}
#endif

#endif
