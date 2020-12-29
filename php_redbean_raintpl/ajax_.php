<?php
include_once './inc/Model/NaprawaModel.php';
include_once './RepairController.php';

if ($_POST['c'])
{
	// utworz nowy obiek instancji klasy
	$c=new $_POST['c']($_POST);
	// var_dump($c);
	// wywolaj metode na rzecz tego obiektu
	$c->$_POST['m']();
}

if ($GET['c'])
{
	$c=new $_GET['c']($_POST);
	$c->$_GET['m']();
}


?>