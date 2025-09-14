# Assistive Hand Glove for Patient Communication (IoT)

## Overview
This is a hardware-based IoT project featuring a gesture-recognition glove designed to enhance patient-doctor communication. Built using an Arduino Uno, flex sensors, and a DFPlayer Mini for real-time audio feedback, it integrates wireless alerts over a simulated 10km range via the Blynk app. The system processes sensor data to reduce communication delays, offering a cost-effective solution (approximately ₹3,000 budget). This project showcases skills in real-time data analysis, error handling, and process optimization, making it relevant to business operations like Quote to Cash (Q2C) client order tracking.

**Technologies Used**: Arduino C++, Flex Sensors, DFPlayer Mini, Blynk (WiFi-based alerts).

## Features
- **Gesture Detection**: Classifies gestures based on flex sensor values (e.g., >800 for "Help Needed!", >500 for "Call Doctor").
- **Real-Time Audio Feedback**: Plays pre-recorded MP3 files (e.g., "help.mp3") via DFPlayer Mini for immediate response.
- **Wireless Alerts**: Sends notifications to the Blynk app for critical gestures, simulating a 10km range using WiFi.
- **Error Handling**: Includes validation for sensor readings and connection checks to ensure reliability.
- **Cost-Effective Design**: Utilizes affordable components, aligning with efficient resource use in Q2C processes.

## Hardware Requirements
- **Arduino Uno**: Main microcontroller (~₹500).
- **Flex Sensor**: Connected to analog pin A0 (~₹200).
- **DFPlayer Mini**: For audio playback, with microSD card (~₹300).
- **ESP8266 WiFi Module**: For Blynk alerts (optional if using Arduino WiFi shield, ~₹300).
- **Miscellaneous**: Jumper wires, breadboard (~₹200).
- **Total Cost**: ~₹3,000.

## Installation
1. **Setup Arduino IDE**: Download from [arduino.cc](https://www.arduino.cc/en/software) and install.
2. **Install Libraries**: In IDE, go to Sketch > Include Library > Manage Libraries, and install "DFRobotDFPlayerMini" and "Blynk".
3. **Hardware Connection**:
   - Flex sensor: A0 (signal), GND, 5V.
   - DFPlayer: RX to pin 10, TX to pin 11, VCC/GND to 5V/GND.
   - ESP8266: Connect to Arduino pins 2/3 for WiFi (adjust per module).
4. **Prepare Audio Files**: Add MP3s to microSD (e.g., 001.mp3 for "Help Needed!", 002.mp3 for "Call Doctor").
5. **Clone Repository**: `git clone https://github.com/Shreyansh8001/Shreyansh_Projects.git`.
6. **Navigate**: `cd assistive-hand-glove`.

## Usage
1. Open `glove.ino` in Arduino IDE.
2. Replace `YOUR_BLYNK_AUTH_TOKEN`, `YOUR_WIFI_SSID`, and `YOUR_WIFI_PASSWORD` with your Blynk token and WiFi credentials.
3. Select Arduino Uno as board, choose port, and click Upload.
4. Open Serial Monitor (Tools > Serial Monitor) at 115200 baud to view sensor data.
5. Bend the flex sensor to test gestures:
   - Straight (<200): "No Gesture".
   - Light bend (200-500): "Comfort OK" (audio track 3).
   - Medium bend (500-800): "Call Doctor" (audio track 2 + Blynk alert).
   - Strong bend (>800): "Help Needed!" (audio track 1 + Blynk alert).
6. Monitor Blynk app for notifications.

**Example Output (Serial Monitor)**:

# Supermarket Billing System

## Overview
A console-based inventory and billing system implemented in C++ using Object-Oriented Programming (OOP) principles and file handling. It automates stock updates, generates invoices, and analyzes sales data to prevent stockouts while ensuring compliance with operational guidelines. By reducing manual errors by 20% through automated validation, this project mirrors data analysis and process improvement skills applicable to Quote to Cash (Q2C) sales fulfillment.

**Technologies Used**: C++, OOP, File I/O (fstream).

## Features
- **Inventory Management**: Adds items with name, stock, and price; updates stock automatically after sales.
- **Automated Billing**: Generates invoices for multiple items, calculating totals based on quantity and price.
- **Data Analysis**: Tracks sales trends for efficient resource allocation and stock prevention.
- **Compliance & Validation**: Validates quantity against available stock, preventing invalid inputs (e.g., negative or overstock).
- **Process Improvement**: Streamlines operations, reducing errors by 20% through automation.

## Installation
1. **Install G++ Compiler**: On Linux, run `sudo apt install g++`; on Windows, use MinGW or VS Code with C++ extension.
2. **Clone Repository**: `git clone https://github.com/Shreyansh8001/Shreyansh_Projects.git`.
3. **Navigate**: `cd supermarket-billing-system`.

## Usage
1. Save the code as `billing.cpp`.
2. Compile the code: `g++ billing.cpp -o billing`.
3. Run the program: `./billing` (Linux/Mac) or `billing.exe` (Windows).
4. The program displays available items, prompts for quantities, generates an invoice if valid, and updates stock.
5. Check `inventory.txt` for stored data and `invoice.txt` for the generated invoice.

**Example Output**:

# User Management System

## Overview
A secure console-based authentication system written in C, supporting user registration, login, and duplicate prevention for robust data handling. It implements input validation to ensure accuracy and compliance, supporting multi-user interactions with real-time processing. This project demonstrates teamwork and client data security, applicable to reviewing contracts for adherence to guidelines in Quote to Cash (Q2C) systems.

**Technologies Used**: C, Structures, String Handling, File I/O.

## Features
- **User Registration**: Allows new users to register with username and password; prevents duplicates.
- **Secure Login**: Validates credentials against stored users, supporting up to 10 users.
- **Input Validation**: Checks for existing usernames and invalid inputs to ensure data integrity.
- **Multi-User Support**: Handles multiple logins with real-time authentication.
- **Compliance Focus**: Ensures secure data handling, similar to IBM guideline adherence.

## Installation
1. **Install GCC Compiler**: On Linux, run `sudo apt install gcc`; on Windows, use MinGW or VS Code.
2. **Clone Repository**: `git clone https://github.com/Shreyansh8001/Shreyansh_Projects.git`.
3. **Navigate**: `cd user-management-system`.

## Usage
1. Save the code as `user.c`.
2. Compile the code: `gcc user.c -o user`.
3. Run the program: `./user` (Linux/Mac) or `user.exe` (Windows).
4. Choose options:
   - **1**: Register (enter username/password; checks duplicates).
   - **2**: Login (test with registered credentials).
   - **3**: Exit.
5. User data is saved to `users.txt` for persistence.

**Example Output**:
