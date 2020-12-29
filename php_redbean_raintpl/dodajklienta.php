<?php

include './inc/rain.tpl.class.php';
include 'KlientControler.php';

$tpl = new RainTPL;

$title = "Dodaj nowego klienta";
$tpl->assign("title", $title);

if (isset($_POST['dodaj'])) {

    $klientControler = new KlientController();
    
    $newClientId = $klientControler->dodaj($_POST);
    //todo make me better!
    $html = "</br><a href=./dodajpojazd.php?clientId=".$newClientId.">Dodaj pojazd dla nowego klienta</a>";
    $tpl->assign('message', 'Prawidłowo dodano klienta' .$html);
}

$html = $tpl->draw('new_client');