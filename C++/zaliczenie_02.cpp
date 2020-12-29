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
            int rodzaj;
      public:
             /* Konstruktor*/
             Figura () {pole=0;}
              //~Figura ();                 
             virtual float Pole()=0; //Czysto wirtualna metoda
              virtual char* pob_col()=0; // Przekazujemy wartosc tego pola przez wskaznika w celu 
                                         // zachowania integralnosci i spojnosci danych !
    void get_pin(char* p) 
         {strcpy(p,color);}
    char* send()
         {return color;}
    
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
      pole=podstawa*wysokosc*0.5;
      //printf("%f",pole);
      system("pause");
      return pole;
      }

char* trojkat::pob_col(){printf("Podaj kolor figury \n");scanf("%s",&color);return color; }


/*Inne definicje danych metod*/


//Zapis danych - II vektory do 1 pliku
void save(vector<float> v1,vector<char*> v2)
{
     FILE* file = fopen("dane.txt","w"); //plik danych trybie "w"
    int i,j;
     
     
        for(j=0; j < v2.size() ;j++)
                      
                      {     
                       fprintf(file,"%s\t",v2[j]);
                       fprintf(file,"%f\t",v1[i]); 
                       i+=1;
                       fprintf(file, "%f\t",v1[i]);
                       i+=1;
                      }
                   fclose(file);
      
}

void open()
{
    vector<char*> v2;
    Figura *t; 
    FILE* file = fopen("dane.txt","rb"); 
      char col[20];
      char* k;
      float p;
      int r,i=0,j=0;
    // fopen("baza.txt","r");
      while(fscanf(file,"%s\t%d\t%f\t",&col,&r,&p) != EOF)
      {
         t->get_pin(col);
          v2.push_back(t);                                    
      }
    /* while(fscanf(file,"%s\t",&col) != EOF)
      {
         t->get_pin(col);
          //v2.push_back(t->send());                                    
          
     
     }*/
     fclose(file);
//printf("%s",v2[0]);
system("pause");
}




/*Zmienne globalne*/
int o;
int z;

Figura *obiekt1 = new prostokat; // gdy¿ jest to metoda abstrakcyjna !!
Figura *obiekt2 = new kolo;
Figura *obiekt3 = new trojkat;
float p;
vector<float> v1; //przechowuje rodzaj figury i jej pole
vector<char*> v2; // przechowuje jej color
int i=0,j=0,m_i,m_j;

/*Program wlasciwy*/
int main ()

{
menu:
     system("cls");
     printf("Wybierz opcje \n\n");
     printf("------------------ \n");
     printf("1 Dodawanie figury \n");
     printf("2 Wyswietl wszystkie dane figur \n");
     printf("3 Zapisz dane do pliku \n");
     printf("4 Otworz dane z pliku \n");
     scanf("%d",&o);

switch(o){
    case 1:
         system("cls");
         printf("Jakiego typu figure chcesz dodac ?\n");
         printf("1 Prostokat \n");
         printf("2 Kolo \n");
         printf("3 Trojkat \n");
         scanf("%d",&z);
         switch(z){
                  case 1: system("cls");
                          
                          i=m_i;j=m_j;
                          /*printf("%d",i);    
                          printf("%d",j);*/
                          printf("\n");
                          v1.push_back(1);// 1- prostokat 2-kolo 3-trojkat
                          i+=1;
                          v1.push_back(obiekt1->Pole());
                          v2.push_back(obiekt1->pob_col());
                          i+=1;
                          j+=1;
                          m_i=i;m_j=j;
                          obiekt1=new(prostokat);
                          system("pause");
                         
                          break; 
                  
                  case 2: system("cls");
                          
                          i=m_i;j=m_j;
                          /*printf("%d",i);    
                          printf("%d",j);*/
                          printf("\n");
                          v1.push_back(2);// 1- prostokat 2-kolo 3-trojkat
                          i+=1;
                          v1.push_back(obiekt2->Pole());
                          v2.push_back(obiekt2->pob_col());
                          i+=1;
                          j+=1;
                          m_i=i;m_j=j;
                          obiekt2=new(kolo);
                          system("pause");
                         
                          break; 
                  
                  case 3: system("cls");  
                          
                          i=m_i;j=m_j;
                          /*printf("%d",i);    
                          printf("%d",j);*/
                          printf("\n");
                          v1.push_back(3);// 1- prostokat 2-kolo 3-trojkat
                          i+=1;
                          v1.push_back(obiekt3->Pole());
                          v2.push_back(obiekt3->pob_col());
                          i+=1;
                          j+=1;
                          m_i=i;m_j=j;
                          obiekt3=new(trojkat);
                          system("pause");
                         
                          break; 
                  }
         break;
    
                              
                              
                                                                 /*v1 - rodzaj i pole*/
        case 2: system("cls");                                   /*v2 - color*/
                
                i=0;
                printf("Wyswietl wszystkie figury\n");
                printf("\n");
               
               for(j=0; j < v2.size() ;j++)
                          
                          {
                             
                             printf("Figura nr: %d\n",j+1 );
                             printf(" Color Figury : %s\n",v2[j]);
                             printf(" Rodzaj figury: %0.0f\n",v1[i]);
                             i+=1;
                             printf(" Pole Figury: %0.2f\n",v1[i]);
                             i+=1; 
                             printf("\n");
                             
                          }
                         
                         
                system("pause"); 
                
                
                break;
        
        case 3: system("cls"); 
                printf("Zapisz dane do pliku");
                /*Zapisaæ wektor v1 i v2 do pliku*/
                save(v1,v2);
                break;
        
        
        case 4: system("cls"); 
                
                /*Zapisaæ wektor v1 i v2 do pliku*/
               
                open();
                break; 
        
         }

goto menu;
system("pause");       
}
