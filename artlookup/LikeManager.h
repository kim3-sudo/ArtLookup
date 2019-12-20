#include "ArtDBCommunicator.h"
#include "Like.h"
#include <vector>

using std::vector;
//using std::to_string;

#ifndef LIKE_MANAGER_H
#define LIKE_MANAGER_H

class LikeManager: public ArtDBCommunicator{
	public:
	    void addLike(string itemId, string userId);
	    // add like to like table in sql database

	    vector<Like> getLikes(string itemId);
	    // Returns likes associated with a specific artwork

	    LikeManager();
	    // Default Constructor
	private:
		//We do not plan on changing columns in our like table.
		const string likeColNames[4] = { "likeId", "userId", "itemId", "itemType" };
};

#endif //COMMENT_MANAGER_H
