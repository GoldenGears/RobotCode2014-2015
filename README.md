<!---
	Golden Gears Robotics
	11/7/14
	README
-->

<!---11-7-14 - Tyler Robbins - Added a header to the README, added some more instructions, and changed some formatting.-->

GGRobotics Team 4413 C++ Code
=============================

##Description##
The robot code for the 2014 - 2015 First Robotics Competition (FRC) that will be coded entirely in the C++ programming language.

##Editing##
Only those who are on the programming team of Golden Gears Robotics (Team 4413) may edit this repository. If you are on the programming team of Golden Gears Robotics, but do not have write permission for this repository, send an email to github@goldengearsrobotics.com.

If you are not on the programming team, but would like to make some changes, then clone the repository and make a pull request.

##Clone Repository##
1) Log into your github account. If you do not have one, [sign up here](https://github.com/join).

2) Open up a Unix terminal (cygwin or some other alternative if using Windows) and in the field, type:

`cd ~/.ssh && ssh-keygen`

Then hit enter and type:

###Linux###
`cat id_rsa.pub | xclip`

###MacOSX###
`cat id_rsa.pub | pbcopy`

###Windows###
`cat id_rsa.pub`

Select and copy the contents to your clipboard.

3) Setup your git config:
```
git config --global user.name "your-name-here"
git config --global user.email your_email@youremailhere.com
```

4) Navigate and/or make the directory where you would like the file to be placed.
EX: `.../Desktop/dev/frc_code_2013-2014`

###Collaborators###
5) Restart your command line to make sure that the config settings have loaded, go to the folder where you want to clone the repository, and type:
`git clone https://github.com/GoldenGears/RobotCode2014-2015.git`

5.1) To push your changes to github, open terminal and type:
`git push`

- Type in your username and password for github.

####Non-Collaborators####
5) Go to [the github repository](https://github.com/GoldenGears/RobotCode2014-2015) and click on the "Fork" button in the top right hand corner of the screen.

5.1) Restart your command line to make sure that the config settings have loaded, go to the folder where you want to clone the repository, and type:

`git clone git@github.com:username/RobotCode2014-2015`

Where username is _your_ github username.

5.2) To commit your changes, go back to [the github repository](https://github.com/GoldenGears/RobotCode2014-2015/pulls) and click "New pull request".

##Build and Deploy##
Foo
Spam
Bar

##Code Structure##
[This needs to be worked on a bit more]