#include "../include/Interpretador.h"
#include "../include/funciones.h"

Interpretador::Interpretador()
{
    this->tree=new arbol_binario();
  // ------------------func binarias
    double (*suma_p)(double, double);
    suma_p =&suma;
    double (*resta_p)(double, double);
    resta_p =&resta;
    double (*multi_p)(double, double);
    multi_p =&multiplicacion;
    double (*divi_p)(double, double);
    divi_p =&division;
    double (*potencia_p)(double, double);
    potencia_p =&potencia;

    //-----------------func unarias
    double (*seno_p)(double);
    seno_p =&seno;
    double (*tangente_p)(double);
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

void Interpretador::reverse_string(string& x){
  reverse(x.begin(),x.end());
}


bool Interpretador::buscar_ope(string text, string ope, std::vector<string>& list){

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

bool Interpretador::esta_en(string text, string ope){
    if(text.size()>=ope.size()){
        for (int i=0; i<ope.size();i++){
            if(ope[i]!=text[i]){
                return false;
            }
        }
        return true;
    }
    return false;
}

double Interpretador::string_to_double(string text){
  double f = 0.0;
  stringstream ss;
  ss << text;
  ss >> f;
  return f;
}

void Interpretador::separar_en_dos(std::vector<string>& v,string ope){

  std::vector<string> temp;
  string temp1="";
  bool found = false;
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

void Interpretador::transformar(string text,vector<string>& v){
  elim_parent(text);
  if(is_number(text)){
    Nodo* raiz=new Nodo_double(string_to_double(text));
    this->tree=new arbol_binario(raiz);
    return;
  }
  int num_parent=0;
  bool func_bin = false;
  string temp="";
  string oper_mayor_prio="";
  int mayor_prio=0;
  for (auto it : text){
      if (it=='('){
        num_parent++;
      }
      else if (it==')'){
        num_parent--;
      }
      temp+=it;
      if (num_parent==0){
        for(auto i : funciones_binarias){
            if(buscar_ope(temp, i.first, v) == true){
                temp="";
                if(prioridad_funciones[i.first]>mayor_prio){
                  oper_mayor_prio=i.first;
                  mayor_prio=prioridad_funciones[i.first];
                  func_bin=true;
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
                  func_bin=false;
                }
                break;
            }
        }
      }
  }

  if(oper_mayor_prio==""){
    if(isAlpha(text)){
      Nodo* raiz=new Nodo_double(text);
      this->tree=new arbol_binario(raiz);
      return;
    }
  }
  std::cout << oper_mayor_prio<<"<--"<< std::endl;
  std::cout << (func_bin? "es binario" : "es unario") <<"<---------" << std::endl;
  v.push_back(temp);
  separar_en_dos(v, oper_mayor_prio);
  elim_vacio(v);
  Nodo*raiz;
  std::cout << func_bin << std::endl;
  if(func_bin){
    raiz=new Nodo_funcion_binaria(*funciones_binarias[oper_mayor_prio]);
    this->tree=new arbol_binario(raiz);
    for (auto i : v){
        cout<<i<<endl;
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
bool Interpretador::isAlpha(const string &str){
  for (auto i : str){
    if (isdigit(i)){
      return false;
    }
  }
  return true;
}

void Interpretador::elim_parent(string & a){
  if (a[0]=='(' & a[a.size()-1]==')'){
    int num_parent=0;
    int temp=0;
    for (auto i : a){
      if(i=='('){
        num_parent++;
      }
      else if(i==')'){
        num_parent--;
      }
      if(num_parent==0){
        temp++;
      }
    }
    if(temp==1){
      a.erase(a.begin(),a.begin()+1);
      a.erase(a.end()-1,a.end());
    }
  }
}

void Interpretador::transformar(string text, Nodo* padre, bool der){
  elim_parent(text);
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
  int num_parent=0;
  std::vector<string> v;
  bool func_bin = false;
  string temp="";
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
                  func_bin=true;
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
                  func_bin=false;
                }
                break;
            }
        }
      }
  }

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

  std::cout << oper_mayor_prio<<"<---------" << std::endl;
  std::cout << (func_bin? "es binario" : "es unario") <<"<---------" << std::endl;
  v.push_back(temp);
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
    return !s.empty() && std::find_if(s.begin(),
        s.end(), [](char c) { return !std::isdigit(c); }) == s.end();
}
