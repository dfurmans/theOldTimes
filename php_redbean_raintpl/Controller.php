<?php 

include './inc/rain.tpl.class.php';

abstract class Controller {
	
	protected $view;
	private $debug=false;

	function __construct()
	{
		
		$this->view=new RainTPL;

	}


}