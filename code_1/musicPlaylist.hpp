/****************************************************************/
/*                     MusicPlaylist Definition                     */
/****************************************************************/
/* LEAVE THIS FILE AS IS! DO NOT MODIFY ANYTHING! =]            */
/****************************************************************/

//#pragma once
#ifndef MUSIC_PLAYLIST_HPP__
#define MUSIC_PLAYLIST_HPP__
#include <iostream>

using namespace std;

// Song: node struct that will be stored in the playlist linked-list
struct Song {
    std::string songName;             // Name of the song.
    //int totalArtists;                 // Total artists of the song.
    //std::string artistNames[5];       // Artists of the song.
    string artistNames;
    bool liked;                       // If the song has been liked.
    Song* next;                       // Pointer to the next song in the playlist.
    


    /**
     * Returns a deepcopy of this song
     * 
     * @return Returns a deepcopy of the song
     */
    Song* cloneSong(){
        Song* newSong = new Song();
        newSong->songName = this->songName;
        newSong->artistNames = this->artistNames;
        newSong->liked = this->liked;
        newSong->next = nullptr;
        return newSong;
    }
    void displaySong();
};

// class for storing and manipulating linked-list of songs
class MusicPlaylist {
    private:
        // pointer to head of linked-list of songs
        Song* head;
    public:
        // Constructors to initialise the playlist
        MusicPlaylist();
        MusicPlaylist(Song* song);

        /**
         * Gets the first song in the playlist
         * 
         * @return The first song in the playlist
         */
        Song* getFirstSong();

        bool isEmpty();
        void displayPlaylist(); 
        void addSong(Song* previousSong, Song* newSong);
        Song* searchSongByName(std::string name); 
        void likeSong(std::string name);       
        void displayAllSongsbyArtist (string name); 
};
#endif
