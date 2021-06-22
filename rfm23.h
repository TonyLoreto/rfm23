#ifndef RF_23
#define RF_23

//Lista de constantes 

#define uint8_t regOpMode= 0x07;

//Modos de Operacion
#define uint8_t standby= 0x00;
#define uint8_t transmit= 0x08;
#define uint8_t receive=  0x04;
#define uint8_t sensor= 0x11; 
//#define uint8_t transmit= 0x09;
//#define uint8_t receive=  0x05;

//Registros y Constantes para Sensor de Temperatura 
#define uint8_t adcConfSensor = 0x83;//Temp ADC conf Apagar 1000 0011 
#define uint8_t adcConfSensorTrigger = 0x80;//Temp ADC Trigger Encender 1000 0000
#define uint8_t adcConf= 0x0f;//ADC Configuration Reg
#define uint8_t adcValue = 0x11;//ADC Value
#define uint8_t tempSensorControlConf = 0x00;//Temp Sensor Control Conf
#define uint8_t tempSensorControl = 0x12;//Temp Sensor Control Reg
//#define uint8_t adcConfSensor = 0x13;//Temp Sensor Calibration Reg

//Variable para Temperatura
uint8_t tempVal = 0;

//Configuracion de Frecuencia
#define uint8_t freqBandSelect= 0x75;//Frecuency Band Sel Reg
#define uint8_t nominalCarrierF1= 0x76;//
#define uint8_t nominalCarrierF0= 0x77;
#define uint8_t fB= 19;

#define uint16_t frqTx= 50240;
#define uint16_t frqRx= 50400;

//Salto de frecuencia
#define uint8_t frqHopCh= 0x79;//Reg
#define uint8_t frqHopStep= 0x7A;//Reg
#define uint8_t hopToTx= 0;
#define uint8_t hopToRx= 1;
#define uint8_t stepSize= 2;

//Desviacion de Frecuencia
#define uint8_t modMC= 0x71;//Reg Modulation Mode Control
#define uint8_t freqDev= 0x72;//Rrg frequency Deviation
#define uint16_t desvON= 0;//Por definir
#define uint16_t desvOFF=0;

//Desplazamiento de Frecuencia
#define uint8_t freqOffset0= 0x73;//Reg Frequency Offset 0
#define uint8_t freqOffset1= 0x74;//Ref Frequency Offset 1
uint16_t offset= 0;

//Tasa de Datos
uint16_t dataRate=0;
bool txdtrtscale=0;

//Potencia
bool lna= 0;
#define uint8_t powerMin= 5;
#define uint8_t powerMid= 6;
#define uint8_t powerMax= 7;

#define uint8_t UnMod= 0x00;
#define uint8_t FSKPacket= 0x22;
#define uint8_t OOKPacket= 0x21;
#define uint8_t FSKDirect= 0x92;
#define uint8_t OOKDirect= 0x91;

//Modos de operacion
void setOpMode(uint8_t mode){
	uint8_t aux = mode;
	if( aux == standby )
	{
		write(regOpMode, standby);
	}
	if( aux == transmit )
	{
		write(regOpMode, transmit);
		setFrqBndSel(FrqTx, 1);
	}
	if( aux == receive )
	{
		write(regOpMode, receive);
		setFrqBndSel(FrqRx, 1);
	}
	if( aux == sensor )
	{
		uint8_t aux=0;
		aux = read(adcConf) & adcConfSensor;
		write(adcConf, aux);
		aux = read(tempSensorControl) & tempSensorControlConf;
		write(tempSensorControl, aux);
		aux = read(adcConf) | adcConfSensorTrigger;
		write(adcConf, aux);
		tempVal = read(adcValue);
	}

}

//Configuracion de Frecuencia
//hbsel depende de 
void setFrqBndSel(uint16_t freq, bool hbsel){
	uint8_t aux = 0;
	if (hbsel==1)
	{
		aux = read(freqBandSelect) | fB | (hbsel<<5);
		write(freqBandSelect, aux);
		write(nominalCarrierF1, (uint8_t)(freq >> 8));
		write(nominalCarrierF0, (uint8_t)(freq));
	}
	if (hbsel==0)
		{
			aux = read(freqBandSelect) | fB & (hbsel<<5);
			write(freqBandSelect, aux);
			write(nominalCarrierF1, (uint8_t)(freq >> 8));
			write(nominalCarrierF0, (uint8_t)(freq));
		}
}

//Establecimiento de Frecuencia
//void setFrq(uint16_t freq){
//}

//Selector de Frecuencia de Salto 
//freq+hop*(stepSize*10KHz)
void setFrqHop(uint16_t freq, bool hbsel, uint8_t hop, uint8_t stepSize){//Quitar hop, agregar fB
	setFrqBndSel(freq, hbsel);
	setStpHop(hop, stepSize);
}
//Salto de Frecuencia
void setStpHop(uint8_t hop, uint8_t stepSize){//hop*(stepSize*10KHz)//quitar step size
	write(frqHopCh, hop);
	write(frqHopStep, stepSize);
}

//Desviacion de Frecuencia
void setFrqDev(uint16_t desvFreq){
	uint8_t aux= 0;
	aux = read(modMC) | desvFreq & (1<<8); 
	write(modMC, aux);
	write(freqDev, (uint8_t)(desvFreq));
}

//Desplazamiento de Frecuencia
void setFrqOff(uint16_t numOffset){
	write(freqOffset0, (uint8_t)(numOffset));
	write(freqOffset1, numOffset & (2<<8));
}

//Tasa de Datos
void setTxKbps(uint16_t numDataRate, bool rang){
	if( 258 <= numDataRate <= 62915 && rang == 0 ){

	}
	if( 2032 <= numDataRate <= 16778 && rang =1 ){

	}
	else{

	}
}

//Potencia
void setTxPwr(bool lna_sw, uint8_t txPow){
	uint8_t aux = 0;
	aux = read(outPower) | txPow | (lna_sw<<3);
	write(outPower, aux);
}

//Modulacion
void setModCtl(uint8_t modTxRx){

}

#endif
