<?php

$params = (isset($_POST['c'])) ? $_POST : $_GET;

$controller = $params['c'];
$method = $params['m'] ? $params['m'] : 'index';
require("$controller.php");

unset($params['c'],$params['m']);
error_log($controller);
error_log($method);

$controller=new $controller($params);
if (method_exists($controller,$method)) $controller->$method();