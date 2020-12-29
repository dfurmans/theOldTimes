<?php

require_once 'inc/Model/PozycjaNaprawyModel.php';

class RepairsPositionController {
	

	function __construct()
	{

    }

    public function getRepairsPositionListByRepairId($repairId){
    
	    $positionsOfRepairs = new PozycjaNaprawyModel();

	    $positions = $positionsOfRepairs->getAllRepairsPostionsByRapairId($repairId);
	    
	    return $positionsOfRepairs;
    }

}