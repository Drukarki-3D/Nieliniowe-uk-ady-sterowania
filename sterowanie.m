% Pawe³ Jêdrzejak, Bartosz Jaworek, Kacper Bednarczyk 2019

%% podstawowy ruch góra/dó³
fprintf(device, 'a -10000 b -10000 c -10000');     %jazda w dó³
while(device.BytesAvailable == 0)               %oczekiwanie na komunikat
end
if(device.BytesAvailable > 0)                   %odbiór komunikatu
    f = fscanf(device);
end

fprintf(device, 'a 1000 b 1000 c 1000');        %jazda w górê
while(device.BytesAvailable == 0)               %oczekiwanie na komunikat
end
if(device.BytesAvailable > 0)                   %odbiór komunikatu
    f = fscanf(device);
end


%% trójk¹t góra/dó³
fprintf(device, 'a 1000 b 0 c 0');              %jazda a
while(device.BytesAvailable == 0)               %oczekiwanie na komunikat
end
if(device.BytesAvailable > 0)                   %odbiór komunikatu
    f = fscanf(device);
end
%%
fprintf(device, 'a 0 b 1000 c 0');              %jazda b
while(device.BytesAvailable == 0)               %oczekiwanie na komunikat
end
if(device.BytesAvailable > 0)                   %odbiór komunikatu
    f = fscanf(device);
end
%%
fprintf(device, 'a 0 b 0 c 1000');              %jazda c
while(device.BytesAvailable == 0)               %oczekiwanie na komunikat
end
if(device.BytesAvailable > 0)                   %odbiór komunikatu
    f = fscanf(device);
end
%%
fprintf(device, 'a -1000 b 0 c 0');             %jazda a w dó³
while(device.BytesAvailable == 0)               %oczekiwanie na komunikat
end
if(device.BytesAvailable > 0)                   %odbiór komunikatu
    f = fscanf(device);
end
%%
fprintf(device, 'a 0 b -1000 c 0');             %jazda b w dó³
while(device.BytesAvailable == 0)               %oczekiwanie na komunikat
end
if(device.BytesAvailable > 0)                   %odbiór komunikatu
    f = fscanf(device);
end                                             %bartek fajo
%%
fprintf(device, 'a 0 b 0 c -1000');             %jazda c w dó³
while(device.BytesAvailable == 0)               %oczekiwanie na komunikat
end
if(device.BytesAvailable > 0)                   %odbiór komunikatu
    f = fscanf(device);
end


%% Krecenie 
%Pocz¹tkowe pozycje sinika 
size = 200;%Œrednica ko³a
old1 = round(size*sin(0));
old2 = round(size*sin(-2.0944));
old3 = round(size*sin(-4.1888));

for t=0:0.01:degtorad(360)
    %Nowe pozycje silnika
    new1 = round(size*sin(t-0));
    new2 = round(size*sin(t-2.0944));
    new3 = round(size*sin(t-4.1888));
    
    x1 = new1 - old1;
    x2 = new2 - old2;
    x3 = new3 - old3;
    
    fprintf(device, sprintf('a %d b %d c %d', x1, x2, x3));
    
    old1 = new1;
    old2 = new2;
    old3 = new3;
    
while(device.BytesAvailable == 0)               %oczekiwanie na komunikat
end
if(device.BytesAvailable > 0)                   %odbiór komunikatu
    f = fscanf(device);
end    

    
    
    
    
    
end
