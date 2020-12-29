<?php 

    include './inc/Model/PojazdModel.php';
    include './inc/Model/TypPojazduModel.php';
    include './inc/Model/NaprawaModel.php';

    // pojazd kontroler
    include 'VehicleController.php';    
    //klient
    include 'KlientControler.php';
    
    include './inc/rain.tpl.class.php';
    require_once('./inc/function.php');

    $tpl = new RainTPL;

    $title = "Maszyny";
    $tpl->assign( "title", $title );
    
    
    // pobierz dane klienta po identyfikatorze
    $clientController = new klientController();
    $clientDetails = $clientController->getClientById($_GET['klientId']);
    
    //klient data
    $tpl->assign("clientDetails", $clientDetails);
    //pobierz wszystkie pojazdy dla danego klienta 
    $vehicleController = new VehicleController();
    $vehicleData = $vehicleController->viewByClientId($_GET['klientId']);

    $tpl->assign("vehicles", $vehicleData);

    
        //render
    $html = $tpl->draw('vehicle');    