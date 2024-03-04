/*************************************************************/
/*                BrowserHistory Definition                  */
/*************************************************************/
/* TODO: Implement the member functions of BrowserHistory    */
/*     This class uses a linked-list of WebPage structs to   */
/*     represent the schedule of web pages                   */
/*************************************************************/

#include "musicPlaylist.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

/*
 * Purpose: Constructor for empty linked list
 * @param none
 * @return none
 */
MusicPlaylist::MusicPlaylist() {
    /*
    DO NOT MODIFY THIS
    This constructor is already complete. 
    */
    head = nullptr;
}

MusicPlaylist::MusicPlaylist(Song* song) {
    /*
    DO NOT MODIFY THIS
    This constructor is already complete. 
    */
    head = song;
}

Song* MusicPlaylist::getFirstSong(){
    //DO NOT MODIFY THIS
    return this->head;
}

/**
 * Display the song object
 * 
 * @param song The song object to display
 * @return No output returned. Should write to cout
 */
void Song::displaySong(){
    // TODO
    cout << "[ " << this->songName << ", " << this->artistNames << ", " << (this->liked ? "<3" : "</3") << " ]";
}

/**
 * Checks whether the music playlist is empty or not
 * 
 * @return True/False if the playlist is empty or not
 */
bool MusicPlaylist::isEmpty(){
    //TODO
    return this->head == nullptr;
}


/**
 * Walk through all songs in a playlist and display each one based on readme specs.
 * 
 * @return No output returned. Should write to cout using displaySong
 */
void MusicPlaylist::displayPlaylist(){
    // TODO
    cout<<"Displaying songs\n";
    cout << "==================\n";
    Song* currentSong = this->head;
    while(currentSong){
        currentSong->displaySong();
        cout << " -> ";
        currentSong = currentSong->next;
    }
    cout << "NULL\n";
    cout << "==================\n";
}


/**
 * Adds a song to the playlist after the passed song. 
 * @param previousSong The song object to which the newSong should be added to.
 * @param newSong The newSong to be added to the playlist. It should be added after the previousSong (if previousSong is nullptr, song gets added to the beginning)
 * @return No output returned. Should modify the MusicPlaylist 
 */
void MusicPlaylist::addSong(Song* previousSong, Song* newSong){
    // TODO
    if(previousSong){
        Song* tempSong = previousSong->next;
        previousSong->next = newSong;
        newSong->next = tempSong;
    }else{
        newSong->next = head;
        this->head = newSong;
    }
}

/**
 * Search through the music playlist until you find the song by name.
 * 
 * @param name The name of the song being looked for
 * @return Should return a song object. If no song is found, should return nullptr.
 */
Song* MusicPlaylist::searchSongByName(std::string name){
    // TODO
    Song* currentSong = this->head;
    while(currentSong && currentSong->songName != name){
        currentSong = currentSong->next;
    }
    return currentSong;
}

/**
 * Like the song. Change the boolean (*liked*) from false->true or true->false
 * 
 * @param name The name of the song to like
 * @return No output returned. Should modify the Song and print according to readme specifications.
 */
void MusicPlaylist::likeSong(std::string name){
    // TODO
    if(Song* current = this->searchSongByName(name)){
        current->liked = !current->liked;
        cout << "Song: " << current->songName << " liked!" << endl;
    }
    else {
        cout << "Song not found." << endl;
    }
}

/**
 * Traverse the playlist and display all songs that match the given artistName
 * 
 * @param name The name of the artist that we should search for
 * @return No output returned. Should write to cout each song that matches the artist.
 */  
void MusicPlaylist::displayAllSongsbyArtist(std::string name){
    // TODO
    Song* currentSong = this->head;
    bool found = false;
    while(currentSong){
        if(currentSong->artistNames == name) {
            currentSong->displaySong();
            cout << endl;
            found = true;
        }
        currentSong = currentSong->next;
    }
    if(!found) {
        cout << "No songs found." << endl;
    }
}