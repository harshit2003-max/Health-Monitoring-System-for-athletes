# Health-Monitoring-System- for athletes

## Project Description

This project implements a heart rate monitoring system for athletes using an ESP32 microcontroller. It measures heart rate in real-time, analyzes workout intensity, and logs data to the cloud for tracking and analysis.

### Features

- Real-time heart rate measurement using a pulse sensor
- Workout intensity classification based on heart rate zones
- Visual feedback through LEDs
- WiFi connectivity for data transmission
- Integration with ThingSpeak IoT platform for data logging and remote monitoring
- Serial output for local monitoring and debugging

### Hardware Requirements

- ESP32 microcontroller
- Pulse sensor
- LEDs (for visual feedback)
- WiFi connection

### Software Dependencies

- WiFi library
- WiFiClient library
- ThingSpeak library

## Setup and Configuration

1. Connect the pulse sensor to pin 35 on the ESP32.
2. Connect LEDs to pins 2, 25, and 27 for visual feedback.
3. Update the WiFi credentials in the code:
   ```cpp
   const char* ssid = "Your_WiFi_SSID";
   const char* password = "Your_WiFi_Password";
   ```
4. Set up a ThingSpeak channel and update the channel details:
   ```cpp
   unsigned long channelID = Your_Channel_ID;
   const char* writeAPIKey = "Your_Write_API_Key";
   ```

## Usage

The system automatically measures heart rate and classifies the workout intensity into the following zones:

- Maximum Workout
- Anaerobic Training
- Cardio Training
- Fat Burn
- Warm Up

Heart rate data and workout type are sent to ThingSpeak for logging and analysis.

## Future Improvements

- Add a display for real-time feedback
- Implement more precise heart rate calculation
- Add user profiles for personalized heart rate zones
- Develop a mobile app for easy monitoring

## Contributing

Contributions to improve the project are welcome. Please feel free to fork the repository and submit pull requests.

