# Qt Database Console

Download PostgreSQL for the platform you are building for  
If building for MSVC2015 64-bit, then download PostgreSQL 64-bit for Windows

In Qt Creator, make sure the right kit is being run:

- Click on Projects on the left
- Select the correct kit to build (choose 64bit version if PostgreSQL install was 64bit)

The Postgres driver for your Qt application is part of the Postgres install:

- Go to C:\Program Files\PostgreSQL\10\lib
- Copy libpq.dll to the folder that contains the built .exe application
  - for example: ..\Qt\build-DatabaseConsole-Desktop_Qt_5_11_1_MSVC2015_64bit-Debug\debug
- The application must be distributed with this file