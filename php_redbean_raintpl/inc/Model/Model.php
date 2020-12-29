<?php

include_once 'DB.php';
include 'HelperLogger.php';

class Model {

    protected $table;
    
            
    
    function __construct() {
        $this->db = DB::getInstance();
    }

    function getAll() {
        return R::findAll($this->table, ' ORDER BY id');
    }

    public function getRow($id) {
        
         $reflector = new ReflectionClass($this);
        HelperLogger::Log('getRow + '. $id .' '. $this->table . $reflector, 'I');
        return R::load($this->table, $id);
    }

    public function addRow($row) {

        HelperLogger::Log('addRow + '. $row .' '. $this->table, 'I');
        $id = R::store($row);

        return $id;
    }

    public function countAllRows() {
        
        HelperLogger::Log('countAll+ '. $this->table, 'I');
        return R::count($this->table);
    }

    public function deleteRow() {
        
    }

    public function updateRow($id) {
        R::exec('update page set title="test" where id=1');
    }

    /**
     * TODO 
     * @param type $limit
     * @param type $limitValue
     * @param type $limitPerPageValue
     * @param type $sortuj
     * @return type
     */
    public function getAllRows($limit = false, $limitValue, $limitPerPageValue, $sortuj) {
        HelperLogger::Log('getAllRows + '. $this->table, 'I');
        return ($limit) ? R::findAll($this->table, 'ORDER BY ' . $sortuj . ' LIMIT ' . $limitValue . ' , ' . $limitPerPageValue) : R::findAll($this->table);
    }

    public function getClientBySurname($surname) {
        
        return R::find($this->table, ' nazwisko = ? ', array($surname));
    }

    public function getAssoc($id, $columName) {
        HelperLogger::Log('getAssoc + '. $id .' '. $this->table, 'I');
        R::$adapter->getAssoc('select id, ' . $columName . ' from ' . $this . table);
    }

// expeted result:
//     Array
//     (
//         [1] => frontpage
//         [2] => The Jazz Club
//         [3] => back
//     )
// 	ROW TO BEAN CONVERT
// $sql = 'SELECT author.* FROM author 
//         JOIN club WHERE club.id = 7 ';
//     $rows = R::getAll($sql);
//     $authors = R::convertToBeans('author',$rows);
}

?>