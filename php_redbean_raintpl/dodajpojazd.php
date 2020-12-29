<?php

include './inc/rain.tpl.class.php';
include 'VehicleController.php';
include './inc/Model/TypPojazduModel.php';
include 'inc/Model/KlientModel.php';
$tpl = new RainTPL;

$title = "Dodaj nowy pojazd";
$tpl->assign("title", $title);
$typPojazduModel = new TypPojazduModel();

$tpl->assign("typypojazdow", $typPojazduModel->getAll() );

$klient = new KlientModel();
$imieNazwisko  = $klient->getNameSurnameByClientId($_GET['clientId']);

$tpl->assign('message', 'KLIENT ID DLA KTOREGO DODAWNY JEST POJAZD: '. $imieNazwisko); 
if (isset($_POST['dodaj'])) {

    $vehicleController = new VehicleController();
    
    $newVehicleId = $vehicleController->dodaj($_POST, $_GET['clientId'], false);
    
    $html = "</br><a href=./dodajpojazd.php?clientId=".$newClientId.">Zarejestrowac naprawę dla nowego pojazdu?</a>";
    
    $tpl->assign('message', 'Prawidłowo dodano nowy pojazd ' .$html);
}

$html = $tpl->draw('new_vehicle');