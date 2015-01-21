Wireshark Dissector for "LoL ENET"
==================

Tested with
-------
* Wireshark Version 1.12.0 (v1.12.0-0-g4fab41a from master-1.12)
* Lua 5.2
* Windows:
  * 64-bit Windows 7 Service Pack 1
  * Win 8.1 64-bit
* MinGW x64-4.8.1-release-posix-sjlj-rev5

Setup
-------
1. Download x64-4.8.1-release-posix-sjlj-rev5 from mingwbuilds (http://sourceforge.net/projects/mingwbuilds/files/host-windows/releases/4.8.1/64-bit/threads-posix/sjlj/)
2. Extract and either place in your path, or add installation directory to your path (if you have another install of MinGW, you can overwrite that if you wish - usually found in C:\MinGW)
3. Clone this repository and cd into this directory

Installation
-------
1. build the dll -> Compile.bat
2.
  1. use Install.bat
  2. or copy the files & folders:
	 * enet.lua
	 * GetLoLGameHash.vbs
	 * lolkeys/
	 * enet/
	 * enet/blowfish.dll

  into your "Wireshark personal plugin folder".
  See "Wireshark -> Help -> About Wireshark -> Folders -> Personal Plugins" for the exact path.
  If this folder doesnt exists, create it.
3. restart wireshark and check if the plugin is loaded:
  Check if "Wireshark -> Help -> About Wireshark -> Plugins" contains "enet.lua"

Troubleshooting
-------
* **Q**: Can't find command 'g++' (or a similar error)

  * **A**: Seems like you are missing a MinGW installation or your MinGW installation is not in the path. If you installed MinGW outside C:\Program Files\, you need to edit your environment variables and append your MinGW installation directory to the 'Path' variable. Alternatively, you can invoke g++ manually via an absolute path - see Compile.bat for the required commands.


* **Q**: I get this error: 'C:\Program Files\Wireshark\lua52.dll: file not recognized: File format not recognized'

  * **A**: You probably have a wrong version of MinGW installed, or more than one MinGW installation in the path. You need the version from mingwbuilds mentioned above

Usage
-------
Start a capture (Filter: "UDP"). As soon as a packet is captured and detected as "ENET" by the heuristic,
the lua script executes a VBScript to get the game key.
This key is then saved in a file in "your personal plugin folder"/lolkeys.
The filename contains the date&time of the first ENET packet and the server port.
If you open an already created .pcap file, the dissector will look for a matching key file.
If none is found, an empty file is created (you should have the corresponding game base64 key somewhere,
else the capture is useless), so you can fill it with the correct key.

Best case scenario: It captures the packets, marks the ones from LoL as "ENET",
saves they key in the corresponding key file, and shows the decrypted content in Wireshark.
