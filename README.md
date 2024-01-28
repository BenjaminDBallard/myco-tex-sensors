<hr/>

# MycoTex Sensors

## Summary

This project holds the scripts for esp32 microcomputers that recieve and send the data from their corosponding sensors for
[Myco-tex] (url tbd).
This site provides:

- Static pages for main site (react)
- Express/Node.js application server
- REST endpoints for the main web site

Current work is focused on establishing a monitoring system and database for temps, co2, and other enviromental metrics.

<br/>
<hr/>

## Related Projects/Modules

**myco-tex-sensors** (https://github.com/BenjaminDBallard/myco-tex-sensors) (This project)

- Contains scripts to effectively recieve and send temps, humitity, co2 and other enviromental variables using C++ with the Arduino IDE.

**myco-tex-backend** (https://github.com/BenjaminDBallard/myco-tex-backend)

- Serves up REST endpoints for dashboard application using express, node, & mysql2. Authorization and security for the API use JWT and Bcrypt.

**myco-tex-dashboard** (https://github.com/jason-cornish/myco-tex-dashboard)

- This is the main dashboard application used for monitoring facility enviromental status with React & Styled-Components.

<br/>
<hr/>

## Development

**Main**

- [x] Set up Arduino IDE
- [x] Write test function
- [x] Test Build and flash
- [x] Wire probe to ESP32
- [x] Write function to connect to WIFI
- [x] Write function to get sensor measurement
- [x] write function to send https post request
- [x] Build and flash esp

**Final**

- [x] Test live ESP32

<br/>
<hr/>

# Project Setup

> [!TIP]
>
> Install Arduino Extension in VSCode (follow install directions)
>
> cd into the folder for the probetype you intend to install
>
> select your board type and Serial port#
>
> then build and flash the ESP32
>
> monitor its output for errors.
>
> if successful add device to mycodex-dashboard url(tbd)
