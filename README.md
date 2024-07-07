# DHT11 Driver
DHT11 Driver for STM32XXX Microcontrollers to retrieve data(Temperature, Humidity) from DHT11. This library also supports error handling and temperature conversion between Celcius and Fahrenheit.

>[!IMPORTANT]
Specify the HAL include files in "DHT11.h"
+ STM32XXXX_HAL_HEADER_FILE
+ STM32XXXX_HAL_TIM_HEAEDER_FILE
for your Microcontroller.

>[!IMPORTANT]
Intialize a Timer to count "1us".

# Reference
## Types
- DHT11_StatusTypeDef
    + DHT11_OK
    + DHT11_TIMEOUT
    + DHT11_ERROR
    + DHT11_CHECKSUM_MISMATCH

- DHT11_InitTypeDef
    + Temperature
    + Humidity
    + Status

## Functions
+ HAL_DHT11_Init
+ HAL_DHT11_DeInit
+ HAL_DHT11_GetErrorMsg
+ HAL_DHT11_ReadData
+ HAL_DHT11_ReadTemperatureC
+ HAL_DHT11_ReadTemperatureF
+ HAL_DHT11_ReadHumidity

# Installation
Copy the "/Inc" & "/Src" directory into your STM32 project.

# Documentation
## Initialization and Deinitialization
Use function `HAL_DHT11_Init` & `HAL_DHT11_DeInit` to handle Initalization and DeInitialization.

### HAL_DHT11_Init
Intitalizes the DHT11 Driver.

- Arguments: 
    + `DHT11` instance of a DHT11 driver.
    + `GPIOx` where x can be (A..G) to select the GPIO peripheral for STM32xxxx family.
    + `GPIO_Pin` specifies the pin DHT11 is connected.
    + `TIM` handler for timer with frequency to count 1us.

- Returns:
    + None

### HAL_DHT11_DeInit
De-initializes the DHT11 Driver.

- Arguments:
    + `DHT11` instance of a DHT11 driver.

- Returns:
    + None

## Reading data from the DHT11
To Read data from the DHT11, this driver provides function like `HAL_DHT11_ReadData`, `HAL_DHT11_ReadTemperatureC`, `HAL_DHT11_ReadTemperatureF` & `HAL_DHT11_ReadHumidity`

### HAL_DHT11_ReadData
Reads data(Temperature, Humidity) from the DHT11 Driver.

- Arguments:
    + `DHT11` instance of a DHT11 driver.

- Returns:
    + `Status` of the command.

### HAL_DHT11_ReadTemperatureC
Reads Temperature value in Celcius from the DHT11 Driver. Status of the command is stored in DHT11_InitTypeDef->Status.

- Arguments:
    + `DHT11` instance of a DHT11 driver.

- Returns:
    + `Temperature` in Celcius.

### HAL_DHT11_ReadTemperatureF
Reads Temperature value in Fahrenheit from the DHT11 Driver. Status of the command is stored in DHT11_InitTypeDef->Status.

- Arguments:
    + `DHT11` instance of a DHT11 driver.

- Returns:
    + `Temperature` in Fahrenheit.

### HAL_DHT11_Humidity
Reads Humidity value from the DHT11 Driver. Status of the command is stored in DHT11_InitTypeDef->Status.

- Arguments:
    + `DHT11` instance of a DHT11 driver.

- Returns:
    + `Humidity`

## Error Handling
To get the messgaes related to Status of `DHT11` driver have `HAL_DHT11_GetErrorMsg` function. After every command, `DHT11` driver stores the Status code in `Status` instance member of the `DHT11_InitTypeDef` struct. 

- Arguments:
    + `Status` status code.

- Returns:
    + `Message` status message.

# Version
>v1.0.1
