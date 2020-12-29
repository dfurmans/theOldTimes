<?php

require_once 'inc/Model/NaprawaModel.php';

include './inc/rain.tpl.class.php';

class RepairController {

    private $params;

    function __construct($params) {
        $this->params = $params;
    }

    public function dodaj($params) {
        $naprawaModel = new NaprawaModel();
        $bean = R::dispense('naprawa');
        //fk form POST form DATA
        $bean->klient_id = $params['klientId'];
        $bean->pojazd_id = $params['pojazdId'];
        $bean->nazwa = $params['nazwa'];
        $bean->opis = $params['opis'];
        $bean->przebieg = $params['przebieg'];
        $bean->data_przyjecia = date("Y-m-d H:i:s");
        $bean->czy_zaplacono = isset($params['zaplacono']) ? 1:0;
        $bean->wartosc_naprawy = $params['wartosc'];
        // get new row id
        $id = $naprawaModel->addRow($bean);

        return $id;
    }

    public function getAllRepairs() {

        $tpl = new RainTPL;

        $repair = new NaprawaModel();

        $repairs = $repair->getAllRepairByClientIdAndVehicleId($this->params['id']);

        $tpl->assign("naprawa", $repairs);

        //render
        $html = $tpl->draw('repair');
    }

    public function getRepairsByVehicleId() {
        $repair = new NaprawaModel();

        return $repair->getAllRepairByAndVehicleId($vehicleId);
    }
    
    public function closeRepair(){
        $repair = new NaprawaModel();
        
        $repair->closeRepair($this->params['id']);
    }

    // public function getAllPositionsRepairListByVehicleIdAndRepairId($)
    // public function getOwnRepairsPositions($repairId){
    // 	$repair = new NaprawaModel();
    // 	return $repair->getOwnRepairsPositionByRepairId($vehicleId);
    // }
}
