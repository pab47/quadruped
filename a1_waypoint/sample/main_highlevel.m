clc
close all
clear all

PaperPosition = [-0.25 -0.1 8 6]; %location on printed page. rect = [left, bottom, width, height]
PaperSize = [7.25 5.8]; %[width height]
Fontsize = 12;
print_pdf = 1;
path = 'figures/';
Linewidth = 2;


data
%data_turn
%data_yaw

i = 1;
step = all_data(:,i); i = i+1;
x_ref = all_data(:,i); i = i+1;
y_ref = all_data(:,i); i = i+1;
theta_ref = all_data(:,i); i = i+1;
x_p = all_data(:,i); i = i+1;
y_p = all_data(:,i); i = i+1;
theta = all_data(:,i); i = i+1;
error_x = all_data(:,i); i = i+1;
error_y = all_data(:,i); i = i+1;
error_theta = all_data(:,i); i = i+1;
cmd1 = all_data(:,i); i = i+1;
cmd2 = all_data(:,i); i = i+1;
cmd3 = all_data(:,i); i = i+1; 

%%%%%%%%%%%%%%%% alternate figures %%%%%%%%%
hh=figure(1);
subplot(2,2,[1 2]);
plot(x_p,y_p,'r','Linewidth',2); hold on
plot(x_ref,y_ref,'k-.','Linewidth',1);
ylabel('y','Fontsize',Fontsize);
xlabel('x','Fontsize',18);
legend('act','ref','Fontsize',Fontsize,'Location','Best');
ax = gca; ax.FontSize = Fontsize; 
grid on
ylim([-0.8 0.8])
xlim([-4.2 0.2])

subplot(2,2,4);
plot(step,cmd1,'b:','Linewidth',2); hold on
plot(step,cmd2,'r','Linewidth',2);
plot(step,cmd3,'k','Linewidth',2);
ylabel('command','Fontsize',Fontsize);

legend('v_x','v_y','\omega','Fontsize',Fontsize);
ax = gca; ax.FontSize = Fontsize; 
xlabel('step no','Fontsize',Fontsize);

subplot(2,2,3);
plot(step,error_x,'b:','Linewidth',2); hold on
plot(step,error_y,'r','Linewidth',2);
plot(step,error_theta,'k-.','Linewidth',2);
ylabel('error','Fontsize',Fontsize);
legend('x','y','theta','Fontsize',Fontsize);
ax = gca; ax.FontSize = Fontsize; 
xlabel('step no','Fontsize',Fontsize);


string = [path,'all_tracking'];

    
if (print_pdf==1)
       print(hh,'-dpdf',string);
end 

