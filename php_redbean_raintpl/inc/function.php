<?php
//sekcja funkcje pomocnicze




// sprawdz czy jest na aneksie
function spr_aneks($id){


$url='https://www.mbank.net.pl/admin/isonannex.php?id='.$id;
	$ch = curl_init($url);
	curl_setopt($ch, CURLOPT_URL, $url);
	curl_setopt($ch, CURLOPT_HEADER, 0);
	// wylaczenie weryfikacji protokolu SSL/443
	curl_setopt($ch, CURLOPT_SSL_VERIFYPEER, false);
	// wylaczenie wyswietlania wynikow na standarodwe wyjscie
	curl_setopt($ch,CURLOPT_RETURNTRANSFER,true);
	$data = curl_exec($ch);

	switch($data){
			
			case 0:
				$data=false;
				return $data;
			case 1:
				$data=true;
				return $data;
			default:
				return $data;
	
		}


curl_close($ch);
	

}
// sprawdz na ktorej platformie

function spr_platforma($id){

$platforma='';
		switch ($id){
			case 1:
				$platforma='IAI';
				break;
			case 2:
				$platforma='PrestaShop';
				break;
			case 3:
				$platforma='osCommerce';
				break;
			case 4:
				$platforma='Allegro';
				break;
			default:
				$platforma='Another';
			}
return $platforma;
}


/*Pozostale mniej istotne*/


function przeladuj($strona){
	//$url=$_SERVER['HTTP_HOST'].dirname($_SERVER['PHP_SELF']).'/tester.php';
			switch ($strona){
			case 1:
				header('Location: ./www.php');
				break;
			case 2:
				header('Location: ./lista_ola.php');
				break;
			case 3:
				header('Location: ./lista_jira.php');
				break;
			}
	
	//$url=$_SERVER['PHP_SELF'];
	//header('Location:'. $url);
	}

// implementacja paginacji
function pagainacja($sortuj, $current_page, $num_page){
 $page_links = '';

    // Jeśli nie jest to pierwsza grupa wyników, należy wygenerować odnośnik do poprzedniej strony.
    if ($current_page > 1) {
      $page_links .= '<a href="' . $_SERVER['PHP_SELF'] . '?sort=' . $sortuj . '&page=' . ($current_page - 1) . '"><-</a> ';
    }
    else {
      $page_links .= '<- ';
    }

    // Przejście w pętli po stronach i wygenerowanie odnośników z numerami. 
    for ($i = 1; $i <= $num_page; $i++) {
      if ($current_page == $i) {
        $page_links .= ' ' . $i;
      }
      else {
        $page_links .= ' <a href="' . $_SERVER['PHP_SELF'] . '?sort=' . $sortuj . '&page=' . $i . '"> ' . $i . '</a>';
      }
    }

    // Jeśli nie jest to ostatnia grupa wyników, należy wygenerować odnośnik do następnej strony.
    if ($current_page < $num_page) {
      $page_links .= ' <a href="' . $_SERVER['PHP_SELF'] . '?sort=' . $sortuj . '&page=' . ($current_page + 1) . '">-></a>';
    }
    else {
      $page_links .= ' ->';
    }

    return $page_links;
  }
  
 // liczniki do nawigacji  
 function ile($p){
 
 //nowy obiekt do obslugi bazy danych
  $baza = new mysql(); 

// Łączenie się z bazą danych.
$baza->db_connect();
  
  // Pobieranie danych użytkownika z bazy.
    if($p=='p')
	$query = "SELECT * FROM mr_partner"; 
		else if ($p=='w') $query = "SELECT * FROM mr_www";
		else if ($p=='lj') $query = "SELECT * FROM mr_www WHERE integracja=1 AND zamowienie=0 AND data_testow<>'0000-00-00' AND data_testow IS NOT NULL";
		else if ($p=='lo') $query = "SELECT * FROM mr_www WHERE integracja=0 AND data_testow<>'0000-00-00' AND data_testow IS NOT NULL";
		else if ($p=='all') $query = "SELECT * FROM mr_www WHERE zamowienie=0";
	$baza->query($query);
	return $baza->num_rows();
} 
  
 ?>