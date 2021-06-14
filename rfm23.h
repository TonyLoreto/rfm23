#ifndef RF_23
#define RF_23

//Lista de constantes 

#define uint8_t regOpMode= 0x07;

//Modos de Operacion
#define uint8_t standby= 0x00;
#define uint8_t transmit= 0x09;
#define uint8_t receive=  0x05;
#define uint8_t sensor= 0x11; 

//Variable para temperatura
uint8_t tempVal = 0;

//Configuracion de Frecuencia
#define uint8_t freqBand= 19;

#define uint16_t frqTx= 50240;
#define uint16_t frqRx= 50400;

//Salto de frecuencia
#define uint8_t hopToTx= 0;
#define uint8_t hopToRx= 1;
#define uint8_t stepSize= 2;

//Desviacion de Frecuencia
#define uint16_t desvON= 0;//Por definir
#define uint16_t desvOFF=0;

//Desplazamiento de Frecuencia
uint16_t offset= 0;

//Tasa de Datos
uint16_t dataRate=0;
bool txdtrtscale=0;

//Potencia
bool lna= 0;
#define uint8_t powerMin= 5;
#define uint8_t powerMid= 6;
#define uint8_t powerMax= 7;

#define uint8_t UnMod= 00h;
#define uint8_t FSKPacket= 22h;
#define uint8_t OOKPacket= 21h;
#define uint8_t FSKDirect= 92h;
#define uint8_t OOKDirect= 91h;

//Modos de operacion
void setOpMode(uint8_t mode){
	uint8_t aux=0;
	if(){
		setFrqBndSel(freq, hesel)
	}

}

//Configuracion de Frecuencia
void setFrqBndSel(uint8_t freqBand, bool hbsel){

}

//Establecimiento de Frecuencia
void setFrq(uint16_t freq){

}
//Selector de Canal
void setFrqHop(uint8_t hop){//Sugiero cambiar hop a chanel
	
}
//Salto de Frecuencia
void setStpHop(uint8_t stepSize){

}

//Desviacion de Frecuencia
void setFrqDev(uint16_t desvFreq){

}

//Desplazamiento de Frecuencia
void setFrqOff(uint16_t numOffset){

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
void setTxPwr(bool lna_sw, uint8_t){

}

//Modulacion
void setModCtl(uint8_t modTxRx){

}

#endif
