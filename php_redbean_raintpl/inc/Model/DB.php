<?php
// only once PHP load loader!
include_once 'rb.phar';

/*
redbeanphp.com/manual3_0/quick_tour

	Field names:	Lowercase a-z, 0-9 and underscore (_)
	Table name:	Should match bean type, a-z, 0-9
	Primary key:	Each table should have a primary key named 'id' (int, auto-incr)
	Foreign key:	Format: <TYPE>_id
	Link table:	Format: <TYPE1>_<TYPE2> sorted alphabetically


After Development

Once you are done developing you need to deploy your PHP application on a production server. Now you don't want RedBeanPHP to scan the database and modify the schema there, so you need to tell RedBeanPHP to freeze:

    R::freeze( true );

Simply put that line at the beginning of your application before deploying. Right after R::setup( ... ). 


*/


class DB  {

	private static $dataBaseConnection = null;

	private function __clone() {}

	public static function getInstance() {
		
		if (self::$dataBaseConnection == null){
			self::$dataBaseConnection = R::setup('mysql:host=localhost;dbname=dm_garage','root','programator');		
		}

		return self::$dataBaseConnection;
	}

//todo

// To obtain the name of the table of a bean: 
//     $bean = R::dispense('book');
//     $beanTable = $bean->getMeta('type');



// RedBeanPHP offers methods to retrieve cells,columns,rows and multi dimensional arrays:

    // R::getCell( ... )
    // R::getCol( ... )
    // R::getRow( ... )
    // R::getAll( ... )
	


// 	Tainted

// Sometimes its useful to know whether a bean has been modified or not. The current state of the bean is stored in a Meta property called tainted. To get the state of the bean use:

//     $bean->getMeta('tainted');

// If the bean has been modified this will return boolean TRUE, otherwise it will return FALSE.
}