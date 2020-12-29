<?php

include './inc/Model/KlientModel.php';
include './inc/Model/PojazdModel.php';
include './inc/Model/TypPojazduModel.php';
include './inc/Model/NaprawaModel.php';

include 'KlientControler.php';

include './inc/rain.tpl.class.php';
require_once('./inc/function.php');
//echo 'Current PHP version: ' . phpversion();

$tpl = new RainTPL;

$title = "Strona główna";
$tpl->assign("title", $title);
//CLIENTS
// $user = R::load('Klient', 1); 
$clients = new KlientModel();


$total = $clients->countAllRows();
$liczba_na_stronie = 10;
$current_page = isset($_GET['page']) ? $_GET['page'] : 1;

// pierwszy parametr w klauzuli LIMIT
$skip = ($current_page - 1) * $liczba_na_stronie;
$num_page = ceil($total / $liczba_na_stronie);


//$user[] = $users->getRow(1);
//VEHICLES
$sortuj = isset($_GET['sort']) ? $_GET['sort'] : 'id';
$client = $clients->getAllRows(true, $skip, $liczba_na_stronie, $sortuj);
//$test = $clients->getAssoc(1,"imie");
$clientBeans = R::convertToBeans('client', $client);
//print_r($clientBeans);
//print_r($clients->getClientBySurname("Komor"));


$vehicles = new PojazdModel();
$vehicle = $vehicles->getAllRows();

//VEHICLE TYPE
$vehicleType = new TypPojazduModel();
//$vehicleType->getAllRows();
//print_r($vehicleType->getAllRows());
// NAPRAWA 
$rapair = new NaprawaModel();
//print_r($rapair->getAllRows());
//print_r($repair->getAllRows());
//$user[] = $users->getAllRows()
//var_dump($users->getAllRows());
//foreach ($user as $key => $value) {
//    echo $key.' '.$value;
//};
//assign 'dane' to template
$tpl->assign("vehicles", $vehicle);
$tpl->assign("clients", $client);

// szukaj MAKE ME BETTER
if (isset($_POST['szukaj'])) {

    $wartosc = $_POST['wartosc'];
    $kryterium = $_POST['kryterium'];

    switch ($kryterium) {
        case "Nazwisko":
            $tpl->assign("checked_nazwisko", "checked");
            $findsClient[] = $clients->getBySurname($wartosc);
            break;
        case "Pesel":
            $tpl->assign("checked_pesel", "checked");
            $findsClient[] = $clients->getByPesel($wartosc);
            break;
        case "Telefon":
            $tpl->assign("checked_telefon", "checked");
            $findsClient[] = $clients->getByTelefonNumber($wartosc);
            break;
    }


    if (count($findsClient[0]) > 0) {
        $tpl->assign("findsClient", $findsClient);
    }
    $tpl->assign("wartosc", $wartosc);
}
//checkbox usage
//foreach ($_POST['idclients'] as $clients){


$tpl->assign("num_page", $num_page);
$tpl->assign("sortuj", $sortuj);
$tpl->assign("current_page", $current_page);
$listOfTables = R::inspect();

$tpl->assign("dataBaseTable", $listOfTables);

$html = $tpl->draw('index');
