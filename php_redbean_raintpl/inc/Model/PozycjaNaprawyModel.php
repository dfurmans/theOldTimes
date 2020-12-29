<?php
include_once 'Model.php';

class PozycjaNaprawyModel extends Model {

	protected $table='pozycjenaprawy';

	function __construct()
	{
		$this->db=DB::getInstance();
	}
	
	public function getAllRepairsPostionsByRapairId($repairId){

		return R::find($this->table,' naprawa_id = ? ',array( $repairId ));
	}

	
}