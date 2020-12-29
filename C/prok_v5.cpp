//BIBLIOTEKI 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>
#include <conio.h>
#include <iostream>
struct osoba //PROSCIUTKI POJEDYNCZY ELEMENT LISTY
               
               {  
                  char nazwisko[20];
                  int nr_id;
                  float poprzedni_odczyt;
                  float nowy_odczyt;
                  struct osoba *prev;
                  struct osoba *next;
                                       }; 

/* Zmienne Globalne */

int g; // Zmienna do CASE`a
const float first=500;//do warunkow
float w; //zuzycie wody
float sum; //zuzycie all H20
float kasa; // siopa za pobrana cenna wode na tym marnym swiecie.
//Deklaracja + Definicja
float full=0.00;
float middle=0.00;
float siopsko=0.00;
int k=0; // Libczba uzytkownikow
//Pusta Glowa i ogon.
struct osoba *head; //G³owa listy powiazaniej. 
struct osoba *end; // Ogon listy.

/*Deklaracje Funkcji Programowych*/

void Add(struct osoba **head, struct osoba **end);
void Show(struct osoba **head, struct osoba **end);
struct osoba *Search(struct osoba **head, struct osoba **end);
void Del(struct osoba **head, struct osoba **end);
void sort(struct osoba **head, struct osoba **end);
void save(struct osoba **head, struct osoba **end);
void open(struct osoba **head, struct osoba **end);
void clean(struct osoba **head, struct osoba **end);
void edit(struct osoba **head, struct osoba **end);
bool przewin(struct osoba **head, struct osoba **end,char *nazwisko);

void kolorki(short int a);
/*PROGRAM WLASCIWY*/

int main()

{
    system("cls");
    kolorki(249);
    printf("Witamy !\n");
    printf("Program H2o v2.0 - masa poprawek+nowe funkcje\n "); 
    printf("Autor : FurmanS\n\n");
    printf("Dowolny klawisz alby przejsc do menu programu");
    getchar();
    kolorki(252);
    system("cls");
    //system("pause");
    menu:
    printf("H2o v. 2.0  \n\n");
    printf("MENU\n\n\t");
    printf("(1) Dodawanie Pracownika\n\n\t(2) Wyswietlanie \n\n\t(3) Szukanie wg nazwiska \n\n\t(4) Usuwanie\n\n\t(5) Sortowanie\n\n\t(6) Zapis\n\n\t(7) Odczyt\n\n\t(8) Czysc pamiec\n\n\t(9) Edytuj\n\n\t(10) Wyjscie z programu\n\n  ");
    printf("Dane ogolne : \n");
    printf("--*--*--*--*--*--*--*--*--*-- \n");
    printf("SUMA OPLAT ZA PIERWSZE 500 LITROW WODY  %10.2f\n", full);
    printf("SUMA OPLAT ZA PRZEKROCZENIE LIMITU  %10.2f\n" , middle);
    printf("SUMA OPLAT OGOLEM  %10.2f \n", siopsko);
    printf("\n");
    printf("Liczba naszych zadowolonych uzytkownikow %d\n", k);
    printf("--*--*--*--*--*--*--*--*--*-- \n");
    printf("WYBIERZ OPCJE !\n\t");
    scanf("%d",&g);
        
    switch(g)
    {
             case 1:
                     system("cls");
                     Add(&head, &end);
                     break;          
    
             case 2:
                    system("cls");
                    Show(&head, &end);
                    system("cls");
                    break;   
                    
                    
                    
             case 3:
                    system("cls");
                    Search(&head, &end);
                    break;                 
                        
             case 4:
                    system("cls");
                    Del(&head, &end);
                    break;             
             
             case 5:
                    system("cls");
                    sort(&head, &end);
                    break;                    
              
             case 6:
                    system("cls");
                    save(&head, &end);
                    break;          
              
              case 7:
                    system("cls");
                    open(&head, &end);
                    break;                  
                           
              case 8:
                    system("cls");
                    clean(&head, &end);
                    break;  
              
              case 9:
                    system("cls");
                    edit(&head, &end);
                    break;              
              
              case 10:
                   system("cls");
                   save(&head, &end);
                   clean(&head, &end);
                   goto koniec;                         
                           
             default: 
                      save(&head, &end);
                      goto koniec;    
                           }


goto menu;

koniec:
printf("Dziekuje !\n");    
system("pause");

}



/* DEFINICJE FUCKJI */
  
   //I FUCKJCA
   void Add(struct osoba **head, struct osoba **end)
                   
                   {
                        /*Zmienne Lokalne Funckji "Add"*/
                        struct osoba *nowy = NULL; //zmienna wskaznikowa typu osoba.
                        float w1;
                        char b;                   
                         bool a;//zmienna boolowska                      
                        
                       do {
                        nowy=new(osoba); //utorzenie struktury typu osoba i przypisanie jej do zmiennej "nowa".
                        
                        nowy->next = NULL;//wartosc wskaznika na nastepny element   
                        nowy->prev = NULL;//wartosc wskaznika na poprzedni element
                        
                        /*Uzype³nianie pystej struktury typu osoba*/
                        dodaj:
                        printf("Podaj nazwisko pracownika \n");
                        scanf("%s",nowy->nazwisko);
                        a=przewin(head,end,nowy->nazwisko);
                        if (a==true) 
                                     {            
                                                  printf("Jest juz taka osobao takim nazwisku!\n"); 
                                                  printf("Nacisni przycisk aby dodac te osobe jeszcze raz\n");
                                                  printf("Propozycja: mozesz poindeksowac nazwiska\n");
                                                  system("pause");
                                                  system("cls");
                                                  goto dodaj;
                                      }
                        k+=1;
                        printf("Podaj ID_klijenta \n");
                        scanf("%d",&nowy->nr_id);
                        printf("Podaj poprzedni odczyt licznika \n");
                        scanf("%f",&nowy->poprzedni_odczyt);
                        printf("Podaj nowy odczyt \n");
                        scanf("%f",&nowy->nowy_odczyt);
                        
                        w1=nowy->poprzedni_odczyt+nowy->nowy_odczyt;
                        if (w1>0)
                        
                        full=full+0.05;//Suma oplat za pierwsze 500 litrow h2o
                        if (w1>first)
                        middle=middle+(w1-first)*0.02;//oplata za przekroczenie limitu
                        
                        siopsko=middle+full;//Suma siopy do wziecia od plebu
                        
                        /*Ustawienie nowego elementy jako "head" listy*/
                        if(*head == NULL)
                                
                                {
                                    *head = nowy;
                                    (*head)->next = NULL;
                                    (*head)->prev = NULL;
                                    *end = *head;
                                    (*end)->next = NULL;
                                    (*end)->prev = NULL;
                                    //return;
                                }
                        
                        
                        /*W przeciwnym wypadku przypisanie nowego elementy na konice listy*/
                                    else
                                        {
                                           (*end)->next = nowy;
                                            nowy->prev = (*end);
                                           (*end) = nowy;
                                            //return;      
                                         }
                    
                                         printf("Dodac jeszcze jednego (t)-tak  (n)-nie\n");
                                         scanf("%s",&b);
                                         system("cls");
                           }while (b!='n' );
                           //return;                     
                     }
    
    //II FUCKJCA
    void Show(struct osoba **head, struct osoba **end)
    
                     {
                           /*Zmienne Lokalne Funckji "Show"*/
                           struct osoba *scroll;
                           
                           scroll=*head;
                           if (scroll->nazwisko != NULL)
                                        /*Wyswietlanie - "Przewijanie listy"*/
                                        {
                                        do {
                                            
                                            printf("---*--------*-------*----*\n");
                                            printf("Nazwisko: %s\n",scroll->nazwisko);
                                            printf("Nr_ID_klijenta: %d\n",scroll->nr_id);
                                            printf("Poprzedni odczyt z licznika: %10.2f\n",scroll->poprzedni_odczyt);
                                            printf("Nowy odczyt z licznika: %10.2f\n",scroll->nowy_odczyt);
                                            w=scroll->poprzedni_odczyt+scroll->nowy_odczyt;
                                            printf("Zuzycie wody: %10.2f\n",w );
                                            
                                            
                                            if (w<first) 
                                            
                                            {
                                               printf("Oplata za H2o wynosi :0.05 zl \n" );
                                                   printf("Oplata za dalsze zluzycie : BRAK - limit nie przekroczony\n");
                                                      printf("\n\t");
                                                       printf("Do zaplaty : 0.05 zl ");
                                                      printf("\n");
                                                      printf("---*--------*-------*-----*\n"); 
                                                       }
                                            else
                                                {
                                                       printf("Oplata za  PIERWSZE 500 LITROW H2o wynosi :0.05 zl \n" );
                                                       kasa=(w-first)*0.02;
                                                       printf("Oplata za dalsze zluzycie ( przekroczenie limitu) wynosi %10.2f \n",kasa );
                                                       kasa=(w-first)*0.02+0.05;
                                                       printf("\n\t");
                                                       printf("Do zaplaty %10.2f ", kasa );printf("zl");
                                                       printf("\n");
                                                       printf("---*--------*-------*-----*\n");
                                                       
                                                       }
                                            
                                            scroll=scroll->next;
                                            
                                            } while (scroll!= NULL);
                     
                      system("pause");
                       
                      return;
                      }
                      else 
                      {
                           system("cls");
                           printf("WYJATEK KRYTYCZNY !! BLAD !!\n");
                           system("pause");
                           system("cls");
                      }
    }
    //III FUCKJCA
    struct osoba *Search(struct osoba **head, struct osoba **end)
    
    {
         /*Zmienne Lokalne Funckji "Search"*/
         struct osoba *scroll;
         char name[20];                  
         
         printf("Wyszykiwanie po nazwiskoniu klijenta\n");
         printf("Podaj kogo wyszukac\n");
         scanf("%s",&name);
         scroll=*head;
    
    if (scroll->nazwisko != NULL)
      {
         do {
             
             if((!strcmp(name, scroll->nazwisko))) 
                               
                  {
                  printf ("Jest taka osoba !\n"); 
                  printf("----------------\n\t");
                  printf ("Oto jej dane: %s\n\n\t ", scroll->nazwisko);
                  printf ("Nr_id platnika %d\n\n\t", scroll->nr_id);
                  printf ("Poprzedni odczyt z licznika %10.2f\n\n\t", scroll->poprzedni_odczyt);
                  printf ("Nowy odczyt z licznika %10.2f\n\n\t", scroll->nowy_odczyt);
                  printf("\n");
                  printf("----------------\n");
                  printf("\n");
                  system("pause");
                  system("cls");
                  return scroll;
                  }
             
                  scroll = scroll->next;
            
            }  while (scroll!=NULL);
         
         printf("Brak Takiej Osoby w Bazie Danych\n");
         system("pause");
         system("cls");
         return NULL;
}
         else 
                     {
                           system("cls");
                           printf("Brak Takiej Osoby w Bazie Danych\n");
                           system("pause");
                           system("cls");
                           return NULL;
                      }
     
     
}
        
        //IV FUCKJCA    
      void Del(struct osoba **head, struct osoba **end)    
           {
              /*Zmienne Lokalne Funckji "Search"*/
              struct osoba *szukany;
              
              /*Wywolanie funkcji szukajacej*/
               szukany =Search( head, end );

              if ( szukany != NULL )
                 {
                   if (szukany->prev != NULL)
                   {
                   szukany->prev->next = szukany->next; // wskaznikd do wskaznika
                   }
                           else
                               {
                                       *head = szukany->next;
                               }

if ( szukany->next != NULL)
                   {
                     szukany->next->prev = szukany->prev; 
                   }
                       else
                           {
                                         *end = szukany->prev;
                           }

printf("O.K - usunieto poprawnie !  %s \n", szukany->nazwisko);
free(szukany);//Zwolnienie pamieci.
}        
     
     
          }   
          
//FUNKCJIA V

void sort(struct osoba **head, struct osoba **end)

{
struct osoba *osoba = NULL ,*biez = NULL, *pom = NULL ,*pop = NULL ,*nast = NULL;
      

                osoba = *head;
                if (osoba!=NULL && osoba->next!=NULL)
{
                biez=osoba->next;
      
do //poczatek pentlji zewnetrznej 
{
   pom=biez;
   do //petla wewnetrzna
   {
   if(strcmp(pom->nazwisko, pom->prev->nazwisko)<0)//sprawdzamy czy element nalezy przestawic zgodnie z alfabetem
   {
   nast=pom->next;
   pop=pom->prev;
   pom->prev=pop->prev;
   if ((pop->prev) !=NULL)
   {
   pop->prev->next=pom;
   pom->prev = pop->prev;
}
else
*head = pom;
pop->next=nast;
if (nast != NULL)
nast->prev=pop;
else
{
*end = pop;
}
pop->prev=pom;
pom->next=pop;
pom=pop;
                               
}
pom=pom->prev;
}while (pom->prev!=NULL);
biez=biez->next;
}while (biez!=NULL);
system("cls");       
} 
else
                     {
                           system("cls");
                           printf("Nie moge posorowac-za malo elementow\n\n\t\t");
                           system("pause");
                           system("cls");
                     }

}
 //FUNKCJIA VI Zapisywanie do Pliku


 void save(struct osoba **head, struct osoba **end)
 { 
      FILE* file = fopen("pracownicy.txt","w"); 
      struct osoba *pupa; 
      pupa = *head; //przewiniecie listy
       char nazwa;
//printf("Podaj nazwe pliku w ktorym chcesz zpisac swoje dane\n");
//scanf("%s",&nazwa);
//FILE* file = fopen("pracownicy.txt","w");
      
      
      if (file!=NULL) 
      {  
                   while(pupa != NULL)  //Dopoki nie koniec struktury zapisuj do pliku odpowiednio:
                      {     
                      fprintf(file,"%s\t",pupa->nazwisko); 
                      fprintf(file, "%d\t",pupa->nr_id);
                      fprintf(file, "%f\t",pupa->poprzedni_odczyt);
                      fprintf(file, "%f\t",pupa->nowy_odczyt);
                      fprintf(file, "%f\t",full);
                      fprintf(file, "%f\t",middle);
                      fprintf(file,"%f\t",siopsko);
                      pupa= pupa->next;  
                      }
                   fclose(file);
      }
system("cls");
} 
                        

//FUNKCJIA VII Wczytywanie z Pliku

void open(struct osoba **head, struct osoba **end)
  {
  
  FILE* file = fopen("pracownicy.txt","rb");//rb
   struct osoba *pupa = NULL;
    *head = NULL; //glowa listy
    *end = NULL;  // ogon listy
   

if (file!=NULL) //jezeli plik jest <> NULL
        
{
  pupa=new(osoba); //przydzielenie nowej pamieci dla pustej struktury
          
          while(fscanf(file,"%s\t%d\t%f\t%f\t%f\t%f\t%f",&pupa->nazwisko,&pupa->nr_id,&pupa->poprzedni_odczyt,&pupa->nowy_odczyt,&full,&middle,&siopsko) != EOF)           
             {
              if(*head == NULL)
                       {    (*head)=pupa;
                            pupa->prev=NULL;
                            pupa->next=NULL;
                            (*end)=*head;
                            k+=1;
                        }

                else
                    {
                              pupa->prev=*end;
                              (*end)->next=pupa;
                              (*end)=pupa ;
                              pupa->next=NULL;
                              k+=1;
                    }
                    pupa = new(osoba);
               } // zamkniecie petli WHILe

}// Zamkniecie pierwszego If`a

system("cls");
} //Zamkniecei funkcji OPEN
      

//Funkcja czyszczaca pamiec operacyjna.

void clean(struct osoba **head, struct osoba **end)

     {
               struct osoba *scroll;
               struct osoba *kolejny;
                           
                           scroll=*head;
                           if (scroll!= NULL && scroll->nazwisko!= NULL )   
                           {
                               do 
                                    {
                                      kolejny=scroll->next;
                                      
                                      scroll->prev=NULL;
                                      scroll->next=NULL;
                                      scroll=NULL;
                                      free(scroll);
                                      scroll=kolejny;
                                   
                                    }  while (scroll!= NULL);
                          
                           
                           
                           
                           free(scroll);
                          
                           }
               free(scroll);
               (*head)=NULL;
               (*end)=NULL;
              
               full=0.00;
               middle=0.00;
               siopsko=0.00;         
               k=0;  
      system("cls");            
     }

//Funkcja do edycji wybranego elementu przez uzytkownika
void edit(struct osoba **head, struct osoba **end)
{
     struct osoba *edit;
     int e;
     edit =Search( head, end );
     
     if (edit!=NULL)
     {
                    printf("----------------\n\t");
                    printf ("Oto jej dane: %s\n\n\t ", edit->nazwisko);
                    printf ("Nr_id platnika %d\n\n\t", edit->nr_id);
                    printf ("Poprzedni odczyt z licznika %10.2f\n\n\t", edit->poprzedni_odczyt);
                    printf ("Nowy odczyt z licznika %10.2f\n\n\t", edit->nowy_odczyt);
                    printf("\n");
                    printf("----------------\n");
                    printf("\n");
                    
                    
                    printf("Prosze podaj ktore pole chcesz zaktualizowac\n\t");
                    printf("(1) Edycja Nazwiska\n\t(2) Edycja numeru Id\n\t(3) Popraw stary odczyt\n\t(4) Popraw nowy odczyt\n\n");
                    printf("Anuluj - zatwierdz dowolna inna cyfre enterem ");
                    scanf("%d",&e);
    
                                   switch(e)
                    
                                            {
                                                    case 1:
                                                           
                                                            printf("Podaj nowe Nazwisko\n");
                                                            scanf("%s",edit->nazwisko);
                                                            system("cls");
                                                            break;   
                                                    case 2:
                                                            
                                                            printf("Podaj nowy Nr_id\n");
                                                            scanf("%d",&edit->nr_id);
                                                            system("cls");
                                                            break;
                                                    case 3:
                                                         
                                                            printf("Popraw stary odczyt z licznika\n");
                                                            scanf("%f",&edit->poprzedni_odczyt);
                                                            system("cls");
                                                            break;
                                                    case 4:
                                                    
                                                            printf("Popraw nowy odczyt z licznika\n");
                                                            scanf("%f",&edit->poprzedni_odczyt);
                                                            system("cls");
                                                            break;
                                                    
                                                    default:
                                                            break;
                                                            ;
                                            }
                        
                                                  
                    
    }//Koniec IF`a
 
 
 
 
 
 }//Koniec Funkcji

// Funkcja ta zwraca TRUE lub FALSE w zaleznosci od tego czy by³a taka osoba na liscie czy nie
bool przewin(struct osoba **head, struct osoba **end,char *nazwisko)

{
         struct osoba *scroll;
                           
                           scroll=*head;
                           if (scroll->nazwisko != NULL)
                              {
                               do {
             
                                  if((!strcmp(nazwisko, scroll->nazwisko))) //jest taka osoba
                                   return true;       //to zwroc wartosc logiczna TRUE              
                                  scroll=scroll->next;
                                  
                                  } while (scroll!= NULL);      
                               return false;
                               }
                           return false;
 }
 

// funkcja kolorki z wykorzystaniem handle ;]

void kolorki(short int a)

{

     

     HANDLE handle = GetStdHandle( STD_OUTPUT_HANDLE ); // uzywamy f. HANDLE

     SetConsoleTextAttribute( handle, a ); // ustawiamy kolor tekstu

     }



//KOOOOONIEC !



/* // Smieci 
     
     void sort(struct osoba **head, struct osoba **end)
     
      {
          struct osoba *pom, *nast ,*pop;
         char *wart1,*wart2;
          //char p,o;
          int zn;
 
 pom=*head; //G£OWA LISTY  
 

 
 do
{
 zn=0; //ZMIENNA DO LOGICZNA TZN. JEZELI 0 TO NIE ZMIENIL JEZELI 1 TO ZMIENI
 do
 {
 wart1=pom->nazwisko;//wartosc elementu
 pop=pom->prev; //wskazanie na poprzedni element
 nast=pom->next; //wskazanie na nastepny element
 wart2=nast->nazwisko;//wartosc elemnetu nastepnego
 if(strcmp(wart1,wart2)>0) //jesli element jest wiekszy od nastepnego, to zamienia wartosci
 {
 if (pom->prev !=NULL)
{
 pop->next=nast;//Poprzedni pokazuje na nastepny
 nast->prev=pop;//
 
 pom->next=nast->next;
 nast->next=pom;
 pom->prev=nast;
}
 /*p=*wart2;
 o=*wart1;
 *(pom->nazwisko)=p; //WARTOS2 JEST MNIEJSZA OD WARTOSCI1
 *(znaj->nazwisko)=o;*/
 
 //zn=1;//znaczy, ze zamienil wartosci elem.
 //}
 //pom=pom->next; //wskazanie na nastepny elem.
 //} while (nast->next!=NULL);

 //pom=*head; // PO SKONCZENIU PETLI ZNOWU WRACAMY DO POCZATKU LISTY  
 //} while (zn==1); //...AZ BRAK PRZESTAWIEN NA LISCIE 

 //} 
          
    /* V FUNKCJA  
     
     void sort(struct osoba **head, struct osoba **end)
     
      {
          struct osoba *biez=NULL, *nast=NULL ,*pop=NULL,*pom=NULL;
          char *wart1,*wart2;
          int zn;
          
          //if(*head!=NULL)
           
            biez=*head;
          
    do
{
 zn=0;
          do{
          wart1=biez->nazwisko;//wartosc elementu biezacego
          pop=biez->prev; //wskazanie na poprzedni element
          nast=biez->next; //wskazanie na nastepny element
          wart2=nast->nazwisko;//wartosc elemnetu nastepnego
          
          

          if(strcmp(wart1,wart2)<0)
              {
              if (biez->prev=NULL)
             {
               biez->prev=nast;
               biez->next=nast->next;
               nast->next->prev=biez;
               nast->next=biez;
               nast->prev=NULL;
                zn=1 ;             
                              }
                              else
                              {
                                  pop->next=nast;
                                  nast->prev=pop;
                                  biez->next=nast->next;
                                  biez->prev=nast;
                                  nast->next=biez;
                                  zn=1;          
                                              }}
       biez=biez->next;
       } while (nast->next!=NULL);
biez=*head;
}while (zn==1);

}*/








