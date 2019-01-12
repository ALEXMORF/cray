## C-Ray

A real-time interactive progressive path tracer.

Keep in mind this is A very early demo of CRay, so crashes or unexpected platform-dependent behavior might happen.

IMPORTANT: do not change the file structure that came within the zip. 
The executable relies on it to find the location of models. Currently
all the models are hardcoded with a fixed position and orientation for
the ease of viewing them. Of course this will change as I will allow
user-inputed models to be rendered. 

Bugs are probably inevitable, as it is just the nature of this kind of things.
I tried my best to give meaningful error messages to all possible failure 
points in the program. If any error occured, please report them on CRay's
forum as this will help me pick out bugs and make the program more robust.
Thank you very much!

website: https://cray.handmade.network/

# Gallery

Still images after some samples are taken:

![conference](https://user-images.githubusercontent.com/16845654/51070010-1c704e80-15ef-11e9-8b95-d9117a9c663e.PNG)
![fireplace](https://user-images.githubusercontent.com/16845654/51070011-1da17b80-15ef-11e9-826b-ecd625f678a5.PNG)
![dragon](https://user-images.githubusercontent.com/16845654/51070013-1e3a1200-15ef-11e9-8fe4-3637d151bbe1.PNG)

# Requirements:
Best to run it on Windows 10. It might be able to run on Windows 7 (still working on compatibility).
Supports DirectX 11. 
Recommend at least 1 GB if you want to load huge models. 

# Controls:
WASD to move honrizontally
X to move up
Z to move down
Q to show UI when it's hidden

Use mouse to drag across the screen to look around.

You can drag most fields on UI, such as exposure rate and colors. 
"L" stands for light vector; it's the direction pointing towards the light,
is not required to be normalized. 

Enjoy!  - Chen