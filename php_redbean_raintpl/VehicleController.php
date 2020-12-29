<?php

require_once 'inc/Model/PojazdModel.php';

class VehicleController {

    function __construct() {
        
    }

    public function dodaj($params, $clientId, $update = false) {
        $pojazdModel = new PojazdModel();
        $bean = R::dispense('pojazd');
        
        //$bean->id = $params['id'];
        $bean->nazwa = $params['nazwa'];
        $bean->pojemnosc = $params['pojemnosc'];
        $bean->rok_produkcji = $params['rok_produkcji'];
        $bean->numer_rejestracyjny = $params['numer_rejestracyjny'];
        $bean->klient_id = $clientId;
        // pojazdTypeID
        $bean->pojazd_typ_id = $params['type_id'];
        if ($update) {
            $bean->utworzono = date("Y-m-d H:i:s");
        }
        // get row id
        $id = $pojazdModel->addRow($bean);

        return $id;
    }

    public function viewByClientId($clientId) {

        $vehicles = new PojazdModel();

        $vehicle = $vehicles->getAllVehiclesByClientId($clientId);

        return $vehicle;
        //assign 
        //$tpl->assign("vehicles", $vehicle );
        //render
        //$html = $tpl->draw('vehicle');
    }

    public function getVehicleByVehicleId($vehicleId) {

        $vehicle = new PojazdModel();

        return $vehicle->getRow($vehicleId);
    }

    public function getOwnRepairs($vehicleId, $repairStatus = null) {

        $vehicle = new PojazdModel();
        #return ($repairStatus) == null ? $vehicle->getOwnRepairByVehicleId($vehicleId) : $vehicle->getOwnEndedRepairByVehicleId($vehicleId);

        switch ($repairStatus) {
            case null:
                return $vehicle->getOwnRepairByVehicleId($vehicleId);
            case true:
                return $vehicle->getOwnEndedRepairByVehicleId($vehicleId);
            case false:
                return $vehicle->getOwnPendingRepairByVehicleId($vehicleId);
        }
    }

}
