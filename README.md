# myco-tex-sensors

This project holds the scripts for esp32 microcomputers that recieve and send the data from their corosponding sensors for
[Myco-tex] (url tbd).
This site provides:

- Static pages for main site (react)
- Express/Node.js application server
- REST endpoints for the main web site

## Related Projects/Modules

**myco-tex-sensors** This project. Scripts to effectively recieve and send temps, humitity, co2 and other enviromental variables using C++.

**myco-tex-backend** This serves up REST
endpoints for dashboard application using express, node, & mysql2.
The Github project is:
https://github.com/BenjaminDBallard/myco-tex-backend.

**myco-tex-dashboard** This is the main dashboard application used for monitoring facility enviromental status using react & styled-components.
The Github project is:
https://github.com/jason-cornish/myco-tex-dashboard.
