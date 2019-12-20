#include <string>
#include <iostream>

using namespace std;

#ifndef LIKE_H
#define LIKE_H

class Like{
  public:
    Like();
    Like(string likeId, string userId, string itemId);

    string getlikeId();
    string getuserId();
    string getitemId();

  private:
    string m_likeId;
    string m_userId;
    string m_itemId;
    //We will not have liking comments implemented so the
    //only thing we can like are artworks
    const string m_itemType = "artwork";
};

#endif
