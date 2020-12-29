<?php
class HelperLogger{
	
	/** Typ logu - Error  */
	const LogError = 'E';
	/** Typ logu - Info */
	const LogInfo = 'I';
	/** Typ logu - Warning */
	const LogWarning = 'W';
	/** Typ logu - Verbose */
	const LogVerbose = 'V';
	
        

/**
	 * Logowanie do pliku
	 *
	 * @param string $message Tresc do zapisania w logu
	 * @param string $logLevel Typ bledu (E, W, I)
	 */
	public static function Log($message, $logLevel = self::LogInfo) {
		try {
			switch ($logLevel) {
				case self::LogError :
					$logFile = 'fileE';
					break;
				case self::LogWarning :
					$logFile = 'fileB';
					break;
				case self::LogVerbose :
					$logFile = 'fileC';
					break;
				case self::LogInfo :
					$logFile = 'fileInfo';
			}
			if (empty ( $logFile )) {
				return;
			}
			
			if (strpos ( $logFile, '(' ) > - 1) {
				$logFile = preg_replace ( '/\(([^\)]+)\)/e', "date('$1')", $logFile );
			}
			
			file_put_contents ( $logFile, date ( 'Y-m-d H:i:s	' ) . '[' . $logLevel . ']	' . $message . chr ( 13 ) . chr ( 10 ), FILE_APPEND );
		} catch ( Exception $e ) {
			throw new Exception ( 'An error occurred while writing data to log file.' . chr ( 10 ) . $e->getMessage (), $e->getCode () + 400 );
		}
	
	}

	public static function ShowAllLogs($logFileName){

		$content = file_get_contents('./'.$logFileName, true);
		print_r($content);
	}
}

$operationType = $argv[1];
$args = $argv[2];

switch($operationType){
	case 'write':
		HelperLogger::Log($args, 'E');
		break;
	case 'read':
		HelperLogger::ShowAllLogs($args);
		break;
}

//usage
# write messsage
# read fileName