//File Name: Like.cpp
//Author: Ryan, Michaela, and Sejin
//Email Address: schultz4@kenyon.edu, kim3@kenyon.edu, brydon1@kenyon.edu
//Assignment: Project 3
//Description: Data representation of a like
//Last Changed: December 20, 2019

#include "Like.h"

Artwork::Artwork(){
  m_likeId = -1;
  m_userId = -1;
  m_itemId = -1;
}

Artwork::Like(int likeId, int userId, int itemId){
  m_likeId = likeId;
  m_userId = userId;
  m_itemId = itemId;
}

int Like::getlikeId(){
  return m_likeId;
}

int Like::getuserId(){
  return m_userId;
}

int Like::getitemId(){
  return m_itemId;
}
