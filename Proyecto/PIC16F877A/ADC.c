/*
AUTOR: MICROSIDE TECHNOLOGY S.A. DE C.V.
FECHA: JUNIO 2019
*/

/*
---------------------------------------------------------------------------
Implementar una lectura anal�gica de un potenci�metro y desplegar el valor
en 8 LEDs
---------------------------------------------------------------------------
*/

#include <16F877A.h>                            //Incluye el microcontrolador con el que se va a trabajar 
#DEVICE ADC=8                                   //Configura el ADC a 8 bits
#use delay(clock=20Mhz, crystal)                //Tipo de oscilador y frecuencia dependiendo del microcontrolador 

 
int ValorPot;                                   //Variable para almacenar el valor le�do del ADC

void SisInit(void)

{

set_tris_b (0X00);                              //Configura todo el puerto B como salidas digitales

setup_adc_ports (AN0);                          //Configura solo el puerto A0 como entrada anal�gica

setup_adc (ADC_CLOCK_DIV_8);                    //Configura oscilador para la conversi�n

}

 

void main()

{
              SisInit () ;

              while (1)

                    {

                          set_adc_channel (0);                       //Selecciona el canal 0 para la conversi�n

                         ValorPot = read_adc ();                     //Lee el valor del ADC y lo guarda en la variable

                          if (ValorPot <= 28)                        //Compara el valor de el ADC con 28

                                {

                                    output_b (0b00000000);           // Leds activos
                                }

                           else if (ValorPot <= 56)                  //Compara el valor de el ADC con 56

                                {

                                    output_b (0b00000001);           // Leds activos
                                }

                            else if (ValorPot <= 84)                 //Compara el valor de el ADC con 84

                                {

                                    output_b (0b00000011);           // Leds activos

                                }

                           else if (ValorPot <= 112)                //Compara el valor de el ADC con 112

                                {

                                      output_b (0b00000111);        // Leds activos

                                }

                           else if (ValorPot <= 140)                //Compara el valor de el ADC con 140

                                {

                                      output_b (0b00001111);       // Leds activos

                                }

                            else if (ValorPot <= 168)              //Compara el valor de el ADC con 168

                                 {

                                        output_b (0b00011111);     // Leds activos

                                 }

                             else if (ValorPot <= 196)             //Compara el valor de el ADC con 196

                                 {

                                         output_b (0b00111111);    // Leds activos

                                 }

                             else if (ValorPot <= 252)             //Compara el valor de el ADC con 252

                                 {

                                       output_b (0b01111111);      // Leds activos

                                 }

                             else if (ValorPot <= 255)             //Compara el valor de el ADC con 255

                                   {

                                        output_b (0b11111111);     // Leds activos

                                    }
               }
}