#!/usr/bin/perl 
use Excel::Writer::XLSX;
  
my $Excelbook = Excel::Writer::XLSX->new( 'Sample.xlsx' );
my $Excelsheet = $Excelbook->add_worksheet();
  
$Excelsheet->write( "A1", "Hello!" );
$Excelsheet->write( "A2", "KYA BOLTE!!" );
$Excelsheet->write( "B1", "Next_Column" );
  
$Excelbook->close;
