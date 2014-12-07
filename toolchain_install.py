####################
# Golden Gears Robotics
# 12/5/14
# ToolChain Installer
# Install the necessary toolchain depending on the operating system.
#####################

# 12-5-14 - Tyler Robbins - Created a Python script to install the 2013-2014 C++ FRC Toolchain on Windows, Mac OSX, and Linux operating systems automatically.

import sys, os
if sys.version_info[0] == 2:
	import urllib as urllib
else:
	# print("Must have Python 2.7!")
	import urllib.request as urllib

def getOS():
	'''Get the current operating system.'''
	# print sys.platform
	return str(sys.platform)

def isLinux():
	'''Returns True if the current operating system is a Linux.'''
	return (getOS()=="linux")

def isOSX():
	'''Returns True if the current operating system is a Mac OSX.'''
	return (getOS()=="darwin")

def isWin32():
	'''Returns True if the current operating system is a Windows.'''
	return (getOS()=="win32" or getOS()=="win64")

def install():
	if isLinux():
		print("Installing for Linux.")
		installLinux()

	elif isOSX():
		print("Installing for Mac OSX.")
		installOSX()

	elif isWin32():
		print("Installing for Windows.")
		installWin32()

	else:
		print("Unknown operating system: %s" % getOS())
		print("Terminating install")
		sys.exit()

def installLinux():
	# In case the program fails to install the necessary packages, open your terminal and run the following commands depending on how you
	#	want to install it (Binary install or Manual install):
	# 
	##########
	# Binary #
	##########
	# $ echo \"deb http://debian.repo.frc.s3.amazonaws.com jessie main\" | sudo tee -a /etc/apt/sources.list
	# $ wget -O - http://debian.repo.frc.s3.amazonaws.com/rbmj.gpg.key | sudo apt-key add - 
	# $ sudo apt-get update
	# $ sudo apt-get install cmake gcc-powerpc-wrs-vxworks frc-buildscripts wpilib
	# $ echo \"export WIND_BASE=/usr/powerpc-wrs-vxworks/wind_base\" >> ~/.bashrc
	# $ source ~/.bashrc
	#
	# Note: Only run one of these. You do not need to run the manual commands if you installed using binary, and vice-versa.
	#
	##########
	# MANUAL #
	##########
	# $ sudo apt-get install debhelper devscripts binutils-dev build-essential
	# $ git clone https://github.com/rbmj/wrs-headers-installer
	# $ git clone https://github.com/rbmj/ppc-vxworks-binutils
	# $ git clone https://github.com/rbmj/ppc-vxworks-gcc
	# $ git clone https://github.com/rbmj/frc-buildscripts
	# $ git clone https://github.com/rbmj/wpilib
	# $ for i in `find . -type d`; do (./debmake && sudo dpkg -i build/*.deb); done
	#
	# If problems persist, contact me at "robbint@campbellhall.org" and I will do my best to assist.

	for c in coms:
		print(coms[c] + "...")
		os.system(str(c))

def installWin32():
	# In case the program fails to install the necessary packages, download and install the files from the following links:
	# FRC-C++11 Toolchain: 	http://firstforge.wpi.edu/sf/frs/do/viewRelease/projects.c--11_toochain/frs.windows_installers.beta1
	# GNU Make: 			http://sourceforge.net/projects/gnuwin32/files/make/3.81/make-3.81.exe/download?use_mirror=softlayer-dal&download=
	#
	# If problems persist, contact me at "robbint@campbellhall.org" and I will do my best to assist.

	frc_url = 	"http://www.firstforge.wpi.edu/sf/frs/do/downloadFile/projects.c--11_toolchain/frs.windows_installers.beta1/frs1943?dl=1"
	make_url = 	"http://www.colocrossing.dl.sourceforge.net/project/gnuwin32/make/3.81/make-3.81.exe"

	make_path = "C:\\Program Files (x86)\\GnuWin32\\bin\\make.exe"
	frc_path = 	"C:\\Program Files (x86)\\FRC_Toolchain\\"

	dl_path = os.getcwd()

	if not os.path.exists(make_path):
		print("Downloading make-3.81.exe...")
		open(os.path.join(dl_path,"make-3.81.exe"),"wb").write(urllib.urlopen(make_url).read())
		os.system(concatFilePath("make-3.81.exe"))
	else:
		print("File make-3.81.exe already exists. Skipping.")

	if not os.path.exists(frc_path):
		print("Downloading FRCToolchainInstaller.exe...")
		open(os.path.join(dl_path,"FRCToolchainInstaller.exe"),"wb").write(urllib.urlopen(frc_url).read())
		os.system(concatFilePath("FRCToolchainInstaller.exe"))
	else:
		print("File FRCToolchainInstaller.exe already exists. Skipping.")

def installOSX():
	# In case the program fails to install the necessary packages, download and install ALL of the files from
	#	http://firstforge.wpi.edu/sf/frs/do/viewRelease/projects.c--11_toochain/frs.mac_os_x_pkg.alpha0
	#
	# Also, make sure you have GNU Make installed. To check, type 'make --version' into your terminal. If it does not exist, install Xcode from
	#	the AppStore, and then install the component named "Command Line Tools" from "Xcode->Preferences->Downloads".
	#
	# If problems persist, contact me at "robbint@campbellhall.org" and I will do my best to assist.

	import zipfile

	#Packages to install:
	downloads_list = {
	"http://firstforge.wpi.edu/sf/frs/do/downloadFile/projects.c--11_toochain/frs.mac_os_x_pkg.alpha0/frs1915?dl=1" : "PowerPC VxWorks GCC",
	"http://firstforge.wpi.edu/sf/frs/do/downloadFile/projects.c--11_toochain/frs.mac_os_x_pkg.alpha0/frs1914?dl=1" : "PowerPC VxWorks Binutils",
	"http://firstforge.wpi.edu/sf/frs/do/downloadFile/projects.c--11_toochain/frs.mac_os_x_pkg.alpha0/frs1913?dl=1" : "WindRiver Headers",
	"http://firstforge.wpi.edu/sf/frs/do/downloadFile/projects.c--11_toochain/frs.mac_os_x_pkg.alpha0/frs1917?dl=1" : "WPILib",
	"http://firstforge.wpi.edu/sf/frs/do/downloadFile/projects.c--11_toochain/frs.mac_os_x_pkg.alpha0/frs1916?dl=1" : "FRC Aliases"
	}

	for d in downloads_list:
		print("Downloading %s..." % downloads_list[d])
		path = concatFilePath("install_zip.zip")
		open(path,"wb").write(urllib.urlopen(d))

		ext_path = os.path.join(os.getcwd(),"install_zip")

		zfile = zipfile.ZipFile(path)
		zfile.extractall(ext_path)

		files = []

		for f in os.listdir(ext_path):
			if f.endswith(".pkg"):
				files.append(f)

		# os.system("./WPILib.pkg")
		for f in files:
			os.system("sudo installer -pkg " + ext_path + "/" + f + " -target /")

	if not os.path.exists("/Library/Developer/CommandLineTools/"):
		print("Installing Command Line Tools...")
		os.system("xcode-select --install")

def concatFilePath(filename,path=os.getcwd()):
	return os.path.join(path,filename)

def delFile(filename):
	path = os.path.join(os.getcwd(),filename)
	if os.path.exists(path):
		print("Deleting %s." % filename)
		os.remove(path)
	else:
		print("File %s does not exist!" % filename)

coms = {"echo \"deb http://debian.repo.frc.s3.amazonaws.com jessie main\" | sudo tee -a /etc/apt/sources.list" : "Adding frc-c++11 repository",
		"wget -O - http://debian.repo.frc.s3.amazonaws.com/rbmj.gpg.key | sudo apt-key add - " : "Adding maintainer key for the repository",
		"sudo apt-get update" : "Installing the frc-c++11 packages",
		"sudo apt-get install cmake gcc-powerpc-wrs-vxworks frc-buildscripts wpilib" : "",
		"echo \"export WIND_BASE=/usr/powerpc-wrs-vxworks/wind_base\" >> ~/.bashrc" : "Adding WIND_BASE to bash config",
		"source ~/.bashrc" : ""
		}

def main():
	print("Now attempting to install the FRC C++ Toolchain for %s." % getOS())
	install()

	yn = '-1'

	if isWin32():
		while yn != 'y' or yn != 'n':
			yn = input("Delete installers (y/n)").lower

		if yn == 'y':
			delFile("FRCToolchainInstaller.exe")
			delFile("make-3.81.exe")

if __name__ == '__main__':
	main()