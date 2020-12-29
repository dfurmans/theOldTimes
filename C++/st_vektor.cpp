#include <iostream>
#include <vector>

using namespace std;


//___________________________________klasa kient
class klient 
{
private:
       int pin;
       
public:
int stan;
int nrko; 
int nrka;


void ustaw_pin(int p){
pin=p;
}

int pokaz_pin(){
return pin;
}


};

//-================================== klasa bank
class bank 
{
public:
       
klient k; 
vector <klient> gg;
void wypisz_all();
void dodanie();
void wplata();
void wyplata();
void szukanie();

void zapisz();
void wczytaj();


};

//_-----------------------------zadeklarowane globalnie wazne zmienne! i wektor
bank b;
klient k;




//----------------------------Funkcja wypisujaca all klientow

void bank::wypisz_all()
{
     cout << " " << endl;
   cout << ">>>> Dane Klientow: <<<<" << endl;
	cout << " " << endl;
for (int i = 0; i < gg.size(); i++)
{

    k=gg[i]; // trzeba wziac calosc i z calosci wyjac czesc
	cout << "nr klienta: "<< i+1 << endl;
	cout << "nr konta: " << k.nrko << endl;
	cout << "nr karty " << k.nrka << endl;
	cout << "stan: " << k.stan << endl;
	int pinn=k.pokaz_pin();
	cout << "pin: " << pinn << endl; 
	cout << " " << endl;
	
}  
     }

//---------------------------Funkcja: dodanie klienta
void bank::dodanie()

{
int d;
cout << " " << endl;
cout << "Dodawanie klienta: " << endl;
cout << " " << endl;
  
nrklienta:
cout << "podaj nr konta klienta" << endl;
cin >> d;

for (int i = 0; i < gg.size(); i++)
{
	k=gg[i];
     if(k.nrko ==d) 
     {
               cout << "taki nr juz istnieje! podaj inny" << endl;
               goto nrklienta;
               }
               }
 
int z;
nrkarty:
cout << "podaj nr karty" << endl;
cin >> z;
for (int i = 0; i < gg.size(); i++)
{
	k=gg[i];
     if(k.nrka ==z) 
     {
               cout << "taki nr juz istnieje! podaj inny" << endl;
               goto nrkarty;
               }
               }

k.nrko = d;
k.nrka = z;


cout << "podaj poczatkowy stan konta" << endl;
cin >> d;
k.stan = d;

//pin:
cout << "podaj pin" << endl;
cin >> d;


k.ustaw_pin(d);
gg.push_back(k);     
     }




//-------------------------Funkcja: wplata na konto
     
     
 void bank::wplata()
 {
      int sz2;
      cout << " " << endl;
      cout << " podaj nrkonta klienta ktoremu chcesz wplacic na konto" << endl;
cin >> sz2;


for (int i = 0; i < gg.size(); i++)
{
	k=gg[i];
     if(k.nrko ==sz2) 
     {
int w;
cout << "podaj kwote jaka chcesz wplacic" << endl;
cin >> w;
k.stan += w;
cout << "stan konta po operacji:" << k.stan << endl;
gg[i]=k;
	cout << " " << endl;

     }
}
      }    


//______---------------------------------__Funkcja: wyplata z konta

void bank::wyplata() {
int w;
int pp;
int pipin;
pipin=k.pokaz_pin();
int o;
cout << " " << endl;
cout << " podaj nrkonta klienta ktoremu chcesz wyplacic z konta" << endl;
cin >> o;

for (int i = 0; i < gg.size(); i++)
{
	k=gg[i];
     if(k.nrko ==o) 
{
     pipin=k.pokaz_pin();
do {
cout << "podaj pin" << endl;
cin >> pp;
if(pp != pipin)
cout << "zly pin, podaj jeszcze raz " << endl;
}while(pp != pipin);

cout << "podaj kwote jaka chcesz wyplacic" << endl;
cin >> w;
k.stan -= w;
cout << "stan konta po operacji:" << k.stan << endl;
gg[i]=k;
	cout << " " << endl;
	
     }
}
}

//________-------------------------___szukanie klienta
void bank::szukanie()
{
     int sz;
     cout << " " << endl;
     cout << " podaj nrkonta klienta ktorego szukasz" << endl;
      cin >> sz;



for (int i = 0; i < gg.size(); i++)
{
	k=gg[i];
     if(k.nrko ==sz) 
     {
               cout << " " << endl;
   cout << "Dane klienta: " << endl;   
    cout << "nr klienta: " << i+1 << endl;        
cout << "nr konta: " << k.nrko << endl;
	cout << "nr karty: " << k.nrka << endl;
	cout << "stan: " << k.stan << endl;
	int pinn=k.pokaz_pin();
	cout << "pin: " << pinn << endl; 
	cout << " " << endl;

     }
}
     }


//____________zapisz do pliku
void bank::zapisz()
{ 
      FILE* plik = fopen("baza.txt","w"); 
      
       
      if (plik!=NULL) 
      {  
		  for (int i = 0; i < gg.size(); i++)
		  {
			  k=gg[i];
                       
                                            fprintf(plik, "%d\n",k.nrko);
                      fprintf(plik, "%d\n",k.nrka);
                      fprintf(plik, "%d\n",k.stan);
					  int pinn=k.pokaz_pin();
                      fprintf(plik, "%d\n",pinn);
		  }                  
                     

                   fclose(plik);
      }
} 

//______________________wczytanie z pliku
void bank::wczytaj()
{
     gg.clear();
     int pinn;
 FILE* plik = fopen("baza.txt","a");
 fclose(plik);
 
 fopen("baza.txt","r");
 

    if (plik!=NULL) 
                    {

while(fscanf(plik,"%d\n%d\n%d\n%d\n",&k.nrko,&k.nrka,&k.stan,&pinn) != EOF)
{
                k.ustaw_pin(pinn);                                                    
             gg.push_back(k);                                                        
                                                                    }

                                                                    }				
 fclose(plik);
 b.wypisz_all();
} 
  




//______________________//////_____________glowny PROGRAM
int main() {


int sz;




//__------------------------menu programu
int m;
do {
    cout << " ------------------------------- " << endl;
cout << ">>>> MENU <<<<" << endl;
cout << "1. dodaj klienta" << endl;
cout << "2. wyszukaj klienta" << endl;
cout << "3. wplac na konto" << endl;
cout << "4. wyplac z konta" << endl;
cout << "5. pokaz wszystkich klientow" << endl;
cout << "6. wczytaj z pliku" << endl;
cout << "7. koniec" << endl;
cout << " " << endl;
cin >> m;

switch(m) 
{
//____dodanie klienta        
case 1:
b.dodanie();
b.zapisz();
break;

      //--- szukanie klienta
      case 2:
      b.szukanie();
      break;
      
            //____wplata na konto 
            case 3:
            b.wplata();
			b.zapisz();
            break;

                  //_____wyplata z konta
                  case 4:
                  b.wyplata();
				  b.zapisz();
                  break;

                        //_____wypisanie all klientow
                          case 5:
                          b.wypisz_all();
                          break;
                           	
								//_______wczytaj z pliku
						        case 6:
						        b.wczytaj();
						        break;
}
}while(m != 7);
}

