//File Name: Like.cpp
//Author: Ryan, Michaela, and Sejin
//Email Address: schultz4@kenyon.edu, kim3@kenyon.edu, brydon1@kenyon.edu
//Assignment: Project 3
//Description: Data representation of a like
//Last Changed: December 20, 2019

#include "Like.h"

Like::Like(){
  m_likeId = -1;
  m_userId = -1;
  m_itemId = -1;
}

Like::Like(string likeId, string userId, string itemId){
  m_likeId = likeId;
  m_userId = userId;
  m_itemId = itemId;
}

string Like::getlikeId(){
  return m_likeId;
}

string Like::getuserId(){
  return m_userId;
}

string Like::getitemId(){
  return m_itemId;
}
