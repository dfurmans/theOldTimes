<?php

include './inc/rain.tpl.class.php';
include './VehicleController.php';
include './inc/Model/TypPojazduModel.php';
require_once('./inc/function.php');

$tpl = new RainTPL;
//selectbox z typami pojazdow
$typPojazduModel = new TypPojazduModel();
$tpl->assign("typypojazdow", $typPojazduModel->getAll());

$vehicleId = $_GET["vehicleId"];
$clientId = $_GET["clientId"];

$vehicleController = new VehicleController();
$vehicleData = $vehicleController->getVehicleByVehicleId($vehicleId);


if (isset($_POST['dodaj'])) {

    $vehicleController = new VehicleController();

    $updateVehicle = $vehicleController->dodaj($_POST, $clientId, true);
    //todo make me better!
    $tpl->assign('message', 'Prawidłowo zaktualizowano dane pojazdu ');
    //reload data
    $vehicleData = $vehicleController->getVehicleByVehicleId($vehicleId);
}

$tpl->assign("vehicleData", $vehicleData);

$tpl->draw('vehicleCard');