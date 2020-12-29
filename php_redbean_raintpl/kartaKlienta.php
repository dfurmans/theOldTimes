<?php

include './inc/rain.tpl.class.php';
include 'KlientControler.php';
require_once('./inc/function.php');

$tpl = new RainTPL;

$id = $_GET["id"];

$clientController = new KlientController();
$clientaData = $clientController->getClientById($id);


if (isset($_POST['dodaj'])) {

    $klientControler = new KlientController();
    
    $newClientId = $klientControler->dodaj($_POST);
    //todo make me better!
    $tpl->assign('message', 'Prawidłowo zaktualizowano dane dla klienta' );
    //reload data
    $clientaData = $clientController->getClientById($id);
}

$tpl->assign("clientData", $clientaData);


$tpl->draw('clientCard');