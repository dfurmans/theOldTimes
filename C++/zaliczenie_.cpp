#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>
#include <conio.h>
#include <iostream>
#include <vector>

using namespace std;
//klasa bazowa która jest klasa abstrakcyjna tzn. nie mozemy z niej bezpoœrednio tworzyæ obiektów tylko przez 
//klasy pochodne od niej
class Figura

{
      protected:
            char color[20];
            float pole;
            int typ; // 1- pros, 2 - troj, 3 - okrag
           
      public:
             /* Konstruktor*/
             Figura () {pole=0;}
              //~Figura ();                 
             virtual float Pole()=0; //Czysto wirtualna metoda
             virtual char* pob_col()=0; // Przekazujemy wartosc tego pola przez wskaznika w celu 
                                         // zachowania integralnosci i spojnosci danych !
       
       void ustaw_typ(int t){typ=t;}
         char* send()
               {return color;}
      
      float send_1()
               {return pole;}
      };
//klasy pochodne od klasy bazowej "Figura" hierarchia p³aska
//dziedziczymy z takimi samymi prawami dostepu do pol co w kalasie bazowej
class prostokat : public Figura 
{
      protected:
                float bok_a,bok_b;
      public:
             float Pole();
             char* pob_col();
      };
/*Redefinicje kolejnych metod wirtualnych*/
float prostokat::Pole()
{ 
                         
         printf("Podaj 1 bok \n");
         scanf("%f",&bok_a);
         printf("Podaj 2 bok \n");
         scanf("%f",&bok_b);
         pole=bok_a*bok_b;
         return pole;
}
char* prostokat::pob_col(){printf("Podaj kolor figury \n");scanf("%s",color); return color; }
/*-----------------------------*/
class kolo : public Figura
{
      
      protected:
                float promien;
                
      public:
            
            float Pole(); //def. metody v.
            char* pob_col();
      };

float kolo::Pole()
{ 
      
      printf("Podaj promien\n");
      scanf("%f",&promien);
      pole=3.14*promien;
      return pole;
      }
char* kolo::pob_col(){printf("Podaj kolor figury \n");scanf("%s",&color); return color;}
/*----------------------------*/
class trojkat : public Figura 
{
       protected:
             float podstawa,wysokosc;   
      public:
             float Pole();
             char* pob_col();
      };    
float trojkat::Pole()
{ 
      printf("Podaj dl. podstawy\n");
      scanf("%f",&podstawa);
      printf("Podaj wysokosc\n");
      scanf("%f",&wysokosc);
      pole=(1/2)*podstawa*wysokosc;
      return pole;
      }

char* trojkat::pob_col(){printf("Podaj kolor figury \n");scanf("%s",&color);return color; }




/*Zmienne globalne*/

Figura *obiekt;
float p;
vector<Figura*> v;
int i=0,j=0,z;

/*Program wlasciwy*/
int main ()

{
/*menu:
     system("cls");
     printf("wybierz opcje \n");
     printf("------------------ \n");
     printf("1 dodawanie figury \n");
     printf("2 Wyswietl wszystkie dane figur \n");
     printf("3 Zapisz dane do pliku \n");
     scanf("%d",&o);

switch(o){
    case 1:
         system("cls");
         printf("Jakiego typu figure chcesz dodac ?\n");
         printf("1 Prostokat \n");
         printf("2 Kolo \n");
         printf("3 Trojkat \n");
         scanf("%d",&z);
         
         obiekt = new prostokat;
         obiekt->Pole();
         obiekt->pob_col();
         obiekt->Pole();
         obiekt->ustaw_typ(z);
         v.push_back(obiekt);
         
         switch(z){
                  case 1: system("cls");
                           obiekt = new prostokat;
                                                   i=m_i;j=m_j;
                          printf("%d",i);    
                          printf("%d",j);
                         
                          
                          obiekt->Pole();
                          obiekt->pob_col();
                          v.push_back(obiekt);
                         
                           
                          
                         
                         
                          delete obiekt;
                          system("pause");
                         
                          break; 
                  
                  case 2: system("cls");
                          v1.push_back(2);
                          v1.push_back(obiekt2->Pole());
                          v2.push_back(obiekt2->pob_col());
 
                          break;
                  
                  case 3: system("cls");  
                          v1.push_back(3);
                          v1.push_back(obiekt3->Pole());
                          v2.push_back(obiekt3->pob_col());
 
                          break;
                  }
         break;
    
                              
                              
                                                                 //1 - rodzaj i pole
        case 2: system("cls");                                   //2 - color
                       i=0;
                printf("Wyswietl wszystkie figury\n");
                printf("\n");
                for(j=0; j < v.size() ;j++)
                          {
                             
                             
                             printf("%s\n",v[j]->send());
                             printf("%f\n",v[j]->send_1());
                             
                            
                            
                          }
                         
                         
                system("pause"); 
                
                
                break;
        
        case 3: system("cls"); 
                printf("Zapisz dane do pliku");
                break;
         
        
         }

 goto menu;*/
 
 /*
 for i = 0 to x
     for j = i+1 do x
         if v[i]->typ == v[j]->typ
         prit "te 2 obiekt sa rowne"
     end
 end
 */
 
 obiekt = new prostokat;
 obiekt->Pole();
 obiekt->pob_col();
 v.push_back(obiekt);
 obiekt = new prostokat;
 obiekt->Pole();
 obiekt->pob_col();
 v.push_back(obiekt);
 obiekt = new prostokat;
 obiekt->Pole();
 obiekt->pob_col();
 v.push_back(obiekt);
 
 for(int i = 0; i <= 2; i++)
 {
         cout << v[i]->send() << " : " << v[i]->send_1() << "\n";
 }
 
system("pause");       
}
