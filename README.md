# SwiftBot
 ## Abstract
 The need for secure and 'swift' delivery has risen to the forefront in today's increasingly connected society, a society that relies heavily on delivery services. From local food deliveries to worldwide shipping, the reliability and safety of delivery services can significantly impact the efficacy of operations involving the movement of goods. Another revolution being experienced is in the increasing degree of automation the world is undergoing which has altered the landscape of many traditional industries, including that of delivery logistics. Be it in factories, offices, or hospitals, issues related to the transportation of items within organizations exist that can hinder or delay tasks which are to be completed within fixed time frames and hence, there exists a requirement for tackling the issue of deliveries within closed spaces in a safe and timely manner.

This project puts forth an autonomous unmanned ground vehicle that utilizes localization and mapping capabilities to plan a path to a destination intended for the delivery of a load. A mobile application integrated with a mapping service is utilized to mark a destination area or coordinate. Moreover, via the data harvested from sensors, such as a laser range sensor responsible for object detection, the mapping and path planning process is used to automate the delivery process between two points. Security features such as facial recognition are possible means to secure the payload within the robot. 

Part of the motivation of the project stems from observing the transportation needs on Habib University's campus, from transporting food items to and from the cafeteria, to moving exam papers and lab manuals between different offices and departments when dealing with bulk loads and downed printing services. With the team’s interest in robotics and the desire to make the campus life easier for its denizens, potential use cases were brainstormed that focused on providing a solution to the aforementioned problems. All these factors led to the team going forward with the titular project.
 ## Details
 Check out the CS and Capstone Reports, under the Reports folder, for detailed information about the project.
 ## How to Run the Files
 1) Files related to ROS
 2) Files related to App
 3) Files related to Facial Recognition
   ## Files related to ROS
   
   (All of the installations should be done on the raspberry pi, unless otherwise mentioned)
   
   1) If you want to run these files then you need to first download ROS Kinetic from http://wiki.ros.org/kinetic/Installation/Ubuntu (You need to have ubuntu installed in order to install ROS). You also need arduino uno and the robot to make it work. You will also need to install ROS on your own system as well, so that you can visualize the robot and run the Main Loop.
   
   2) Once you have done that, please copy the files and folders under the Robot directory (on github) and paste it under the catkin directory in your system (raspberry pi) root folder.
   
   3) Now you must build the files. This can be done by first opening terminal, changing working directory to catkin_ws and then typing the command: catkin_make
   
   4) To install Google Cartographer, the mapping algorithm, follow this link: https://google-cartographer-ros.readthedocs.io/en/latest/compilation.html#building-installation
   
   5) Now you must source the files. This can be done by first opening terminal, changing working directory to catkin_ws and then typing the command: source devel/setup.bash. This must be done on Raspberry Pi.
   
   6) To run the mapping algorithm, you need to upload the teleop code under arduino directory, in github, to arduino uno. You also need to install the teleop_twist_keyboard package by following this link: http://wiki.ros.org/teleop_twist_keyboard. SSH to the PI using your personal system, making sure that it is connected to the same WiFi.
   
   7) Open a terminal on your system and type in roscore, to turn on ROS on your personal system. After that using the ssh(ed) terminals, change the ROS_MASTER_URI and ROS_IP. The reason we are doing this is so that the robot can communicate its data with your system. You must change these two variables for each terminal you ssh into the robot(pi) and also each terminal you open in your PC, ensuring two way communication. This can be done by:
      - For your pc:
      - <code>export ROS_MASTER_URI= http://[ your pc local ip address]:11311</code>
      - <code>export ROS_IP= [your pc local ip address] </code>
      - For your robot(pi):
      - <code> export ROS_MASTER_URI=http://[ your pc local ip address]:11311</code>
      - <code>export ROS_IP= [robot(pi) local ip address]</code>
      You can check the ip address of the current system you are using by typing in <code>ifconfig</code> into your terminal.
    
   8) Now, for every command, open a terminal and run them in parallel(Again keeping in mind step 7). Also every one of these terminals need to have catkin_ws as the working directory:
    These codes need to be run on the ssh terminals:</code>
       - <code>roslaunch rplidar_ros rplidar.launch</code> (This will turn on the lidar)
       - <code>rosrun teleop_twist_keyboard teleop_twist_keyboard.py</code>
       - <code>rosrun motor_driver motor_driver.py</code>
       - <code>source install_isolated/setup.bash</code>
       - <code>roslaunch cartographer_ros cartographer.launch</code>
    This code must be run on your local machine (pc):
       - <code>rviz rviz</code> 
       - Once that is done, go to terminal where you ran the teleop command and then follow the instruction to move the robot. You will notice the map being made on rviz. (Note: go to add topics tab in rviz and click on the topics that you want see on the gui. Particularily the map topic would be of use here.)
   9) If you need to run the main program then you need to make sure that your pi can be port forwarded into. For our system, we used ngrok on our pi to make the server available for the app to access, this allowed us to skip the whole port forwarding process. However, this also means that we need to change the ip everytime on our server when the robot starts (A limitation unless we buy the paid version of ngrok). This is needed so that the app can be able to open the lock of your robot using the pin security feature. The challenge is to how to download ngrok on your pi, fear not we will still cover that here:
   - ssh into your pi and type in your terminal: <code>wget "https://bin.equinox.io/c/4VmDzA7iaHb/ngrok-stable-linux-arm.zip"</code>
   - Then unzip it by typing into your terminal: <code>unzip /path/to/ngrok.zip</code>
   - <code>./ngrok authtoken <YOUR_AUTH_TOKEN></code>
   - Finally: <code>./ngrok http 4010 </code>
   
   10) Finally moving onto the navigation stack (main program), you need to upload the main code under arduino directory, in github, to arduino uno. Now, for every command, open a terminal and run them in parallel (Again keeping in mind step 7). Also every one of these terminals need to have catkin_ws as the working directory:
   These codes need to be run on the ssh terminals:
       - <code>roslaunch rplidar_ros rplidar.launch</code>              (This will turn on the lidar)
       - <code>roslaunch my_robot_name_2dnav my_robot_configuration.launch</code>
   These codes need to be run on your local machine:
       - <code>roslaunch my_robot_name_2dnav move_base.launch</code>
       - <code>rviz rviz</code> (You need to set the initial pose of the robot, you can also use it to visualize where your robot is moving. You may close it only after setting the initial pose of the robot, this needs to be done once only)
       - <code>python src/simple_navigation_goals/src/call_this.py</code>
   Again move to one of your ssh terminals and type in: 
       -<code> python src/simple_navigation_goals/src/open_lock.py</code>
       -<code>python src/simple_navigation_goals/src/mainLoop_f.py</code>
       
   11) Else you can just use the robot's pose using the 2d_pose icon on top and then give a goal by pressing on the 2d_navigation goal icon on rviz, if you dont want to use the app and just watch the robot move (smoothly) across the map using your own cordinates. Just make sure that you don't input anything after the rviz command, ignoring every command that is written in point 11 after the rviz command, to be specific. 
   
   (Note: go to add topics tab in rviz and click on the topics that you want see on the gui. Particularily the map, polygon, the global path and costmap, the local path and costmap would be of use here)
       
 ## Files related to Android App   
 
 Following are the steps that you need to follow to get the app in working condition.

 1) Download NPM, ie Node Package Manager.
 2) Open cmd and type ```npm install ionic```
 3) Now navigate to the app folder with the source code inside terminal and type ```npm install``` . Now, npm will start installing all the dependencies. 
 4) Once that is done, type ```ionic serve``` to start the app. This will open the app in your default browser.
 5) For running app on your android phone, connect your android phone to your PC and run the command <code>ionic cordova run android --device --livereload</code>
 6) After you have tested and run the code, you can get a <code>.apk</code> file for the project by running the command <code>ionic cordova build --release android</code>. After a while, you can find your <code>.apk</code> file here,
<code>\platforms\android\app\build\outputs\apk\release\app-release-unsigned.apk</code>.

### Signing Apk

1) <code>keytool -genkey -v -keystore my-release-key.keystore -alias alias_name -keyalg RSA -keysize 2048 -validity 10000</code>

if "keytool" is not found, use,

2) <code>"C:\Program Files\Java\jre1.8.0_151\bin\keytool.exe" -genkey -v -keystore my-release-key.keystore -alias alias_name -keyalg RSA -keysize 2048 -validity 10000</code>

3) .keystore file has been generated. To attach it with the unsigned apk, use the "OutSign" software. Path to the JDK file: <code>C:\Program Files\Java\jdk1.8.0_144\bin</code>

## Files Related to Facial Recognition Server
Files Related to Facial Recognition Setup on Server Side: 

1) Make Sure that Python-Pip is installed on the Machine. This tutorial can be followed on a Windows Machine with a valid Python installation <code>https://www.liquidweb.com/kb/install-pip-windows/</code>  

2) using pip in the cmd environment further dependency libraries need to be installed <code>https://packaging.python.org/tutorials/installing-packages/</code>

    a) Scikit-learn (pip install scikit-learn)
    b) NumPy (pip install numpy)
    c) OpenCV (pip install cv2)
    d) Flask (pip install flask)
3) Now to overcome any discrepancy in the trained dataset the module should be retrained over the current dependencies. 
For this step, open a cmd prompt and run "python extract_embeddings.py" should be run, afterwards "python train_model.py" should be run.

4) After these two files are successfully executed, the folder "./dataset" will have folders of people who are recognizable by the system. After this, the Server should be run on the local device, the port number is customiz-able in the script "Server.py"

5) Installing ngrok (For port forwarding of the server running on localhost)
Setting up on a windows machine:

   a) Download the ngrok ZIP file.
   b) Unzip the ngrok.exe file.
   c) Place the ngrok.exe in a folder of your choosing.
   d) Make sure the folder is in your PATH environment variable.

For Linux machines:
The ngrok can be installed via terminal "sudo apt-get install ngrok" on Debian based systems, while "sudo pacman -S ngrok" on arch based systems directly.

6) After running the ngrok on desired port the port forwarding will start and the generated link would have to be updated in the "src/simple_navigation_goals/mainloop.py" file, in the "Send_Nodes" method.

7) After the server has been successfully set up the robot can start communicating with the server, to successfully run facial recognition feature for security purposes.

