<?php
    include './inc/Model/KlientModel.php';
    include './inc/Model/PojazdModel.php';
    include './inc/Model/TypPojazduModel.php';
    include './inc/Model/NaprawaModel.php';

    include './inc/rain.tpl.class.php';

class IndexController {
	
	function index()
	{
		//$this->view->assign('page_title','Edytor akcji');
		//$this->view->assign('mails',$this->model->getMails());
		//parent::index();
		
    $tpl = new RainTPL;
    //echo 'PHP VERIS' . phpversion();    
    // make me better
    $title = "SG";
    $tpl->assign( "title", $title );
    //CLIENTS
   // $user = R::load('Klient', 1); 
    $clients = new KlientModel();
    

    //$user[] = $users->getRow(1);
    //VEHICLES
    $client = $clients->getAllRows();
    //$test = $clients->getAssoc(1,"imie");
     $clientBeans = R::convertToBeans('client',$client);
    //print_r($clientBeans);
    print_r($clients->getClientBySurname("Komor"));

    
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
    $tpl->assign("vehicles", $vehicle );
    $tpl->assign("clients", $client );
     //print_r($vehicle);
        $html = $tpl->draw('index');
        

// close connection
    R::close();

		error_log("TUTAJ");
	}

}


?>