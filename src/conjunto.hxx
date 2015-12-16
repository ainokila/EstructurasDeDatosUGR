#include "conjunto.h"
//INICIO PRACTICA 3


// ================================= ITERADORCONJUNTO ========================================/


	conjunto::iterator conjunto::begin(){
		iterator iterador;
  		iterador.itv=vc.begin();
  		return iterador;
	}

	conjunto::iterator conjunto::end(){
		iterator iterador;
  		iterador.itv=vc.end();
  		return iterador;
	}

	conjunto::iterator::iterator(){
		
	}
	conjunto::iterator::iterator(const conjunto::iterator & it){
		itv = it.itv;
	}
	conjunto::iterator::iterator(const vector<conjunto::entrada>::iterator n){
		itv=n;
	}
		   
	const conjunto::entrada & conjunto::iterator::operator*() const{
			return *itv;
	}
		   
		   
	conjunto::iterator conjunto::iterator::operator++( int ){
		//Aquí hay que hacer una copia e incrementar el iterador, pero devolver la copia, porque es el operador de Pre-incremento.
			conjunto::iterator copia(itv);
			++itv;
			return copia;
			
	}
	conjunto::iterator & conjunto::iterator::operator++(){
			itv++;
			return *this;
	}
	conjunto::iterator conjunto::iterator::operator--(int){
		//Aquí hay que hacer una copia e decrementar el iterador, pero devolver la copia, porque es el operador de Pre-decremento.
			conjunto::iterator copia(itv);
			--itv;
			return copia;
	}			
			
	conjunto::iterator & conjunto::iterator::operator--(){
			itv--;
			return *this;
		   
	}
	bool conjunto::iterator::operator==(const iterator & it){
			return it.itv==itv;
	}
	bool conjunto::iterator::operator!=(const iterator & it){
			return it.itv!=itv;
	}


// ================================= FIN-ITERADORCONJUNTO ========================================/







// ================================= INICIO-ARREST_ITERADOR ========================================/



  
    	conjunto::arrest_iterator conjunto::abegin(){

		conjunto::arrest_iterator iterador;
		bool arresto = false;
		vector<conjunto::entrada>::iterator i = vc.begin();

		while(!arresto && i != vc.end()){
					
			if((*i).getArrest() == true){
				arresto = true;
			}
			else{
				i++;
			}
		}				
  		iterador.a_itv = i;
		iterador.ptr =this;
  		return iterador;
	}
	
	conjunto::arrest_iterator conjunto::aend(){
		conjunto::arrest_iterator iterador;
		iterador.a_itv = vc.end();
		iterador.ptr =this;
	        return iterador;
	}

	conjunto::arrest_iterator::arrest_iterator(){
	}

	conjunto::arrest_iterator::arrest_iterator(const conjunto::arrest_iterator & it){
		a_itv = it.a_itv;
	}	

	conjunto::arrest_iterator::arrest_iterator(const vector<conjunto::entrada>::iterator n){
		a_itv = n;
	}		

	const conjunto::entrada & conjunto::arrest_iterator::operator*() const{
		return *a_itv;
	}

	conjunto::arrest_iterator conjunto::arrest_iterator::operator++( int ){
	
	
		conjunto::arrest_iterator copia(a_itv);
		++(*this);		
		return copia;
			
	}

	conjunto::arrest_iterator & conjunto::arrest_iterator::operator++(){
		do{
        		a_itv++;

		}while ((*ptr).vc.end()!=a_itv && (*a_itv).getArrest()==false);

		return *this;
	 }

	conjunto::arrest_iterator conjunto::arrest_iterator::operator--( int ){
	
		conjunto::arrest_iterator copia(a_itv);
		--(*this);
		return copia;
			
	}

	conjunto::arrest_iterator & conjunto::arrest_iterator::operator--(){
		do{
        		a_itv--;

		}while ((*ptr).vc.begin()!=a_itv && (*a_itv).getArrest()==false);
		return *this;
	}

	bool conjunto::arrest_iterator::operator==(const conjunto::arrest_iterator & it){
			return it.a_itv==a_itv;
	}

	bool conjunto::arrest_iterator::operator!=(const conjunto::arrest_iterator & it){
			return it.a_itv!=a_itv;
	}
	
//*********************************FIN_ARRESTO_ITERATOR*************************







//Constructor por defecto

conjunto::conjunto(){
}

	
//Constructor de copia
	
conjunto::conjunto (const conjunto & d){

	
	this->vc = d.vc;
}




pair<conjunto::entrada,bool>  conjunto::findID( const long int & id) const{

	pair<conjunto::entrada, bool> solucion;
	solucion.second = false;
			unsigned int aux = id;

		if (busquedaBinaria(aux) != -1){
			if(vc[busquedaBinaria(aux)].getID() == id){
				solucion.first = vc[busquedaBinaria(id)];
				solucion.second = true;
		
			}
		}

return solucion;
}
	
conjunto conjunto::findIUCR( const string & iucr) const{
			
		
	conjunto solucion;
	
	for(size_t i =0;  i<vc.size() ; i++){
		if(vc[i].getIUCR() == iucr){
				
			solucion.insert(vc[i]);
			
		
		}
		
	}


return solucion;

}


conjunto conjunto::findDESCR( const string & descr) const{

	conjunto solucion;

	for(size_t i =0;  i<vc.size()  ; i++){
		if(vc[i].getDescr() == descr){
				
			solucion.insert(vc[i]);
		
		
		}
		
	}

return solucion;
}
int conjunto::busquedaBinaria(const long int & e)const{
		int primero = 0 ;
			int ultimo = vc.size()-1;

			while(primero<=ultimo){
				int central = (int) (primero+ultimo)/2;
			
				if(e == vc[central].getID()){
						primero = -1;
						ultimo = -2;
				}else if ( e < vc[central].getID() ) {
					ultimo = central -1 ;
				}else{
					primero = central +1 ;
				}
			}
			
return primero;
}
bool conjunto::insert( const conjunto::entrada & e){
		
		bool solucion = true;
		if(empty()){
			vc.push_back(e);
		}else{

			int posicion = busquedaBinaria(e.getID());
			if(posicion == -1){
					solucion = false;
			}
			else{
				vc.insert(vc.begin()+posicion, e);
			}
	}

return solucion;
}			

bool conjunto::erase(const long int & id){
	
	bool solucion = false;
	
	for (vector<conjunto::entrada>::iterator it = vc.begin() ; it != vc.end(); it++){
		if(it->getID() == id){
			solucion = true;
			vc.erase(it);
			
		}
	}

return solucion;  

}

bool conjunto::erase(const  conjunto::entrada & e){

		bool solucion = false;
	
	for (vector<conjunto::entrada>::iterator it = vc.begin() ; it != vc.end(); it++){
		if(it->getID() == e.getID()){
			solucion = true;
			vc.erase(it);
		}
	}

return solucion;  
}

conjunto & conjunto::operator=( const conjunto & org){

		
		this->vc = org.vc;

return *this;
}

conjunto::size_type conjunto::size() const {
	
return vc.size();
}

bool conjunto::empty() const{
	bool solucion = false;
		if (vc.size() == 0){
				solucion = true;
		}
return solucion;	

}

bool conjunto::cheq_rep( ) const{

  bool solucion=true;
 
		if(vc[0].getID() <= 0){
			solucion = false;
		}	
		
		for(unsigned int i = 0; i< vc.size()-1 && solucion; i++){
			if(vc[i+1]<vc[i]){
				solucion = false;
			}
		}
return solucion;

}


ostream& operator << ( ostream &sal, const conjunto & D){

		if(D.empty()){
			sal << "Conjunto vacio." ;

		}else{
			for(unsigned int i = 0; i< D.size(); i++){
				sal << D.getPos(i);
				sal << endl;
			}
		}
	return sal;
}



