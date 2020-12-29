<?php
include_once 'Model.php';

class KlientModel extends Model {
	
	protected $table="klient";
	
	function __construct()
	{
		$this->db=DB::getInstance();
	}

    public function getBySurname($surname){
        
        return  R::getRow('SELECT * from '.$this->table.' where nazwisko like ? limit 1',
        array('%'.$surname.'%'));
    }
        
    public function getByPesel($pesel){
        
        return  R::getRow('SELECT * from '.$this->table.' where pesel like ? limit 1',
        array('%'.$pesel.'%'));
    }
        
    public function getByTelefonNumber($tel){
    
        return  R::getRow('SELECT * from '.$this->table.' where numer_telefonu like ? limit 1',
        array('%'.$tel.'%'));
        
    }
    
    public function getNameSurnameByClientId($clientId) {

        $klient = R::findOne('klient', ' id = ? ', array($clientId));
        
        return $klient['imie']." ".$klient['nazwisko'];
    }
    
    
    public function addVehicle($newVehicle){
        
        
    }
}