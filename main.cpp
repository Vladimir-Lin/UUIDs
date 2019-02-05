#include <QCoreApplication>

#include "UUIDs.hpp"

int main(int argc, char *argv[])
{
    srand(time(NULL)) ;
  SUID * sa = (SUID *) suidArray ( 1000 ) ;
  for (int i = 0 ; i < 100 ; i++ ) {
    SUID extension= rand ( ) % 100000 ;
//    bool upper    = ( ( rand() % 2 ) == 1 ) ;
    bool upper    = false ;
    sa [ i ] = randomSuid ( extension , upper ) ;
  }
  suidSort(sa,100) ;
  for (int i = 0 ; i < 100 ; i++ ) {
    printf("%llu\n", sa [ i ] ) ;
  }
}
