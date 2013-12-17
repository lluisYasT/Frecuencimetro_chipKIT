Plantilla para ChipKIT
======================
La idea de esta plantilla es colocar el código fuente del programa en src y las
bibliotecas de terceros en lib.
- Para compilar solamente: `make [archivo].S`
- Para compilar y ensamblar: `make [archivo].o`
- Para compilar y enlazar: `make`
- Para cargar en placa: `make load`

#Variables
Se pueden modificar diferentes parámtros a través de variables:

  * Directorio de instalación de MPIDE
    `MPIDE=/home/lluis/mpide`
  * Puerto serie
    `SERIAL_PORT=/dev/ttyUSB0`
  * CPUTYPE (chip microcontrolador que lleva la placa)
    `CPUTYPE=32MX795F512L`
  * Variante
    `VARIANT=Max32`
  * Placa
    `BOARD=_BOARD_MEGA_`


Se incluye el script "prep_sketch.pl" que simula el comportamiento de MPIDE
declarando las funciones definidas en "sketch.pde" al principio del mismo,
junto con la inclusión de WProgram.h.
