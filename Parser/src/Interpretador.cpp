#include "../include/Interpretador.h"
#include "../include/funciones.h"
#include "../include/tipos de datos.h"

string unir_vector(std::vector<string> v){
  string temp="";
  for (auto it : v){
    temp+=it;
  }
  return temp;
}



bool isOper(std::map<str_interp,num_interp (*) (num_interp,num_interp)> func_b, std::map<str_interp,num_interp (*) (num_interp)> func_u, str_interp text){
  for (auto it : func_b){
    if (text == it.first){
      return true;
    }
  }
  for (auto ite : func_u){
    if (text == ite.first){
      return true;
    }
  }
  return false;
}


Interpretador::Interpretador()
{
    this->tree=new arbol_binario();
  // ------------------func binarias
    T_do (*suma_p)(num_interp, num_interp);
    suma_p =&suma;
    T_do (*resta_p)(num_interp, num_interp);
    resta_p =&resta;
    T_do (*multi_p)(num_interp, num_interp);
    multi_p =&multiplicacion;
    T_do (*divi_p)(num_interp, num_interp);
    divi_p =&division;
    T_do (*potencia_p)(num_interp, num_interp);
    potencia_p =&potencia;

    //-----------------func unarias
    T_do (*seno_p)(num_interp);
    seno_p =&seno;
    T_do (*tangente_p)(num_interp);
    tangente_p =&tangente;


    //------------------map_binario

    funciones_binarias["+"]=suma_p;
    funciones_binarias["-"]=resta_p;
    funciones_binarias["*"]=multi_p;
    funciones_binarias["/"]=divi_p;
    funciones_binarias["^"]=potencia_p;
    //------------------map_unario

    funciones_unarias["sin"]=seno_p;
    funciones_unarias["tan"]=tangente_p;

    //-----------------prioridad_funciones

    prioridad_funciones["+"]=4;
    prioridad_funciones["-"]=4;
    prioridad_funciones["*"]=3;
    prioridad_funciones["/"]=3;
    prioridad_funciones["sin"]=2;
    prioridad_funciones["tan"]=2;
    prioridad_funciones["^"]=1;


}



Interpretador::~Interpretador()
{
    //dtor
}

bool Interpretador::es_operador_unario(string oper){
  for(auto it:this->funciones_unarias){
    if(it.first==oper){
      return true;
    }
  }
  return false;
}

bool Interpretador::es_operador_binario(string oper){
  for(auto it:this->funciones_binarias){
    if(it.first==oper){
      return true;
    }
  }
  return false;
} 

bool Interpretador::es_expresion(string texto){
  if(texto[0]=='('&&texto[texto.size()-1]==')'){
    return true;
  }
  return false;
}

void Interpretador::fix_operaciones_unarias(std::vector<string>& v){
  
  for(int i=0;i<v.size();i++){
    if(this->es_operador_unario(v.at(i))){
      v.at(i)="("+v.at(i)+v.at(i+1)+")";
      v.erase(v.begin()+i+1);
    }
  }
}

void Interpretador::fix_multiplicaciones(std::vector<string>& v){
  for(auto it:v){
    cout<<it<<endl;
  }
  string l_last="";
  string last="";
  for (string& it : v){
      

      if(all_of(it.begin(),it.end(),[](char a){return isalpha(a);}) || all_of(it.begin(),it.end(),[](char a){if(a=='.'){return 1;}else{return isdigit(a);};}) || this->es_operador(it) || (this->es_expresion(it)&&(this->es_operador(last)==true || last=="") ) ){
                
      }

      else{
          cout<<"-"<<it<<"-"<<this->es_operador(last)<<endl;
          bool tmp=false;
          string temp="";
          for(auto& ite:it){
            if(isdigit(ite)==false&&tmp==false&&ite!='.'){
              temp+="*";
              temp+=ite;
              tmp=true;
            }
            else{
              temp+=ite;
            }
          }
          it=temp;
      }
    l_last=last;
    last=it;
  }

}

std::vector<string> Interpretador::string_to_vector(string text){
  elim_parent(text);
  std::vector<string> v;
  int_c num_parent=0;
  str_interp temp="";
  string oper_mayor_prio="";
  int mayor_prio=0;
  for (auto it : text){
      temp+=it;
      if (it=='('){
        num_parent++;
      }
      else if (it==')'){
        num_parent--;
      }
      if (num_parent==0){
        for(auto i : funciones_binarias){
            if(buscar_ope(temp, i.first, v) == true){
                temp="";
                if(prioridad_funciones[i.first]>mayor_prio){
                  oper_mayor_prio=i.first;
                  mayor_prio=prioridad_funciones[i.first];

                }
                break;
            }
        }
        for(auto i : funciones_unarias){
            if(buscar_ope(temp, i.first, v) == true){
                temp="";
                if(prioridad_funciones[i.first]>mayor_prio){
                  oper_mayor_prio=i.first;
                  mayor_prio=prioridad_funciones[i.first];

                }
                break;
            }
        }
      }
  }
  v.push_back(temp);
  elim_vacio(v);
  return v;
  //this->fix_negativos(v);
  //this->fix_operaciones_unarias(v);
  //this->fix_multiplicaciones(v);    
}

string Interpretador::verif_sintaxis(std::string  text){
  elim_parent(text);
  std::vector<string> v=this->string_to_vector(text);
  cout<<"********************"<<endl;
  for(auto it:v){
    cout<<it<<endl;
  }
  cout<<"********************"<<endl;
  this->fix_operaciones_unarias(v);
  this->fix_multiplicaciones(v);     
  this->fix_negativos(v);
  cout<<"------------------"<<endl;
  cout<<"********************"<<endl;
  string temp=unir_vector(v);
  elim_parent(temp);
  v=string_to_vector(temp);  
  for(auto it:v){
    cout<<it<<endl;
  }
  cout<<"********************"<<endl;
  
    for (int i=0; i<v.size();i++){
        
        cout<<"-->"<<v.at(i)<<endl;
      if (v.at(i)[0]=='(' & v.at(i)[v.at(i).size()-1]==')'){
        std::cout << "entro" << std::endl;
        elim_parent(v.at(i));
        v.at(i)=  '('+verif_sintaxis(v.at(i))+')' ;
      }
    }    
  
  
  

  string result=unir_vector(v);
  elim_parent(result);
  return result;
}



void Interpretador::fix_negativos(std::vector<string>& v){
  if(v.at(0)=="-"){
    if(es_operador(v.at(1))==true){
      v.at(0)="(0-"+v.at(1)+v.at(2)+")";
      v.erase(v.begin()+1);
      v.erase(v.begin()+1);
    }
    else{
      v.at(0)="(0-"+v.at(1)+")";
      v.erase(v.begin()+1);
    }
  }
  for(int i=1;i<v.size();i++){
    if(v.at(i)=="-" && this->es_operador(v.at(i-1))==true ){
      if(this->es_operador(v.at(i+1))==true){
        v.at(i)="(0-"+v.at(i+1)+v.at(i+2)+")";
        v.erase(v.begin()+i+1);
        v.erase(v.begin()+i+1);
      }
      else{
        v.at(i)="(0-"+v.at(i+1)+")";
        v.erase(v.begin()+i+1);
      }
    }
  }
}

bool Interpretador::es_operador(string oper){
  for(auto it : this->funciones_unarias){
    if(oper==it.first){
      return true;
      break;
    }
  }
  for(auto it : this->funciones_binarias){
    if(oper==it.first){
      return true;
      break;
    }
  }
  return false;
}

void Interpretador::reverse_string(string& x){
  reverse(x.begin(),x.end());
}


booleano Interpretador::buscar_ope(str_interp text, str_interp ope, std::vector<string>& list){

  reverse_string(text);
  reverse_string(ope);

  if(esta_en(text,ope)){
      reverse_string(text);
      reverse_string(ope);


      text.erase(text.end()-ope.size(),text.end());


      list.push_back(text);
      list.push_back(ope);
      return true;
  }
  return false;
}

booleano Interpretador::esta_en(str_interp text, str_interp ope){
    if(text.size()>=ope.size()){
        for (int_c i=0; i<ope.size();i++){
            if(ope[i]!=text[i]){
                return false;
            }
        }
        return true;
    }
    return false;
}

string Interpretador::get_operador_mayor_prioridad(std::vector<string> v){
  string operador_mayor_prioridad="";
  int mayor_prio=0;
  for(auto it:v){
    if(this->es_operador(it)){
      if(this->get_operador_prioridad(it)>mayor_prio){
        operador_mayor_prioridad=it;
        mayor_prio=this->get_operador_prioridad(it);
      }
    }
  }
  return operador_mayor_prioridad;
}

int Interpretador::get_operador_prioridad(string oper){
  return this->prioridad_funciones[oper];
}

T_do Interpretador::string_to_double(str_interp text){
  T_do f = 0.0;
  stringstream ss;
  ss << text;
  ss >> f;
  return f;
}




void Interpretador::separar_en_dos(std::vector<string>& v,str_interp ope){

  std::vector<string> temp;
  str_interp temp1="";
  booleano found = false;
  for (auto i : v){

    if (i==ope & found==false){
      temp.push_back(temp1);
      found=true;
      temp1="";
    }
    else{
      temp1+=i;
    }
  }
  temp.push_back(temp1);
  v=temp;

}

void Interpretador::elim_vacio(std::vector<string> & v){
  std::vector<string> temp;
  for (auto it : v){
    if(it!=""){
      temp.push_back(it);
    }
  }
  v=temp;
}

void Interpretador::transformar(str_interp text){
  if(is_number(text)){
    text="0+"+text;
  }

  text=verif_sintaxis(text);
  elim_parent(text);
  vector<string> v=string_to_vector(text);
  string oper_mayor_prio=get_operador_mayor_prioridad(v);
  int mayor_prio=get_operador_prioridad(oper_mayor_prio);
  bool func_bin=es_operador_binario(oper_mayor_prio);
  


  if(oper_mayor_prio==""){
    if(isAlpha(text)){
      Nodo* raiz=new Nodo_double(text);
      this->tree=new arbol_binario(raiz);
      return;
    }
  }
  //std::cout << oper_mayor_prio<<"<--"<< std::endl;
  //std::cout << (func_bin? "es binario" : "es unario") <<"<---------" << std::endl;
  
  separar_en_dos(v, oper_mayor_prio);
  elim_vacio(v);
  Nodo*raiz;
  //std::cout << func_bin << std::endl;
  if(func_bin){
    raiz=new Nodo_funcion_binaria(*funciones_binarias[oper_mayor_prio]);
    this->tree=new arbol_binario(raiz);
    for (auto i : v){

    }
    transformar(v.at(0), this->tree->raiz, false);
    transformar(v.at(1), this->tree->raiz, true);
  }
  else{
    raiz=new Nodo_funcion_unaria(*funciones_unarias[oper_mayor_prio]);
    this->tree=new arbol_binario(raiz);
    transformar(v.at(0), this->tree->raiz, true);
  }
/*
  double(* funcion)(double, double);
  this->tree->raiz->get_valor(funcion);
  std::cout << ((*funcion)(23,4)) << std::endl;
*/
}
booleano Interpretador::isAlpha(const str_interp &str){
  for (auto i : str){
    if (isdigit(i)){
      return false;
    }
  }
  return true;
}

void Interpretador::elim_parent(str_interp & texto){
  int temp=0;
  int temp2=1;
  int tam=texto.size();
  if (tam>=3){
      for (auto it : texto){
          if (it=='('){
              temp++;
          }
          else if(it==')'){
              temp--;
          }
          if (temp==0){
              if(temp2==tam){
                  texto.erase(texto.begin(),texto.begin()+1);
                  texto.erase(texto.end()-1,texto.end());
                  elim_parent(texto);
              }
              else{
                  return;
              }
          }
          temp2++;
      }
  }

}

void Interpretador::transformar(str_interp text, Nodo* padre, booleano der){
  cout<<"transformando 2"<<endl;
  elim_parent(text);
  cout<<"1"<<endl;
  if(is_number(text)){
    
    Nodo* nodo=new Nodo_double(string_to_double(text));
    
    if(der){
      padre->agregar_der(nodo);
    }  
    else{
      padre->agregar_izq(nodo);
    }

    return;

  }


  text=verif_sintaxis(text);
  elim_parent(text);
  vector<string> v=string_to_vector(text);
  string oper_mayor_prio=get_operador_mayor_prioridad(v);
  int mayor_prio=get_operador_prioridad(oper_mayor_prio);
  bool func_bin=es_operador_binario(oper_mayor_prio);

  
  if(oper_mayor_prio==""){
    if(isAlpha(text)){
      Nodo* nodo=new Nodo_double(text);
      if(der){
        padre->agregar_der(nodo);
      }
      else{
        padre->agregar_izq(nodo);
      }
      return;
    }
  }

  //std::cout << oper_mayor_prio<<"<---------" << std::endl;
  //std::cout << (func_bin? "es binario" : "es unario") <<"<---------" << std::endl;
  
  separar_en_dos(v, oper_mayor_prio);
  elim_vacio(v);

  Nodo*nodo;
  if(func_bin){
      nodo=new Nodo_funcion_binaria(*funciones_binarias[oper_mayor_prio]);
      if(der){
          padre->agregar_der(nodo);
          transformar(v.at(0), padre->der, false);
          transformar(v.at(1), padre->der, true);
      }
      else{
          padre->agregar_izq(nodo);
          transformar(v.at(0), padre->izq, false);
          transformar(v.at(1), padre->izq, true);
      }
  }
  else{
    nodo=new Nodo_funcion_unaria(*funciones_unarias[oper_mayor_prio]);
    if(der){
        padre->agregar_der(nodo);
        transformar(v.at(0), padre->der, true);
    }
    else{
        padre->agregar_izq(nodo);
        transformar(v.at(0), padre->izq, true);
    }

  }

}

bool Interpretador::is_number(const std::string& s)
{
    for(auto it:s){
      if(isdigit(it) || (it=='.')){
        
      }
      else{
        return false;
      }
    }
    return true;
}

