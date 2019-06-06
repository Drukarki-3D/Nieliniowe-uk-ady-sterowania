% Pawe³ Jêdrzejak, Bartosz Jaworek, Kacper Bednarczyk 2019

%% otwieranie portu
device = serial('COM6');
device.BaudRate = 115200;
fopen(device);

%% zamykanie portu
fclose(device);

