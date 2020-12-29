<?php
include_once 'Model.php';

class NaprawaModel extends Model {

	protected $table='naprawa';
	

	function __construct()
	{
		$this->db=DB::getInstance();
		
	}

	public function getAllRepairByClientIdAndVehicleId($params){
		
		$paramsArray = $this->spltiArrayParams($params);
		
		$idParams['clientId']  = $paramsArray[0]; 
		$idParams['vehicleId'] = $paramsArray[1];

		$data =  R::find($this->table,' klient_id = :clientId AND pojazd_id = :vehicleId ', array( 
                ':clientId' => $paramsArray[0], 
                ':vehicleId' => $paramsArray[1]
            )
		);
		//print_r($data);
		return $data;
		//http://donna-oberes.blogspot.com/2013/04/passing-php-array-to-javascript-ajax.html
	}

	//TODO - utils class
	private function spltiArrayParams($stringParams){

		return explode('/',$stringParams);
	}

	// POBIERZ WSZYSTKIE POZYCJE DLA DANEJ NAPRAWY (IDENTYFIKATOR)
	public function getOwnRepairsPositionByRepairId($repairId){

		$vehicle = R::load($this->table,$repairId);
    	$repairsPosition = $vehicle->ownPozycjenaprawy; 	

		return $repairsPosition;
	}
        
        public function addRepairPositions($newRepairPostions){
            
            
        }
        
        public function closeRepair($repairId){
            
             R::exec( 'update '.$this->table.' set data_zdania = NOW() where id='.$repairId );
        }
}