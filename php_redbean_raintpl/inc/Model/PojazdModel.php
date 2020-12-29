<?php

include_once 'Model.php';

class PojazdModel extends Model {

    protected $table = 'pojazd';

    function __construct() {
        $this->db = DB::getInstance();
    }

    public function getAllVehiclesByClientId($klientId) {
        return R::find($this->table, ' klient_id = ? ', array($klientId));
    }

    public function getOwnRepairByVehicleId($vehicleId) {

        $vehicle = R::load($this->table, $vehicleId);
        
        $repairs = $vehicle->ownNaprawa;

        return $repairs;
    }
    
    public function getOwnEndedRepairByVehicleId($vehicleId){
        
        $vehicle = R::load($this->table, $vehicleId);
        
        $repairs = $vehicle->withCondition(" data_zdania <> '0000-00-00 00:00:00' AND data_zdania IS NOT NULL")->ownNaprawa;

        return $repairs;
        
    }
    public function getOwnPendingRepairByVehicleId($vehicleId){
        
        $vehicle = R::load($this->table, $vehicleId);
        
        $repairs = $vehicle->withCondition(" data_zdania == '0000-00-00 00:00:00' AND data_zdania IS NULL")->ownNaprawa;

        return $repairs;
        
    }
    
    public function addRepair($newRepair) {
        
    }

    public function getRegisterNumberByVehicleId($vehicleId) {

        $pojazd = R::findOne('pojazd', ' id = ? ', array($vehicleId));

        return $pojazd['numer_rejestracyjny'];
    }

}
