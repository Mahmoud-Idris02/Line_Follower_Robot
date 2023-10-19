
![Logo](https://github.com/Mahmoud-Idris02/Line_Follower_Robot/blob/5179b0c80e8a97cc257eb072e5e92295dd9c582e/mainApp/Hussien.jpg?raw=true)


# Line Follower Robot 

it's a self driving micro car that can detect the white line and move with it along the track.


## Hardware design

Version 1:
	In this version we used a servo motor to control our 2 front free wheels. This can cause some difficulties controlling them but eventually it provides more speed and stability on track. To sum up, here is the pros and cons of using servo version. 
	Advantages 
•	It allows you to work at a fixed speed for the back two wheels.
•	Gives you a more stable movement over the track.
•	Provides an overall faster vehicle.
Disadvantages
•	More complicated than the free wheel version.
•	We must be extremely specific with servo speed, torque and max weight.

we used:

•	2 mini-DC gear motors 
It gives a good continuous speed but cannot be more specifically angled just like servo motors, so we basically used them for rear wheel drive.
We faced some obstacles such as the speed of each motor is not the same as the other, we did handle this by calibrating the speed of each motor to the other in our SW design.
          
 




•	Dual H-bridge l298n
It was our best choice to control both motors. It successfully protects our chip from being burned through any current draining from any motor.
  
•	Tower pro mini servo 9gm SG90 
Unfortunately, it couldn’t keep up with the wight of the axe and 2 front wheels, so it has been broken after 2 weeks of actual trials. We   tried to replace it with mg995s 180 degrees servo motor this solved the wight problems but affected the speed of movement. 

      
•	3 series rechargeable Li-ion Batteries 3.7v

We used a 3 series battery connection that totally gives us around 11.7 v.
to supply our electrical circuit. We used it instead of a 9v non rechargeable one.
           
•	8 TCRT5000 IR sensors 
Working with TCRT5000 IR sensor was not very easy. To be honest it gives you much knowledge than using the TCRT module, but you must be sure about your electrical connections, making sure that it has a fixed connection that would not be affected with any random movement. You also must consider the percentage of tolerance. It can be affected by daylight.



•	Ultrasonic sensor HC SR04
It was the best option to detect the racing gate for self-launching. 
 
•	A specialized designed acrylic body 
	We did face some difficulties to find a vehicle body that fits our idea, so we designed one by a special measure.
 
Version 2:
	In version 2 we simply had to remove the servo motor for accidental issue. We had to replace it with a fixed connection for the two front wheels.to be honest this version was much easer it just needs a different structure and design for the body. We actually did it for accidental reasons after we didn’t find an appropriate servo motor that can fit to our idea “for the sake of competing instead of nothing”.
In my opinion, if we can find an appropriate servo motor for this mission it might be the most stable and faster vehicle in the competition.

## Electric design
	Electric design for version 2:
We faced a pretty challenging issue that the Arduino regulator chip cannot handle 12v for along time it’s a bit losing method. We can avoid this by connecting the 12v current to the H-bridge but at the other side you would face a current intensity issue as the H-bridge regulator generates a 0.5 A   

<img src ="IMGs/Electric Design.jpg">


## Software design
	We used “layer design approach” for our software design that we will be illustrated in the following diagram.
<img src ="IMGs/Application Layer (2).png">
