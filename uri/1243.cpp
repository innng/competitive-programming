#include <iostream> //cin,cout
#include <string>  //string
#include <sstream> //istringstream
#include <cctype>  //isdigit
  
using namespace std; 
  
int main(){ 
  
    string frase; 
  
    while(getline(cin,frase)){ 
  
        int tam = frase.size(); 
        int num=0;//contador da soma dos tamanhos das palavras
        int qtd=0;//contador da quantidade de palavras válidas 
        string token;//string que recebe cada palavra da string 
  
        istringstream iss(frase);//iss é usado para conter a frase 
        while ( getline(iss, token, ' ') ){//quebra a frase usando ' ' como delimitador e coloca em token 
  
            bool b = false;//booleano para verificar se a palavra é válida
            int tam = token.size(); 
            int num_aux = 0; //conta o comprimento da palavra
  
            for(int i=0 ; i<tam ; i++){ 
                if( isdigit(token[i]) || token[i] == '.' && i!=tam-1){//palavra inválida 
                    b=true;//indica que a palavra é inválida 
                    break; 
                }else if(token[i] == '.'){ 
                    //caso o ultimo caracter seja '.', não contabilize! 
                }else{ 
                    num_aux++; //incrementa o comprimento da palavra
                } 
            } 
            if(b==false){//se b for false indica que a palavra é válida
                num+=num_aux;//incrementa o comprimento da palavra atual na soma dos tamanhos das palavras
                qtd++;//incrementa a quantidade de palavras válidas 
            } 
        } 
        int comprim_medio; 
        (qtd == 0) ? comprim_medio = 0 : comprim_medio = num/qtd;//protege de uma divisão por 0 
        if(comprim_medio <=3){ 
            cout<<"250"<<endl; 
        }else if(comprim_medio == 4 || comprim_medio == 5 ){ 
            cout<<"500"<<endl; 
        }else{ 
            cout<<"1000"<<endl; 
        } 
    } 
}