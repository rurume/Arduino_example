%% Basic example for analog and digital IO and basic serial functions

% This is a very simple example that shows how to use the basic functions 
% for analog and digital IO as well as serial port
clear;
close all;

%% create arduino object and connect to board
if exist('a','var') && isa(a,'arduino') && isvalid(a),
    % nothing to do    
else
    a=arduino('/dev/tty.usbmodem1411');
end

%% basic analog and digital IO
[music ,fs] = wavread('123.wav'); 
emg_data = [];
number = 0;
%figure;
%figH = plot(nan);

av=analogRead(a,0);

% while av(2) ==0
%    
% % read analog input from analog pin 5 (physically != from digital pin 5)
% av=analogRead(a,0);
% 
% 
% display(av(1));
% 
% % normalize av from 0:1023 to 0:254
% % emg_data = [emg_data [av(1);(av(2)/1023)*254]];
% %emg_data = [emg_data [av(1);(av(2)/1023)*5]];
% %plot(emg_data(1,:),emg_data(2,:));
% %set(figH,'XData',emg_data(1,:),'YData',emg_data(2,:));
% %set(gca,'xlim',[emg_data(1,number)-5000, emg_data(1,number)],'ylim',[1 5]);
% %drawnow;
% end
%% close session
sound(music,fs);

delete(a);
% Copyright 2013 The MathWorks, Inc.
%%
