<?php 
/*
Dawid Furman 
klasa do obslugi bazy MySql*/
// konfiguracja polaczenia
  require_once('connectvars.php');
  // do przepisania na MySQLi
class mysql{
	
//dostep
	var $host = DB_HOST;
	var $database = DB_NAME;
	var $user = DB_USER;
	var $pass = DB_PASSWORD;
//argumenty polaczeniowe
	var $link_db = 0; 
	var $query_id = 0;
	var $row = array();

	
//POLACZ Z BAZA DANYCH - tutaj uzywamy  @mysql_connect()
	
function db_connect($h='',$u='',$p=''){
		
		if ($h==''&& $u==''&&$p==''){
			
	//chwyt do polaczenia z baza danych. podpinamy pod argument $link_db
			
		@$this->link_db = mysql_connect($this->host,$this->user, $this->pass)
		or die('Brak połączenia z serwerem MySQL.<br />Błąd: '.mysql_error());
	// Wybieramy baze danych
		@mysql_select_db($this->database, $this->link_db) 
	// w przypadku niepowodzenia wyświetlamy komunikat 
		or die('Nie mogę połączyć się z bazą danych<br />Błąd: '.mysql_error());  
	// ustawiamy kodowanie na UTF-8  - pierwsze zapytanie :D
		mysql_query('SET NAMES utf8', $this->link_db);
	//zwracamy link do polaczenia
		return $this->link_db;
	}
}// koniec metody db_connect()
		
//ZAPYTANIE - tutaj używamy @mysql_query();
function query($qString){

//sprawdz czy mamy link do polaczenia z baza danych
	if ($this->link_db==0) return 0;
// jezeli puste zwroc 0
	if ($qString == '') return 0;
// zapisz Id zapytania / wykonaj SQL
	$this->query_id = @mysql_query($qString, $this->link_db)
	or die ('Nie mogę wykonać następującego zapytania SQL. Błąd: '.mysql_error());
//zwroc wynik zapytania
return $this->query_id;
}

//CZYTAJ - tutaj uzywamy @mysql_fetch_assoc - tablica asocjacyna - klucz - > wartosc ! more informatnion ? manual !
// dopisac funckje czyszczaca dane  $user_username = mysqli_real_escape_string($dbc, trim($_POST['username']));
function czytaj(){
	$this->row = @mysql_fetch_assoc($this->query_id);	
	$jest_tablica = is_array($this->row);
	// ustawiamy status TRUE/FALSE - w zaleznosci tego czy jest tablica
	return $jest_tablica;
}

// Zwroc wybraną kolumnę. Funkcja korzysta z tablicjy asocjacyjnej zdefinowanej za pomocą @mysql_fetch_assoc()
function f ($name) {
    return $this->row[$name];
  }
// Zwraca liczbę wierszy  ! - to samo co Select count(*) dla danego query_id
 function num_rows () {
    if (mysql_num_rows($this->query_id) != 0)
	return mysql_num_rows($this->query_id);
		else return 0;
  }

//future - nie znajome funckje. sprawdzic w manulau 		

  function affected_rows () {
    return @mysql_affected_rows ($this->link_db);
  }		
  
  function data_seek ($row_number) {
    return @mysql_data_seek ($this->query_id, $row_number);
  }

function zamknij_polaczenie(){
	mysql_close($this->link_db);
	}

  
}	

?>