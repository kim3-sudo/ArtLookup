#include <string>
#include <iostream>

using namespace std;

#ifndef LIKE_H
#define LIKE_H

class Like{
  public:
    Like();
    Like(int likeId, int userId, int itemId);

    int getlikeId();
    int getuserId();
    int getitemId();

  private:
    int m_likeId;
    int m_userId;
    int m_itemId;
    //We will not have liking comments implemented so the
    //only thing we can like are artworks
    const string m_itemType = "artwork";
};

#endif
