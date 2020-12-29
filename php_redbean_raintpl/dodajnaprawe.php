<?php

include 'inc/Model/PojazdModel.php';
include 'inc/Model/KlientModel.php';

include 'RepairController.php';
include_once './inc/rain.tpl.class.php';

$tpl = new RainTPL;


$title = "Dodaj nową naprawę";
$tpl->assign("title", $title);

$klient = new KlientModel();
$imieNazwisko  = $klient->getNameSurnameByClientId($_POST['klientId']);
$numerRejestracyjny = PojazdModel::getRegisterNumberByVehicleId($_POST['pojazdId']);
$tpl->assign('imieNazwisko', $imieNazwisko);
$tpl->assign('numerRejestracyjny', $numerRejestracyjny);

if (isset($_POST['dodaj'])) {

    $repairController = new RepairController();
    
    $newRepairId = $repairController->dodaj($_POST);
    $tpl->assign('message', 'Prawidłowo zarejestrowano nowa naprawe');
    $html = "</br><a href=./wydrukPotwierdzenia.php?repairId=".$newRepairId.">WYDRUK POTWIERDZENIA</a>";
    $tpl->assign('message', "Wydrukuj potwierdzenie ?" .$html);
    
}

$html = $tpl->draw('new_repair');




