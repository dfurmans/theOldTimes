<?php
require('./inc/pdf.php');


//$_GET['']


$pdf = new PDF();
$pdf->AliasNbPages();
$pdf->AddPage();
$pdf->SetFont('Times','',12);
$pdf->setAuthor("Warsztat motocyklowy DM");

//for($i=1;$i<=10;$i++)
    $pdf->Cell(0,10,' Imie',0,1);
    $pdf->Cell(0,10,' Nazwisko',0,1);
    $pdf->Cell(0,10,' Pojazd',0,1);
    $pdf->Cell(0,10,' Numer rejestracyjny',0,1);
    $pdf->Cell(20,10,' Data przyjecia pojazdu na warsztat',0,1);
    $pdf->Output();
