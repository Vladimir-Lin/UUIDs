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

class ManageDestroyers
{
  public:

    std::list<Destroyer *> Destroyers ;

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

class PrivateEnabler
{
  public:

    bool                       shouldLock       ;

    std::map<int        ,bool> PrivateEnablings ;
    std::map<SUID       ,bool> UuidEnablings    ;
    std::map<std::string,bool> StringEnablings  ;

    explicit PrivateEnabler (void) ;
    virtual ~PrivateEnabler (void) ;

    void     lock           (void) ;
    void     unlock         (void) ;

    void     clear          (void) ;

    bool     hasEnabled     (int Id) ;
    bool     hasEnabled     (SUID Id) ;
    bool     hasEnabled     (std::string Id) ;

    bool     isAllTrue      (void) ;
    bool     isAllFalse     (void) ;

  protected:

  private:

    CRITICAL_SECTION mutex ;

} ;

#endif
