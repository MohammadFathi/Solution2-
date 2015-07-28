# Solution2-
Update for Coding Challenge Solution


1. I assume computer machine using for the test process has gcc compiler installed. If using Windows platform , please go to http://www.mingw.org to install MinGw for Windows platform. 
Please refer also to http://www.mingw.org/wiki/Getting_Started


2- You'd need to set up the command line path to lead to the compiler. assuming your directory for MinGW is the default C:\MinGW, your Environment Variable should be set to C:\MinGW\bin 

The installers do not automatically modify any environment settings, (in particular the PATH). You will need to add the MinGW `bin' directory,you have to tell the command line interpreter where to find the coomand line tool MinGw. 
This is usually accomplished by adding the appropriate directory names to the PATH variable in your user environment. The installers will not do this for you.
To do that : 
We need to alter the PATH variable, you must ensure to alter your user PATH variable, not your system PATH variable 


Warning: Adding entries to the PATH is normally harmless. However, if you delete any existing entries, you may mess up your PATH string, and you could seriously compromise the functioning of your computer. Please be careful.

- Right-click on your "My Computer" icon and select "Properties".
- Click on the "Advanced" tab, then on the "Environment Variables" button.
- You should be presented with a dialog box with two text boxes. The top box shows your user settings. The PATH entry in this box is the one you want to modify. Note that the bottom text box allows you to change the system PATH variable. 
  You should not alter the system path variable in any manner, or you will cause all sorts of problems for your computer!
- Click on the PATH entry in the TOP box, then click on the "Edit" button 
- Scroll to the end of the string and at the end add
  <installation-directory>\bin

(if PATH entry is not available in your user settings, you should create it using "New" and write the variable name as PATH and Variable value as <installation-directory>\bin )

NOTE: Substitute <installation-directory> with the FULL absolute path name of the installation target directory you chose (ie C:\MinGW);

- press OK -> OK -> OK and you are done.


3- Now, we will work to do the batch file: Create a folder in C directory and name it as "Project", then copy the source code files: project4.cpp, Tweet.cpp, Tweet.h, UniquWord.h to this folder.

4- Make a new notepad file in the desktop, and copy the script written inside run.bat file. to this file. 

5- Save this file as "run.bat" as File Name, and choose "All Files" in Save as type (Do not select as Text Documents (.txt))

6- Copy your "tweets.txt" file and paste it to directory C:
 
7- Now, double click on run.bat file, it  should comiple and execute the program . You will find project.exe file inside the folder project.

8- The two files ft1.txt and ft2.txt will be created and saved inside directory C:.
