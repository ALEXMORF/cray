A very early demo of CRay.

IMPORTANT: do not change the file structure that came within the zip. 
The executable relies on it to find the location of models. Currently
all the models are hardcoded with a fixed position and orientation for
the ease of viewing them. Of course this will change as I will allow
user-inputed models to be rendered. 

Bugs are probably inevitable, as it is just the nature of this kind of things.
In anticipation of different shader compilers from different GPU vendors,
I tried my best to give meaningful error messages to all possible failure 
points in the program. If any error occured, please report them on CRay's
forum as this will help me pick out bugs and make the program more robust.
Thank you very much!

Requirements:
Best to run it on Windows 10. It might be able to run on Windows 7.
Supports OpenGL 4.4.
2 GB of RAM minimum (this is pretty unreasonably big, will be compressed in future demos).

Controls:
WASD to move honrizontally
X to move up
Z to move down
Q to show UI when it's hidden

Use mouse to drag across the screen to look around.

You can drag most fields on UI, such as exposure rate and colors. 
"L" stands for light vector; it's the direction pointing towards the light,
is not required to be normalized. 

Enjoy!  - Chen