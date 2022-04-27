#include <kipr/wombat.h>

int main()
{
    //gets botguy
    create_forward(5000);
    msleep(250);
    servo_speed(1050, 1400, 0, 30);
    msleep(250);
    servo_speed(880, 450, 1, 30);
    msleep(250);
    create_forward(1500);
    msleep(250);
    create_right(700);
    msleep(250);
    create_forward(250);
    msleep(250);
    create_left(900);
    msleep(250);
    create_forward(250);
    msleep(250);
    close_claw(2500);
    ao();
    msleep(250);
    create_right(700);
    msleep(250);
    
    
    
    
    
    
    
    
    
    return 0;
}





//FUNCTIONS

//moves create forward

void create_forward(int time)
{
    create_connect();
    create_drive_direct(75, 75);
    msleep(time);
    create_stop();
    create_disconnect(); 
}


//moves create backwards

void create_backward(int time)
{
    create_connect();
    create_drive_direct(-75, -75);
    msleep(time);
    create_stop();
    create_disconnect(); 
}


//moves create right

void create_right(int time)
{
    create_connect();
    create_drive_direct(75, -75);
    msleep(time);
    create_stop();
    create_disconnect(); 
}


//moves create left

void create_left(int time)
{
    create_connect();
    create_drive_direct(-75, 75);
    msleep(time);
    create_stop();
    create_disconnect(); 
}


//rotates claw clockwise

void claw_rotate_clockwise(int time)
{
    mav(0, 1500);
    msleep(time);
}


//rotates claw counterclockwise

void claw_rotate_counterclockwise(int time)
{
    mav(0, -1500);
    msleep(time);
}


//opens claw

void open_claw(int time)
{
    mav(2, 1500);
    msleep(time);
}


//close claw

void close_claw(int time)
{
    mav(2, -1500);
    msleep(time);
}


//moves servos to a specific position with a position speed

//moves a servo from one given position to another at a certain speed
//op- the starting position of the servo
//wp- the ending positon of the servo
//servoport- the port of the servo 
//speed- the increment by which the servo position is repeatedly moved
void servo_speed(int op, int wp, int servoport, int speed) {   
    //allows for the servo to change in any direction
	if(op > wp){
		while(op > wp){
			if(op - wp < speed){
				//just set the claw to the end position
				set_servo_position(servoport, wp);
				op = wp;
			}else{
				//increments the position
				op -= speed;  

				//sets the servo position to the incremented position
                enable_servos();
				set_servo_position(servoport, op);
				msleep(100);
                disable_servos();
			}
		}
	}else{
		while(wp > op){
			 //if the position is less than one increment away from the wanted position
			if(wp - op < speed){
				//just set the claw to the end position
                enable_servos();
				set_servo_position(servoport, op); 
                msleep(100);
                disable_servos();
				op = wp;
			}else{
				
				//increments the position
				op += speed;
				//sets the servo position to the incremented position
                enable_servos();
				set_servo_position(servoport, op);
				msleep(100);
                disable_servos();
			}
		}
	}
}