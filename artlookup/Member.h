#include <string>

using namespace std;

#ifndef MEMBER_H
#define MEMBER_H

class Member{
  public:
    Member();
    //Member(string memberId, string username, string password, string email);
    Member(string username, string password, string email);
    string getUsername();
    string getPassword();
    string getEmail();


    // void likeArtwork(Artwork artwork);
    // //void likeComment(Comment comment);
    // void commentOnArtwork(string comment, Artwork artwork);
    // //void replyToComment(string reply, Comment comment);
  private:
    int m_memberId;
    string m_username;
    string m_password;
    string m_email;
};

#endif
