<?php

include_once 'Model.php';

class TypPojazduModel extends Model {

    protected $table = 'typpojazdu';

    function __construct() {
        $this->db = DB::getInstance();
    }

    static function getTypeNameByTypeId($typeId) {

        $pojazdType = R::findOne('typpojazdu', ' id = ? ', array($typeId));
        
        return $pojazdType['nazwa'];
    }

}
