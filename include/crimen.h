/* 
 * meteorito.h
 * 
 * Copyright  (C) Juan F. Huete
*/
#ifndef __CRIMEN_H
#define __CRIMEN_H

#include <string>
#include <iostream> 

#include "fecha.h"
//! Clase crimen, asociada a la definición de un crimen 
/*! crimen::crimen,  .....
 * Descripción contiene toda la información asociada a un crimen.
 
 @todo Implementa esta clase, junto con su documentación asociada

*/


class crimen {
 private:
   long int ID; 
 public:
  crimen();
  crimen(const crimen& x);
  void setID(long int & id);
  void setCaseNumber(const string &  s);
  void setDate(const fecha & d);
  // ...
  void setArrest(bool a);
  void setDomestic(bool d); 
  // ...
  
  
  long int getID( ) const;
  string getCaseNumber( ) const;
  fecha getDate( ) const;
  
  // -...
   crimen & operator=(const crimen & c);
   bool operator==(const crimen & x) const;
   bool operator<(const crimen & x) const;
 
};

  ostream& operator<< ( ostream& , const crimen& );


#include "crimen.hxx"
#endif
