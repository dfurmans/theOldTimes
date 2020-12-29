<?php

// pojazd
include 'VehicleController.php';
//klient
include 'KlientControler.php';
// pozycje naprawy
include 'RepairsPositionController.php';
// typ pojazdu
include 'inc/Model/TypPojazduModel.php';
// naprawa model
require_once 'inc/Model/NaprawaModel.php';
include './inc/rain.tpl.class.php';
require_once('./inc/function.php');

$tpl = new RainTPL;

$title = "Karta napraw oraz pozycji napraw";
$tpl->assign("title", $title);

// pobierz dane klienta po identyfikatorze
$clientController = new klientController();
$clientDetails = $clientController->getClientById($_GET['klientId']);

// poiberz pojazd po indetyfikatorze pojazdu
$vehicleController = new VehicleController();
$vehicleDetails = $vehicleController->getVehicleByVehicleId($_GET['pojazdId']);

// pobierz wszystkie naprawy dla tego motocykla
$repairs = $vehicleController->getOwnRepairs($_GET['pojazdId']);
// szukajka dla napraw
if (isset($_POST['szukaj'])) {

    $wartosc = $_POST['wartosc'];
    $kryterium = $_POST['kryterium'];

    switch ($kryterium) {
        case "zakonczone":
            $tpl->assign("checked_zakonczone", "checked");
            $repairs = $vehicleController->getOwnRepairs($_GET['pojazdId'], true);
            break;
        case "trwajace":
            $tpl->assign("checked_trwajace", "checked");
            $repairs = $vehicleController->getOwnRepairs($_GET['pojazdId'], false);
            break;
        case 'wszystkie' :
            $tpl->assign("checked_wszystkie", "checked");
            $repairs = $vehicleController->getOwnRepairs($_GET['pojazdId'], null);
            break;
    }
}

$naprawaModel = new NaprawaModel();
$repairPositionList = $naprawaModel->getOwnRepairsPositionByRepairId(1);

//klient data
$tpl->assign("clientDetails", $clientDetails);
// motocykl 
$tpl->assign("vehicleDetails", $vehicleDetails);
// naprawy    
$tpl->assign("repairs", $repairs);
// // pozycje naprawy    
$tpl->assign("repairsPositions", $repairPositionList);
//render
$html = $tpl->draw('all_repair');

//EOF
//!!!!!!!!!!!!!!!!!!!!!
//POZYCJE NAPRAWY -- to do MAKE ME BETTER
function getAllRepairsPositionByRepairId($repairId) {

    $naprawaModel = new NaprawaModel();
    $repairPositionList = $naprawaModel->getOwnRepairsPositionByRepairId(1);

    return $repairPositionList;
}
