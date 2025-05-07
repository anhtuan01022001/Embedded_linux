# DHT11 + STM32: Temperature and Humidity Sensor Project

## 📌 Project Overview

This project demonstrates how to interface the **DHT11 temperature and humidity sensor** with an **STM32 microcontroller**. It reads real-time temperature and humidity data from the DHT11 sensor and outputs the results via UART or displays them on an LCD.

## 📦 Folder Structure

```
DHT11+STM32/
├── Core/                 # STM32 project core files (main.c, etc.)
├── Drivers/              # Peripheral drivers
├── Inc/                  # Header files
├── Src/                  # Source code files
├── README.md             # Project documentation
├── .ioc                  # STM32CubeMX configuration file
```

## 🔧 Hardware Requirements

- STM32 development board (e.g., STM32F103C8T6 – Blue Pill)
- DHT11 sensor module
- Jumper wires
- USB-UART module (if debugging via serial)
- (Optional) 16x2 LCD display

## 📐 Pin Configuration

| DHT11 Pin | Description      | STM32 Pin Example  |
|-----------|------------------|--------------------|
| VCC       | Power (+3.3V)     | 3.3V               |
| GND       | Ground            | GND                |
| DATA      | Digital Output    | PA1 (configurable) |

## 🛠️ Tools Used

- [STM32CubeMX](https://www.st.com/en/development-tools/stm32cubemx.html)
- [STM32CubeIDE](https://www.st.com/en/development-tools/stm32cubeide.html)
- HAL drivers
- Keil uVision (optional alternative)

## 🚀 How It Works

1. Configure GPIO and Timer via STM32CubeMX.
2. Read data from the DHT11 sensor using precise timing via HAL delay/microsecond functions.
3. Parse and validate the 40-bit data packet.
4. Output temperature & humidity to serial monitor or LCD.

## 🧠 Key Concepts

- GPIO input/output handling
- Bit-banging protocol
- Timing-sensitive signal processing
- Interfacing sensors with STM32

## 📈 Output Example (via UART)

```
Temperature: 25°C
Humidity: 60%
```

## 📚 References

- [DHT11 Datasheet (PDF)](https://www.mouser.com/datasheet/2/758/DHT11-Technical-Data-Sheet-1143054.pdf)
- [STM32 HAL Documentation](https://www.st.com/en/embedded-software/stm32cube-mcu-packages.html)

## 📬 Contact

For questions or contributions, feel free to open an issue or pull request.