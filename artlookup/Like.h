#include <string>

using namespace std;

#ifndef LIKE_H
#define LIKE_H

class Like{
  public:
    Like();

    // Member(string username, string password, string email);
    // Member(const Member& otherMember);
    // // Copy Constructor

    // string getUsername();
    // string getPassword();
    // string getEmail();


    // void likeArtwork(Artwork artwork);
    // //void likeComment(Comment comment);
    // void commentOnArtwork(string comment, Artwork artwork);
    // //void replyToComment(string reply, Comment comment);
  private:
    int m_likeId;
    //string m_username;
    //string m_password;
    //string m_email;
};

#endif
