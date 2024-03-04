
# CSCI 2270 – Data Structures - Assignment 3: Linked Lists I

## Objectives
1. Create, traverse and add nodes to a linked list class
2. Search for a specific node
3. Edit a specific node 
4. Get practice implementing classes

## Instructions
Write code to complete specs given below. To receive credit for your code, you will need to pass the necessary test cases. Use the following steps to test your code as you work on the assignment:

1. Open up your Linux terminal, navigate to the build directory of this assignment (e.g. `cd build`).
2. Run the `cmake ..` command.
3. Run the `make` command.
4. If there are no compilation errors, two executables will be generated within the build directory: `run_app` and `run_tests`.
5. If you would like to run your program including your app implementation in the `main` function, execute `run_app` from the terminal by typing `./run_app`. 
6. To run the grading tests, execute `run_tests` from the terminal by typing `./run_tests`.

## Overview
You will be implementing a class to simulate a music playlist as a linked list of songs. Your repository contains three files containing a code skeleton to get you started. You will have to complete **_both_** the class implementation in `musicPlaylist.cpp` and the driver file `main.cpp`.
> Do not modify the header file, or your code won’t work!

The linked list will be implemented using the following struct (already included in `musicPlaylist.h`):
```
// Song: Node that will be stored in the Playlist linked-list
struct Song
{
  std::string songName;
  std::string artistNames;
  bool liked;
  Song* next;
};
```

> See appendix for code to help you with printing

## Class Specifications
The `MusicPlaylist` class definition is provided in the file `musicPlaylist.hpp`. Fill in the file `musicPlaylist.cpp` according to the following specifications. 
> Make sure you complete the functions in the order they are given here.

`Song* head;`
➔ Points to the first node in the linked list.

`musicPlaylist()`
➔ Class constructor; set the head pointer to nullptr

All function below are `#TODO`

`bool isEmpty()`
➔ Return true if head is nullptr, false otherwise.

`void displaySong(Song* givenSong)`
➔ Print name, artists, and whether or not the song is liked. Follow the below example.
```
[ Hotline Bling, Drake, </3 ]
```


`void displayPlaylist()`
➔ Print names of each song in the linked list and whether or not it is liked. Below is an example of the correct output using the default setup. 
>Note: After each song you need to print `cout << " -> ";`
>Note: At the end of the list `cout << "NULL\n";` 
```
Displaying songs
==================
[ Hotline Bling, Drake, </3 ] -> [ God's Plan, Drake, <3 ] -> NULL
==================
```

`void addSong ( Song* previousSong, Song* newSong )`
➔ Insert a new song with the properties of `newSong` struct in the linked list as the song played by the playlist after `previousSong`. Here we allow the manipulation of the playlist as per request, i.e., insert a new song between two songs. Since, this is a playlist, the same song can be added multiple times at different locations. Note:
1. If `previousPage` is nullptr, add the new page to the beginning of the list.
2. Print the songName of the page you added according to the following format:

`Song* searchSongByName( std::string name )`
➔ Search the `MusicPlaylist` for the specified song by the songName and return a pointer to that node. Return `nullptr` if it is not found.

`void likeSong( std::string name )` ➔ Search for the song with name and then flip the liked boolean (true becomes false, false becomes true). If the song is found, print the below message: 
`cout << "Song: " << current->songName << " liked!" << endl;`

If song is not found, `cout << "Song not found." << endl;`

`void displayAllSongsByArtist std::string name )`
➔ Find all songs with artistName = name. Call displaySong on each one, putting each song on a new line.
If no songs are found by the artist `cout << "No songs found." << endl;`

## Main driver file (`app_1/main_1.cpp`)
The code for main is already complete. You do not need to modify it. However, it is useful for degugging using run_app  
`./run_app ../tests/input_3.txt`
This will display the entire app flow on the terminal.

Your program will start by displaying a menu by calling the `displayMenu()` function included in `main_1.cpp`. The user will select an option from the menu to decide what the program will do, after which, the menu will be displayed again. The specifics of each menu option are described below.

### Option 1: Is Empty
Display whether or not the playlist is empty.

### Option 2: Display playlist
Call the `displayPlaylist()` function. Output should be in the format below:

Ouput for if called on empty linked list (i.e. have not called option 3 yet):
```
Displaying songs
==================
NULL
==================
```
Output for if called on after option 3 has been selected:
```
Displaying songs
==================
[ Hotline Bling, Drake, </3 ] -> [ God's Plan, Drake, <3 ] -> NULL
==================
```
### Option 3: Add Song
Prompts the user for 2 inputs. The first is the new song given in the following format: {song name};{artists};{liked}. We use semi-colons to allow the user to input multiple artists: "artist1, artist2". Liked should be "True" or "False". You should not put spaces between the semi-colons and their neighboring values.

The next input is the name of the song the user wishes to add the new song after. If the song is not found (e.g. user inputs "null"), the song is placed at the head of the playlist.

Some examples are given below:
```
2
Displaying songs
==================
[ Hotline Bling, Drake, </3 ] -> [ God's Plan, Drake, <3 ] -> NULL
==================
3
family ties;Kendrick Lamar, Baby Keem;True
Hotline Bling
2
Displaying songs
==================
[ Hotline Bling, Drake, </3 ] -> [family ties, Kendrick Lamar, Baby Keem, <3] -> [ God's Plan, Drake, <3 ] -> NULL
==================
```
```
2
Displaying songs
==================
NULL
==================
3
family ties;Kendrick Lamar, Baby Keem;True
null
2
Displaying songs
==================
[family ties, Kendrick Lamar, Baby Keem, <3] -> NULL
==================
```


### Option 4: Search By Name
Prompts the user for one input, then searches for the song that matches that playlist. Then if the song is found we display it, otherwise we print out "Song not found."

```
2
Displaying songs
==================
[ Hotline Bling, Drake, </3 ] -> [family ties, Kendrick Lamar, Baby Keem, <3] -> [ God's Plan, Drake, <3 ] -> NULL
==================
4
family ties
[family ties, Kendrick Lamar, Baby Keem, <3] -> 
```
```
2
Displaying songs
==================
[ Hotline Bling, Drake, </3 ] -> [family ties, Kendrick Lamar, Baby Keem, <3] -> [ God's Plan, Drake, <3 ] -> NULL
==================
4
fake song
Song not found.
```

### Option 5: Like Song
Prompts the user for a song name, then flips the liked value for that song. Then display that song (or "Song not found.").

```
2
Displaying songs
==================
[ Hotline Bling, Drake, </3 ] -> [family ties, Kendrick Lamar, Baby Keem, <3] -> [ God's Plan, Drake, <3 ] -> NULL
==================
5
family ties
[family ties, Kendrick Lamar, Baby Keem, </3] -> 
```
```
2
Displaying songs
==================
[ Hotline Bling, Drake, </3 ] -> [family ties, Kendrick Lamar, Baby Keem, <3] -> [ God's Plan, Drake, <3 ] -> NULL
==================
5
fake song
Song not found.
```

### Option 6: Display Songs by Artist
Prompts the user for an artist name, then displays all songs that have the same artist.

```
2
Displaying songs
==================
[ Hotline Bling, Drake, </3 ] -> [family ties, Kendrick Lamar, Baby Keem, <3] -> [ God's Plan, Drake, <3 ] -> NULL
==================
6
Drake
[ Hotline Bling, Drake, </3 ] -> [ God's Plan, Drake, <3 ] -> NULL
```
```
2
Displaying songs
==================
[ Hotline Bling, Drake, </3 ] -> [family ties, Kendrick Lamar, Baby Keem, <3] -> [ God's Plan, Drake, <3 ] -> NULL
==================
6
Taylor Swift
NULL
```



### Option 7: Quit
Print the following message:
`cout << "Quitting!\n";`
