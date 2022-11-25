Nov 25, 2022

This code has been tested on a mac using mujoco200.

Pre-reqs
1) gsl libraries. Download gsl. cd to the gsl folder then type ./configure, make, sudo make install
2) gcc. This is usually installed by default. If not, then install xcode and command line tools for xcode

Running the code
1. Navigate to bin
2. chmod +x run_a1_trot19 (needs to be done only once)
3. ./run_a1_trot19

There are two different waypoint controllers
1) constant yaw
2) changing yaw

In order to change them go to: common/my_controller
At the top of the file set the appropriate value for the flag_constant

int flag_constant = 0; for varying yaw
int flag_constant = 1; for constant yaw.

The parameters of the leminscate can be changed on top of the file my_controller.

Data processing
After running the simulation, you can run main_highlevel.m to see the tracking performance

On Windwos/Linux you would need to download the software from https://www.roboti.us/download.html
Then modify the makefile to suite the operating system. Here are some tutorials for installing and running mujoco200 on win/linux/mac: http://tiny.cc/mujoco

