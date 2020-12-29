<?php

require_once 'inc/Model/KlientModel.php';

//include 'inc/rain.tpl.class.php';

class KlientController {

    function __construct() {
        
    }

    public function dodaj($params) {
        $klientModel = new KlientModel();
        $bean = R::dispense('klient');
        
        $bean->id = $params['id'];
        $bean->imie = $params['imie'];
        $bean->nazwisko = $params['nazwisko'];
        $bean->wiek = $params['wiek'];
        $bean->pesel = $params['pesel'];
        $bean->adres = $params['adres'];
        $bean->numer_telefonu= $params['numer_telefonu'];
        $bean->utworzono = date("Y-m-d H:i:s");
        
        // get row id
        $id = $klientModel->addRow($bean);

        return $id;
    }

    private function view() {

        $tpl = new RainTPL;
        //echo 'PHP VERIS' . phpversion();    
        // make me better
        $title = "SG";
        $tpl->assign("title", $title);
        //CLIENTS
        // $user = R::load('Klient', 1); 
        $clients = new KlientModel();


        //$user[] = $users->getRow(1);
        //VEHICLES
        $client = $clients->getAllRows();
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

        $tpl->assign("vehicles", $vehicle);
        $tpl->assign("clients", $client);

        $html = $tpl->draw('index');

        R::close();
    }

    public function getClientById($clientId) {

        $klientModel = new KlientModel();

        return $klientModel->getRow($clientId);
    }

}
